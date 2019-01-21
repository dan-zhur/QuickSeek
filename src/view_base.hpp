#pragma once

#include "controller_base.hpp"

#include <string>

class ModelBase;
class ControllerBase;


class ViewBase
{
public:
	//construction / deletion
	virtual ~ViewBase() = default;
	//------------

	//pure virtual functions
	virtual void ShowMainWindow() = 0;
	virtual void AddPathToList(const std::string& path) = 0;
	virtual void ClearList() = 0;
	virtual void ShowScanningWindow(const std::string& diskLetter) = 0;
	virtual void SetScanningDiskLetter(const std::string& diskLetter) = 0;
	virtual void CloseScanningWindow() = 0;
	virtual void NotifySearchButtonClicked(const std::string& whatToSearch) = 0;
	//-----------

	//methods
	inline void SetController(ControllerBase* controller) { controller_ = controller; }
	//-----------

protected:
	//member variables
	ControllerBase* controller_{ nullptr };
	//-----------
};