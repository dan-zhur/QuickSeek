#include "file_manager.hpp"
#include "controller.hpp"
#include "qt_view.hpp"

#include <QApplication>


int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	QtView view;
	FileManager manager;
	Controller controller;
	
	manager.SetView(&view);

	view.SetController(&controller);

	controller.SetFileManager(&manager);
	controller.SetView(&view);

	controller.Run();

	return a.exec();
}
