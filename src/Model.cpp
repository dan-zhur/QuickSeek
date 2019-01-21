#include "model.hpp"

#include <filesystem>


void Model::SearchPrefix(const std::string& prefix, CallbackFunction callback)
{
	prefixTree_.SearchByPrefix(prefix, callback);
}


void Model::StopSearch()
{
	prefixTree_.StopSearch();
}


namespace
{
	void ScanFileSystemHelper_(const std::filesystem::path& path, PrefixTree& prefixTree, int depth = 0)
	{
		using namespace std::filesystem;
#ifdef _DEBUG
		if(depth == 3) return;
#endif
		if(!exists(path))
		{
			return;
		}

		directory_iterator end_itr;
		for(directory_iterator itr{ path }; itr != end_itr; ++itr)
		{
			if(is_directory(itr->status()))
			{
				ScanFileSystemHelper_(itr->path(), prefixTree, depth + 1);
			}

			prefixTree.AddString(itr->path().filename().u8string());
		}
	}
}



void Model::ScanFileSystem()
{
#if defined(__CONFIG_WINDOWS__) //если под Windows, нужно просканировать каждый диск
	using namespace std;
	std::string p{ u8"A:\\" };
	view_->ShowScanningWindow(u8" ");
	for(char c = 'A'; c <= 'Z'; c++) //TODO: rewrite
	{
		p[0] = c;
		if(std::filesystem::exists(p))
		{
			view_->SetScanningDiskLetter({ c });
			ScanFileSystemHelper_(p, prefixTree_);
		}
	}
#else //если на Posix, то запускаем из корня
	ScanFileSystemHelper_(u8"/", prefixTree_);
#endif
}