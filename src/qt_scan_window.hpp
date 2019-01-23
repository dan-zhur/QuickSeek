﻿#pragma once

#include "../forms/ui_scan_window.h"

#include <QWidget>


class ScanWindow : public QWidget {
	Q_OBJECT

public:
	// special members
	ScanWindow(QWidget *parent = Q_NULLPTR);
	ScanWindow(const ScanWindow&) = delete;
	ScanWindow(ScanWindow&&) = default;
	ScanWindow& operator=(const ScanWindow&) = delete;
	ScanWindow& operator=(ScanWindow&&) = default;
	~ScanWindow() override = default;
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
