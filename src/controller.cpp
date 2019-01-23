#include "controller.hpp"
#include "file_manager.hpp"
#include "view_base.hpp"


Controller::~Controller() {
	_file_manager->StopSearch();
	if(_running_thread.joinable()) {
		_running_thread.join();
	}
}


void Controller::Run() {
	_running_thread = std::thread(&Controller::_RunHelper, this);
}


void Controller::_RunHelper() {
	_file_manager->ScanFileSystem();
	_view->CloseScanWindow();
	_view->ShowMainWindow();
}


void Controller::SearchButtonPressed(const std::string &what_to_search) {
	_file_manager->StopSearch();
	_view->ClearList();
	_file_manager->SearchPrefix(what_to_search);
}


void Controller::StopSearchButtonPressed() {
	_file_manager->StopSearch();
}
