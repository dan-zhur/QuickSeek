#include "view.hpp"


void View::ShowMainWindow() {
	_main_window.Show();
}


void View::AddPathToList(const std::string &path) {
	_main_window.AddPathToList(QString::fromUtf8(path.c_str()));
}


void View::ClearList() {
	_main_window.ClearList();
}


void View::ShowScanWindow(const std::string &disk_letter) {
	_scan_window.Show();
	SetScanningDiskLetter(disk_letter);
}


void View::SetScanningDiskLetter(const std::string &disk_letter) {
	_scan_window.SetDiskLetter(disk_letter);
}


void View::CloseScanWindow() {
	_scan_window.Close();
}


void View::NotifySearchButtonClicked(const std::string &str) {
	_controller->SearchButtonPressed(str);
}
