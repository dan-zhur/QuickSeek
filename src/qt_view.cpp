#include "qt_view.hpp"


void QtView::ShowMainWindow() {
	_main_window.Show();
}


void QtView::AddPathToList(const std::string &path) {
	_main_window.AddPathToList(QString::fromUtf8(path.c_str()));
}


void QtView::ClearList() {
	_main_window.ClearList();
}


void QtView::ShowScanWindow(const std::string &disk_letter) {
	_scan_window.Show();
	SetScanningDiskLetter(disk_letter);
}


void QtView::SetScanningDiskLetter(const std::string &disk_letter) {
	_scan_window.SetDiskLetter(disk_letter);
}


void QtView::CloseScanWindow() {
	_scan_window.Close();
}


void QtView::NotifySearchButtonClicked(const std::string &str) {
	_controller->SearchButtonPressed(str);
}
