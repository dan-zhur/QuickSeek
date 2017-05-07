#include <QtWidgets/QApplication>
#include "Model.h"
#include "Controller.h"
#include "View.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Model model;
	View view;
	Controller controller;
	
	model.SetView(&view);

	view.SetController(&controller);

	controller.SetModel(&model);
	controller.SetView(&view);

	controller.Run();

	return a.exec();
}
