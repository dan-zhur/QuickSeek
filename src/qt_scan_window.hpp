#pragma once

#include "../forms/ui_scan_window.h"

#include <QWidget>

class ScanWindow : public QWidget {
	Q_OBJECT

public:
	ScanWindow(QWidget *parent = Q_NULLPTR);
	~ScanWindow();

	void SetDiskLetter(std::string diskLetter);
	void Show();
	void Close();

signals:
	void SetDiskLetterSignal(std::string diskLetter);
	void ShowSignal();
	void CloseSignal();

private slots:
	void SetDiskLetterSlot(std::string diskLetter);
	void ShowSlot();
	void CloseSlot();

private:
	Ui::scan_windowClass ui;
};
