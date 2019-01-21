#pragma once

#include "model_base.hpp"
#include "view_base.hpp"

#include <string>


class ModelBase;
class ViewBase;


class ControllerBase {
public:
	// special members
	virtual ~ControllerBase() = default;
	//------------------------------

	// pure virtual functions
	virtual void Run() = 0;
	virtual void SearchButtonPressed(const std::string &what_to_search) = 0;
	virtual void StopSearchButtonPressed() = 0;
	//------------------------------

	// methods
	void SetModel(ModelBase *model) { _model = model; }
	void SetView(ViewBase *view) { _view = view; }
	//------------------------------

protected:
	// member variables
	ModelBase *_model{ nullptr };
	ViewBase *_view{ nullptr };
	//------------------------------
};
