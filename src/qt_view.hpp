#pragma once

#include "view_base.hpp"
#include "qt_main_window.hpp"
#include "qt_scan_window.hpp"


class QtView : public ViewBase {
public:
	// special members
	QtView() = default;
	QtView(const QtView&) = delete;
	QtView(QtView&&) = default;
	QtView& operator=(const QtView&) = delete;
	QtView& operator=(QtView&&) = default;
	~QtView() override = default;
	//------------------------------

	// overriding functions
	void ShowMainWindow() override;
	void AddPathToList(const std::string &path) override;
	void ClearList() override;
	void ShowScanWindow(const std::string &disk_letter) override;
	void SetScanningDiskLetter(const std::string &disk_letter) override;
	void CloseScanWindow() override;
	void NotifySearchButtonClicked(const std::string &what_to_search) override;
	//------------------------------
private:
	// member variables
	MainWindow _main_window{ this };
	ScanWindow _scan_window;
	//------------------------------
};
