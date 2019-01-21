#include "qt_main_window.hpp"

#include <QStringListModel>


QuickSeekUI::QuickSeekUI(ViewBase* view, QWidget *parent)
	: view_(view),
	  QMainWindow(parent)
{
	ui.setupUi(this);
	ui.listView->setModel(&stringListModel_);

	QObject::connect(this, SIGNAL(Addstd::stringSignal(Qstd::string)), SLOT(Addstd::stringSlot(Qstd::string)), Qt::QueuedConnection);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()), Qt::QueuedConnection);
	QObject::connect(ui.listView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(ListDoubleClicked(const QModelIndex&)), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(ShowSignal()), SLOT(ShowSlot()), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(CloseSignal()), SLOT(CloseSlot()), Qt::QueuedConnection);
}



void QuickSeekUI::Show()
{
	emit ShowSignal();
}



void QuickSeekUI::ShowSlot()
{
	show();
}



void QuickSeekUI::Close()
{
	emit CloseSignal();
}



void QuickSeekUI::CloseSlot()
{
	close();
}



void QuickSeekUI::AddPathToList(QString prefix)
{
	emit AddStringSignal(prefix); //to be called in UI-thread
}



void QuickSeekUI::ClearList()
{
	pathStringList_.clear();
}



void QuickSeekUI::AddStringSlot(QString str)
{
	pathStringList_.append(str);
	stringListModel_.setStringList(pathStringList_);
}



void QuickSeekUI::ListDoubleClicked(const QModelIndex& index)
{
	/*int x = index.row();
	QProcess* process = new QProcess();
	process->startDetached(QDir::rootPath() + "Windows/system32/explorer.exe " + "\"" + l[x] + "\"");*/
}



void QuickSeekUI::ButtonClicked()
{	
	view_->NotifySearchButtonClicked(ui.lineEdit->text().toStdString());
}