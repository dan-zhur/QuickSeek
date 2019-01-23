#include "file_manager.hpp"
#include "view_base.hpp"

#include <filesystem>
#include <atomic>
#include <exception>
#include <utility>


namespace {
	// types

	/*
		AssignmentProxy allows to perform some action on object
		right after assignment to it. 
		Constructor accepts Function f, which will be called
		as f(value), where value is assigned value.
	*/
	template<typename Function>
	struct StringProxy {
		StringProxy(Function function)
			: handler{ function } {
		}

		template<typename T>
		StringProxy& operator=(T &&new_value) {
			handler(std::forward<T>(new_value));
			return *this;
		}

		Function handler;
	};


	/*
		OutputIterator - implements common output iterator logic,
		and 2 more features:
			1) becomes nullptr, when std::atomic<bool> becomes true
			2) calls Function, given in constructor, when being dereferenced
				and value assigned to result.
	*/
	template<typename Function>
	struct OutputIterator {
		OutputIterator(std::atomic<bool> &do_we_stop, Function string_handler)
			: string_proxy{ string_handler },
				do_we_stop { do_we_stop	} {
		}

		StringProxy<Function>& operator*() {
			return string_proxy;
		}

		OutputIterator& operator++(int) {
			return *this;
		}

		operator bool() {
			return do_we_stop;
		}

		StringProxy<Function> string_proxy;
		std::atomic<bool> &do_we_stop;
	};
	//------------------------------
}


void FileManager::SetView(ViewBase * const view) {
	_view = view;
}


void FileManager::SearchPrefix(const std::string &prefix) {
	_do_we_stop = false;
	OutputIterator out_iter(_do_we_stop, 
		[this](const std::string& s) {
			_view->AddPathToList(s);
	});
	_prefix_tree.SearchByPrefix(prefix, out_iter);
}


namespace {
	void ScanFileSystemHelper_(const std::filesystem::path &path, PrefixTree &prefix_tree) {
		using namespace std::filesystem;

		try {
			for(directory_iterator itr{ path }; itr != directory_iterator{}; ++itr) {
				if(is_directory(itr->status())) {
					ScanFileSystemHelper_(itr->path(), prefix_tree);
				}

				prefix_tree.AddString(itr->path().filename().u8string());
			}
		}
		catch(const std::exception&) {
			// if something happened with filesystem (no such file, etc.)
		}
	}
}


void FileManager::ScanFileSystem() {
#if defined(__CONFIG_WINDOWS__) // if is being run under Windows, will check every disk
	// TODO: rewrite using WinAPI, not letter disk scan.
	// WARNING: temporary bad code
	using namespace std;
	std::string p{ u8"A:\\temp" };
	_view->ShowScanWindow(u8" ");
	for(char c = u8'D'; c <= u8'D'; c++) { 
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


void FileManager::StopSearch() {
	_do_we_stop = true;
}
