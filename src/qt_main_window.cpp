#include "qt_main_window.hpp"

#include <QStringListModel>


MainWindow::MainWindow(ViewBase *view, QWidget *parent)
	: _view(view),
	  QMainWindow(parent) {
	ui.setupUi(this);
	ui.listView->setModel(&_stringlistmodel);

	QObject::connect(this, SIGNAL(AddStringSignal(QString)), SLOT(AddStringSlot(QString)), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(ShowSignal()), SLOT(ShowSlot()), Qt::QueuedConnection);
	QObject::connect(this, SIGNAL(CloseSignal()), SLOT(CloseSlot()), Qt::QueuedConnection);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()), Qt::QueuedConnection);
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
	emit AddStringSignal(prefix);
}


void MainWindow::ClearList() {
	_path_stringlist.clear();
}


void MainWindow::AddStringSlot(QString str) {
	_path_stringlist.append(str);
	_stringlistmodel.setStringList(_path_stringlist);
}


void MainWindow::ButtonClicked() {	
	_view->NotifySearchButtonClicked(ui.lineEdit->text().toStdString());
}
