#pragma once

#include "controller_base.hpp"

#include <thread>


class Controller : public ControllerBase {
public:
	// special members
	virtual ~Controller();
	//------------------------------

	// overriding methods
	void Run() override;
	void SearchButtonPressed(const std::string &what_to_search) override;
	void StopSearchButtonPressed() override;
	//------------------------------

	// methods
	void SetModel(ModelBase *model) { _model = model; }
	void SetView(ViewBase *view) { _view = view; }
	//------------------------------
private:
	// methods
	void _RunHelper();
	//------------------------------

	// member variables
	ModelBase *_model;
	ViewBase *_view;

	std::thread _running_thread;
	//------------------------------
};
