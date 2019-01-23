#pragma once

#include <thread>


class ViewBase;
class FileManager;

class Controller {
public:
	// special members
	virtual ~Controller();
	//------------------------------

	// overriding methods
	void Run();
	void SearchButtonPressed(const std::string &what_to_search);
	void StopSearchButtonPressed();
	//------------------------------

	// methods
	void SetFileManager(FileManager * const file_manager) { _file_manager = file_manager; }
	void SetView(ViewBase * const view) { _view = view; }
	//------------------------------
private:
	// methods
	void _RunHelper();
	//------------------------------

	// member variables
	FileManager *_file_manager;
	ViewBase *_view;

	std::thread _running_thread;
	//------------------------------
};
