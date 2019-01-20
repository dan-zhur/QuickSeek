#pragma once

#include "config.hpp"
#include "controller_base.hpp"
#include "view_base.hpp"

#include <functional>

class ControllerBase;
class ViewBase;

class ModelBase
{
public:
	//types
	using Char = config::Char;
	using String = config::String;
	using CallbackFunction = std::function<void(String)>;
	//------------

	//construction / deletion
	virtual ~ModelBase() = default;
	//------------

	//pure virtual functions
	virtual void ScanFileSystem() = 0;
	virtual void SearchPrefix(const String& prefix, CallbackFunction callback) = 0;
	virtual void StopSearch() = 0;
	//------------

	//methods
	inline void SetView(ViewBase* view) { view_ = view; }
	//------------

protected:
	//member variables
	ViewBase* view_{ nullptr };
	//------------
};