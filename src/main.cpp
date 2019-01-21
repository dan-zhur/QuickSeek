#include "model.hpp"
#include "controller.hpp"
#include "qt_view.hpp"

#include <QApplication>


int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	Model model;
	QtView view;
	Controller controller;
	
	model.SetView(&view);

	view.SetController(&controller);

	controller.SetModel(&model);
	controller.SetView(&view);

	controller.Run();

	return a.exec();
}
