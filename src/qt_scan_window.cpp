﻿#include "qt_scan_window.hpp"


ScanWindow::ScanWindow(QWidget * const parent)
	: QWidget(parent) {
	ui.setupUi(this);

	QObject::connect(this, SIGNAL(SetDiskLetterSignal(const QString&)), SLOT(SetDiskLetterSlot(const QString&)), Qt::QueuedConnection);
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


void ScanWindow::SetDiskLetter(const QString &disk_letter) {
	emit SetDiskLetterSignal(disk_letter);
}


void ScanWindow::SetDiskLetterSlot(const QString &disk_letter) {
	ui.scannedDiskLabel->setText(disk_letter);
}
