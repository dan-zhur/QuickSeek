#include "controller.hpp"


Controller::~Controller() {
	_model->StopSearch();
	if(_running_thread.joinable()) {
		_running_thread.join();
	}
}


void Controller::Run() {
	_running_thread = std::thread(&Controller::_RunHelper, this);
}


void Controller::_RunHelper() {
	_model->ScanFileSystem();
	_view->CloseScanningWindow();
	_view->ShowMainWindow();
}


void Controller::SearchButtonPressed(const std::string& what_to_search) {
	_model->StopSearch();
	_view->ClearList();
	_model->SearchPrefix(what_to_search, std::bind(&ViewBase::AddPathToList, _view, std::placeholders::_1));
}


void Controller::StopSearchButtonPressed() {
	_model->StopSearch();
}
