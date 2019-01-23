#pragma once

#include "prefix_tree.hpp"

#include <atomic>
#include <functional>
#include <string>


class ControllerBase;
class ViewBase;

class FileManager final {
public:
	// special members
	FileManager() = default;
	FileManager(const FileManager&) = delete;
	FileManager(FileManager&&) = default;
	FileManager& operator=(const FileManager&) = delete;
	FileManager& operator=(FileManager&&) = default;
	~FileManager() = default;

	// pure virtual functions
	void ScanFileSystem();
	void SearchPrefix(const std::string &prefix);
	void StopSearch();
	//------------------------------

	// methods
	void SetView(ViewBase *view);
	//------------------------------

protected:
	// member variables
	ViewBase *_view{ nullptr };
	//------------------------------

private:
	// member variables
	PrefixTree _prefix_tree;
	std::atomic<bool> _do_we_stop;
	std::string _current_file_name;
	//------------------------------
};
