#include "view.hpp"


void View::ShowMainWindow() {
	mainWindow_.Show();
}


void View::AddPathToList(const std::string& path) {
	mainWindow_.AddPathToList(QString::fromUtf8(path.c_str()));
}


void View::ClearList() {
	mainWindow_.ClearList();
}


void View::ShowScanningWindow(const std::string& diskLetter) {
	scanningWindow_.Show();
	SetScanningDiskLetter(diskLetter);
}


void View::SetScanningDiskLetter(const std::string& diskLetter) {
	scanningWindow_.SetDiskLetter(diskLetter);
}


void View::CloseScanningWindow() {
	scanningWindow_.Close();
}


void View::NotifySearchButtonClicked(const std::string& str) {
	controller_->SearchButtonPressed(str);
}
