#pragma once

#include "config.hpp"
#include "model_base.hpp"
#include "view_base.hpp"


class ModelBase;
class ViewBase;


class ControllerBase
{
public:
	//types
	using Char = config::Char;
	using String = config::String;
	//------------

	//construction / deletion
	virtual ~ControllerBase() = default;
	//------------

	//pure virtual functions
	virtual void Run() = 0;
	virtual void SearchButtonPressed(const String& whatToSearch) = 0;
	virtual void StopSearchButtonPressed() = 0;
	//------------

	//methods
	inline void SetModel(ModelBase* model) { model_ = model; }
	inline void SetView(ViewBase* view) { view_ = view; }
	//------------

protected:
	//member variables
	ModelBase* model_{ nullptr };
	ViewBase* view_{ nullptr };
	//------------
};