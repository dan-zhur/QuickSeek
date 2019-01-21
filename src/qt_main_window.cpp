#include "qt_main_window.hpp"

#include <QStringListModel>


MainWindow::MainWindow(ViewBase* view, QWidget *parent)
	: _view(view),
	  QMainWindow(parent) {
	ui.setupUi(this);
	ui.listView->setModel(&_stringlistmodel);

	QObject::connect(this, SIGNAL(Addstd::stringSignal(Qstd::string)), SLOT(Addstd::stringSlot(Qstd::string)), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(ShowSignal()), SLOT(ShowSlot()), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(CloseSignal()), SLOT(CloseSlot()), Qt::QueuedConnection);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()), Qt::QueuedConnection);
	QObject::connect(ui.listView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(ListDoubleClicked(const QModelIndex&)), Qt::QueuedConnection);
}


void MainWindow::Show() {
	emit ShowSignal();
}


void MainWindow::ShowSlot() {
	show();
}


void MainWindow::Close() {
	emit CloseSignal();
}


void MainWindow::CloseSlot() {
	close();
}


void MainWindow::AddPathToList(QString prefix) {
	emit AddStringSignal(prefix); //to be called in UI-thread
}


void MainWindow::ClearList() {
	_path_stringlist.clear();
}


void MainWindow::AddStringSlot(QString str) {
	_path_stringlist.append(str);
	_stringlistmodel.setStringList(_path_stringlist);
}


void MainWindow::ListDoubleClicked(const QModelIndex& index) {
	/*int x = index.row();
	QProcess* process = new QProcess();
	process->startDetached(QDir::rootPath() + "Windows/system32/explorer.exe " + "\"" + l[x] + "\"");*/
}


void MainWindow::ButtonClicked() {	
	_view->NotifySearchButtonClicked(ui.lineEdit->text().toStdString());
}
