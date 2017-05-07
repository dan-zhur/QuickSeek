#include "Controller.h"



Controller::~Controller()
{
	model_->StopSearch();
	if(runningThread_.joinable())
	{
		runningThread_.join();
	}
}



void Controller::Run()
{
	runningThread_ = std::thread(&Controller::RunHelper_, this);
}



void Controller::RunHelper_()
{
	model_->ScanFileSystem();
	view_->CloseScanningWindow();
	view_->ShowMainWindow();
}



void Controller::SearchButtonPressed(const String& whatToSearch)
{
	model_->StopSearch();
	view_->ClearList();
	model_->SearchPrefix(whatToSearch, std::bind(&ViewBase::AddPathToList, view_, std::placeholders::_1));
}



void Controller::StopSearchButtonPressed()
{
	model_->StopSearch();
}