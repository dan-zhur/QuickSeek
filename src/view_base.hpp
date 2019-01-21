﻿#pragma once

#include "controller_base.hpp"

#include <string>


class ModelBase;
class ControllerBase;

class ViewBase
{
public:
	// special members
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
	void SetController(ControllerBase *controller) { _controller = controller; }
	//------------------------------

protected:
	// member variables
	ControllerBase *_controller{ nullptr };
	//------------------------------
};
