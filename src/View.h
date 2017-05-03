#pragma once

#include "ViewBase.h"
#include "QuickSeekUI.h"
#include "ScanningWindow.h"


class View : public ViewBase
{
public:
	//types
	using Char = config::Char;
	using String = config::String;
	//------------------------------

	//construction / deletion
	virtual ~View() override = default;
	//------------------------------

	//overriding functions
	virtual void ShowMainWindow() override;
	virtual void AddPathToList(const String& path) override;
	virtual void ClearList() override;
	virtual void ShowScanningWindow(const Char& diskLetter) override;
	virtual void SetScanningDiskLetter(const Char& diskLetter) override;
	virtual void CloseScanningWindow() override;
	virtual void NotifySearchButtonClicked(const String& whatToSearch) override;
	//------------------------------
private:
	//member variables
	QuickSeekUI mainWindow_{ this };
	ScanningWindow scanningWindow_;
	//------------------------------
};