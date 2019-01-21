﻿#include "model.hpp"

#include <filesystem>


void Model::SearchPrefix(const std::string &prefix, CallbackFunction callback) {
	_prefix_tree.SearchByPrefix(prefix, callback);
}


namespace {
	void ScanFileSystemHelper_(const std::filesystem::path &path, PrefixTree &prefix_tree) {
		using namespace std::filesystem;
		directory_iterator end_itr;
		for(directory_iterator itr{ path }; itr != end_itr; ++itr) {
			if(is_directory(itr->status()))	{
				ScanFileSystemHelper_(itr->path(), prefix_tree);
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
	for(char c = u8'A'; c <= u8'Z'; c++) { // TODO: rewrite using WinAPI, not letter disk scan
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


void Model::StopSearch() {

}
