#include "ScanningWindow.h"



ScanningWindow::ScanningWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QObject::connect(this, SIGNAL(SetDiskLetterSignal(QChar)), SLOT(SetDiskLetterSlot(QChar)), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(ShowSignal()), SLOT(ShowSlot()), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(CloseSignal()), SLOT(CloseSlot()), Qt::QueuedConnection);
}



ScanningWindow::~ScanningWindow()
{
}




void ScanningWindow::Show()
{
	emit ShowSignal();
}



void ScanningWindow::ShowSlot()
{
	show();
}



void ScanningWindow::Close()
{
	emit CloseSignal();
}



void ScanningWindow::CloseSlot()
{
	close();
}



void ScanningWindow::SetDiskLetter(QChar diskLetter)
{
	emit SetDiskLetterSignal(diskLetter);
}



void ScanningWindow::SetDiskLetterSlot(QChar diskLetter)
{
	ui.scanningDiskLabel->setText(diskLetter);
}