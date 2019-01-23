#pragma once

#include <thread>


class ViewBase;
class FileManager;

class Controller final {
public:
	// special members
	Controller() = default;
	Controller(const Controller&) = delete;
	Controller(Controller&&) = default;
	Controller& operator=(const Controller&) = delete;
	Controller& operator=(Controller&&) = default;
	virtual ~Controller();
	//------------------------------
	
	// methods
	void SetFileManager(FileManager * const file_manager) noexcept;
	void SetView(ViewBase * const view) noexcept;

	void Run();
	void SearchButtonPressed(const std::string &what_to_search);
	void StopSearchButtonPressed();
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
