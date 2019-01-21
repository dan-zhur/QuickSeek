#pragma once

#include "../forms/ui_main_window.h"
#include "view_base.hpp"

#include <QMainWindow>
#include <QListview>
#include <QStringListModel>


class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	// special members
	MainWindow(ViewBase *view, QWidget *parent = Q_NULLPTR);
	//------------------------------

	// methods
	void AddPathToList(QString path);
	void ClearList();
	void Show();
	void Close();
	//------------------------------

signals:
	void AddStringSignal(QString str);
	void ShowSignal();
	void CloseSignal();

private slots:
	void AddStringSlot(QString str);
	void ButtonClicked();
	void ListDoubleClicked(const QModelIndex &index);
	void ShowSlot();
	void CloseSlot();

private:
	// member variables
	Ui::main_windowClass ui;
	QStringListModel _stringlistmodel;
	QStringList _path_stringlist;
	ViewBase *_view;
	//------------------------------
};
