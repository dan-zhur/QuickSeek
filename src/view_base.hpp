#pragma once

#include "Config.h"
#include "ControllerBase.h"


class ModelBase;
class ControllerBase;


class ViewBase
{
public:
	//types
	using Char = config::Char;
	using String = config::String;
	//------------

	//construction / deletion
	virtual ~ViewBase() = default;
	//------------

	//pure virtual functions
	virtual void ShowMainWindow() = 0;
	virtual void AddPathToList(const String& path) = 0;
	virtual void ClearList() = 0;
	virtual void ShowScanningWindow(const Char& diskLetter) = 0;
	virtual void SetScanningDiskLetter(const Char& diskLetter) = 0;
	virtual void CloseScanningWindow() = 0;
	virtual void NotifySearchButtonClicked(const String& whatToSearch) = 0;
	//-----------

	//methods
	inline void SetController(ControllerBase* controller) { controller_ = controller; }
	//-----------

protected:
	//member variables
	ControllerBase* controller_{ nullptr };
	//-----------
};