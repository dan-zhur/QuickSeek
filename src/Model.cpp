#include "Model.h"
#include <boost\filesystem.hpp>
#include "Config.h"



void Model::SearchPrefix(const String& prefix, CallbackFunction callback)
{
	prefixTree_.SearchByPrefix(prefix, callback);
}



void Model::StopSearch()
{
	prefixTree_.StopSearch();
}



namespace
{
	void ScanFileSystemHelper_(const boost::filesystem::path& path, PrefixTree& prefixTree, int depth = 0)
	{
		using namespace boost::filesystem;
		if(depth == 3) return;
		if(!exists(path))
		{
			return;
		}
		try
		{
			directory_iterator end_itr;
			for(directory_iterator itr{ path }; itr != end_itr; ++itr)
			{
				if(is_directory(itr->status()))
				{
					ScanFileSystemHelper_(itr->path(), prefixTree, depth + 1);
				}

				/*
					.native() returns
						std::string if runs on Posix system,
						std::wstring if runs on Windows
				*/
				prefixTree.AddString(itr->path().filename().native());
			}
		}
		catch(const filesystem_error& e)
		{
			
		}
	}
}



void Model::ScanFileSystem()
{
#if defined(__CONFIG_WINDOWS__) //если под Windows, нужно просканировать каждый диск
	String path = L"A:\\";
	view_->ShowScanningWindow(L' ');
	for(wchar_t c = L'A'; c <= L'Z'; c++)
	{
		path[0] = c;
		if(boost::filesystem::exists(path))
		{
			view_->SetScanningDiskLetter(c);
			ScanFileSystemHelper_(path, prefixTree_);
		}
	}
#else //если на Posix, то запускаем из корня
	ScanFileSystemHelper_("/", prefixTree);
#endif
}