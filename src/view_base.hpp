#pragma once

#include "controller.hpp"

#include <string>


class ViewBase
{
public:
	// special members
	ViewBase() = default;
	ViewBase(const ViewBase&) = default;
	ViewBase(ViewBase&&) = default;
	ViewBase& operator=(const ViewBase&) = default;
	ViewBase& operator=(ViewBase&&) = default;
	virtual ~ViewBase() = default;
	//------------------------------

	// pure virtual functions
	virtual void ShowMainWindow() = 0;
	virtual void AddPathToList(const std::string &path) = 0;
	virtual void ClearList() = 0;
	virtual void ShowScanWindow(const std::string &disk_letter) = 0;
	virtual void SetScanningDiskLetter(const std::string &disk_letter) = 0;
	virtual void CloseScanWindow() = 0;
	virtual void NotifySearchButtonClicked(const std::string &what_to_search) = 0;
	//------------------------------

	//methods
	void SetController(Controller * const controller) { _controller = controller; }
	//------------------------------

protected:
	// member variables
	Controller *_controller{ nullptr };
	//------------------------------
};
