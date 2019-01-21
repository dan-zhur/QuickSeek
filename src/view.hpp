#pragma once

#include "view_base.hpp"
#include "qt_main_window.hpp"
#include "qt_scan_window.hpp"


class View : public ViewBase
{
public:
	//construction / deletion
	virtual ~View() override = default;
	//------------------------------

	//overriding functions
	virtual void ShowMainWindow() override;
	virtual void AddPathToList(const std::string& path) override;
	virtual void ClearList() override;
	virtual void ShowScanningWindow(const std::string& diskLetter) override;
	virtual void SetScanningDiskLetter(const std::string& diskLetter) override;
	virtual void CloseScanningWindow() override;
	virtual void NotifySearchButtonClicked(const std::string& whatToSearch) override;
	//------------------------------
private:
	//member variables
	QuickSeekUI mainWindow_{ this };
	ScanningWindow scanningWindow_;
	//------------------------------
};