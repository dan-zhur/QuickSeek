#include "View.h"

namespace
{
#if defined(__CONFIG_WINDOWS__)
	inline QString ConfigStringToQString(const config::String& str) { return QString::fromStdWString(str); }
	inline config::String QStringToConfigString(const QString& str) { return str.toStdWString(); }
#else
	inline QString ConfigStringToQString(const String& str) { return QString::fromStdString(str); }
	inline String QStringToConfigString(const QString& str) { return str.toStdString(); }
#endif
}



void View::ShowMainWindow()
{
	mainWindow_.Show();
}



void View::AddPathToList(const String& path)
{
	mainWindow_.AddPathToList(ConfigStringToQString(path));
}



void View::ClearList()
{
	mainWindow_.ClearList();
}



void View::ShowScanningWindow(const Char& diskLetter)
{
	scanningWindow_.Show();
	SetScanningDiskLetter(diskLetter);
}



void View::SetScanningDiskLetter(const Char& diskLetter)
{
	scanningWindow_.SetDiskLetter(diskLetter);
}



void View::CloseScanningWindow()
{
	scanningWindow_.Close();
}



void View::NotifySearchButtonClicked(const String& str)
{
	controller_->SearchButtonPressed(str);
}