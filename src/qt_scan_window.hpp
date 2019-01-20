#pragma once

#include "../forms/ui_scan_window.h"

#include <QWidget>

class ScanningWindow : public QWidget
{
	Q_OBJECT

public:
	ScanningWindow(QWidget *parent = Q_NULLPTR);
	~ScanningWindow();

	void SetDiskLetter(QChar diskLetter);
	void Show();
	void Close();

signals:
	void SetDiskLetterSignal(QChar diskLetter);
	void ShowSignal();
	void CloseSignal();

private slots:
	void SetDiskLetterSlot(QChar diskLetter);
	void ShowSlot();
	void CloseSlot();

private:
	Ui::scan_windowClass ui;
};
