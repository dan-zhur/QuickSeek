#pragma once

#include "../forms/ui_main_window.h"
#include "view_base.hpp"

#include <QMainWindow>
#include <QListview>
#include <QStringListModel>


class MainWindow : protected QMainWindow {
	Q_OBJECT

public:
	// special members
	MainWindow(ViewBase * const view, QWidget * const parent = Q_NULLPTR);
	MainWindow(const MainWindow&) = delete;
	MainWindow(MainWindow&&) = default;
	MainWindow& operator=(const MainWindow&) = delete;
	MainWindow& operator=(MainWindow&&) = default;
	~MainWindow() override = default;
	//------------------------------

	// methods
	void AddPathToList(const QString &path);
	void ClearList();
	void Show();
	void Close();
	//------------------------------

signals:
	void AddStringSignal(const QString &str);
	void ShowSignal();
	void CloseSignal();

private slots:
	void AddStringSlot(const QString &str);
	void ButtonClicked();
	void ShowSlot();
	void CloseSlot();

private:
	// member variables
	Ui::main_windowClass ui;
	QStringListModel _stringlistmodel;
	QStringList _path_stringlist;
	ViewBase * const _view;
	//------------------------------
};
