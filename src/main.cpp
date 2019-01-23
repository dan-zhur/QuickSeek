#include "file_manager.hpp"
#include "controller.hpp"
#include "qt_view.hpp"

#include <QApplication>


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	FileManager manager;
	Controller controller;
	QtView view;
	
	manager.SetView(&view);

	view.SetController(&controller);

	controller.SetFileManager(&manager);
	controller.SetView(&view);

	controller.Run();

	return app.exec();
}
