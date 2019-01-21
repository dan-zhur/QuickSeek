#pragma once

#include "view_base.hpp"
#include "qt_main_window.hpp"
#include "qt_scan_window.hpp"


class View : public ViewBase {
public:
	//special members
	~View() override = default;
	//------------------------------

	//overriding functions
	void ShowMainWindow() override;
	void AddPathToList(const std::string& path) override;
	void ClearList() override;
	void ShowScanningWindow(const std::string& diskLetter) override;
	void SetScanningDiskLetter(const std::string& diskLetter) override;
	void CloseScanningWindow() override;
	void NotifySearchButtonClicked(const std::string& whatToSearch) override;
	//------------------------------
private:
	//member variables
	MainWindow _main_window{ this };
	ScanWindow _scan_window;
	//------------------------------
};
