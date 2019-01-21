#include "model.hpp"

#include <filesystem>


void Model::SearchPrefix(const std::string &prefix, CallbackFunction callback) {
	_prefix_tree.SearchByPrefix(prefix, callback);
}


void Model::StopSearch() {
	_prefix_tree.StopSearch();
}


namespace {
	void ScanFileSystemHelper_(const std::filesystem::path &path, PrefixTree &prefix_tree, int depth = 0) {
		using namespace std::filesystem;
#ifdef _DEBUG
		// in debug, we will skip long indexing by limiting it up to 3 levels
		if(depth == 3) return;
#endif

		if(!exists(path))	return;

		directory_iterator end_itr;
		for(directory_iterator itr{ path }; itr != end_itr; ++itr) {
			if(is_directory(itr->status()))	{
				ScanFileSystemHelper_(itr->path(), prefix_tree, depth + 1);
			}

			prefix_tree.AddString(itr->path().filename().u8string());
		}
	}
}


void Model::ScanFileSystem() {
#if defined(__CONFIG_WINDOWS__) // if ran under Windows, we will check every disk
	using namespace std;
	std::string p{ u8"A:\\" };
	_view->ShowScanWindow(u8" ");
	for(char c = 'A'; c <= 'Z'; c++) { //TODO: rewrite using WinAPI, not letter disk scan
		p[0] = c;
		if(std::filesystem::exists(p)) {
			_view->SetScanningDiskLetter({ c });
			ScanFileSystemHelper_(p, _prefix_tree);
		}
	}
#elif defined(__CONFIG__POSIX__) // if Posix, run from root
	ScanFileSystemHelper_(u8"/", prefixTree_);
#endif
}
