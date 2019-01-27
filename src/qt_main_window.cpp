#include "qt_main_window.hpp"

#include <QStringListModel>


MainWindow::MainWindow(ViewBase * const view, QWidget * const parent)
	: _view(view),
	  QMainWindow(parent) {
	ui.setupUi(this);
	ui.listView->setModel(&_stringlistmodel);

	QObject::connect(this, SIGNAL(AddStringSignal(const QString&)), SLOT(AddStringSlot(const QString&)), Qt::QueuedConnection);
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


void MainWindow::AddPathToList(const QString &prefix) {
	emit AddStringSignal(prefix);
}


void MainWindow::ClearList() {
	_path_stringlist.clear();
}


void MainWindow::AddStringSlot(const QString &str) {
	_path_stringlist.append(str);
	_stringlistmodel.setStringList(_path_stringlist);
}


void MainWindow::ButtonClicked() {	
	_view->NotifySearchButtonClicked(ui.lineEdit->text().toStdString());
}
