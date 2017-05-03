#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QuickSeekUI.h"
#include <qlistview.h>
#include <qstringlistmodel.h>
#include "ViewBase.h"


class QuickSeekUI : public QMainWindow
{
	Q_OBJECT

public:
	//construction / deletion
	QuickSeekUI(ViewBase* view, QWidget *parent = Q_NULLPTR);
	//------------

	//methods
	void AddPathToList(QString path);
	void ClearList();
	void Show();
	void Close();
	//------------

signals:
	void AddStringSignal(QString str);
	void ShowSignal();
	void CloseSignal();

private slots:
	void AddStringSlot(QString str);
	void ButtonClicked();
	void ListDoubleClicked(const QModelIndex& index);
	void ShowSlot();
	void CloseSlot();

private:
	//member variables
	Ui::QuickSeekUIClass ui;
	QStringListModel stringListModel_;
	QStringList pathStringList_;
	ViewBase* view_;
	//------------
};
