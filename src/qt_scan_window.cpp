#include "qt_scan_window.hpp"


ScanWindow::ScanWindow(QWidget *parent)
	: QWidget(parent) {
	ui.setupUi(this);

	QObject::connect(this, SIGNAL(SetDiskLetterSignal(std::string)), SLOT(SetDiskLetterSlot(std::string)), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(ShowSignal()), SLOT(ShowSlot()), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(CloseSignal()), SLOT(CloseSlot()), Qt::QueuedConnection);
}


void ScanWindow::Show() {
	emit ShowSignal();
}


void ScanWindow::ShowSlot() {
	show();
}


void ScanWindow::Close() {
	emit CloseSignal();
}


void ScanWindow::CloseSlot() {
	close();
}


void ScanWindow::SetDiskLetter(std::string disk_letter) {
	emit SetDiskLetterSignal(disk_letter);
}

void ScanWindow::SetDiskLetterSlot(std::string disk_letter) {
	ui.scannedDiskLabel->setText(QString::fromUtf8(disk_letter.c_str()));
}
