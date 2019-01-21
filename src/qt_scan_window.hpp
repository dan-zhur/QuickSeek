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
	void SetDiskLetter(std::string diskLetter);
	void Show();
	void Close();
	//------------------------------

signals:
	void SetDiskLetterSignal(std::string diskLetter);
	void ShowSignal();
	void CloseSignal();

private slots:
	void SetDiskLetterSlot(std::string diskLetter);
	void ShowSlot();
	void CloseSlot();

private:
	// member variables
	Ui::scan_windowClass ui;
	//------------------------------
};
