#pragma once

#include "../forms/ui_scan_window.h"

#include <QWidget>


class ScanWindow : public QWidget {
	Q_OBJECT

public:
	// special members
	ScanWindow(QWidget *parent = Q_NULLPTR);
	~ScanWindow();
	//------------------------------

	// methods
	void SetDiskLetter(std::string disk_letter);
	void Show();
	void Close();
	//------------------------------

signals:
	void SetDiskLetterSignal(std::string disk_letter);
	void ShowSignal();
	void CloseSignal();

private slots:
	void SetDiskLetterSlot(std::string disk_letter);
	void ShowSlot();
	void CloseSlot();

private:
	// member variables
	Ui::scan_windowClass ui;
	//------------------------------
};
