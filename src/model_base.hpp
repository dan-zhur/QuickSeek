#pragma once

#include "controller_base.hpp"
#include "view_base.hpp"

#include <functional>
#include <string>

class ControllerBase;
class ViewBase;

class ModelBase
{
public:
	//types
	using CallbackFunction = std::function<void(std::string)>;
	//------------

	//construction / deletion
	virtual ~ModelBase() = default;
	//------------

	//pure virtual functions
	virtual void ScanFileSystem() = 0;
	virtual void SearchPrefix(const std::string& prefix, CallbackFunction callback) = 0;
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