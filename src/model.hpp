#pragma once

#include "model_base.hpp"
#include "prefix_tree.hpp"


class Model : public ModelBase
{
public:
	//construction / deletion
	virtual ~Model() override = default;
	//------------

	//overriding methods
	virtual void ScanFileSystem() override;
	virtual void SearchPrefix(const String& prefix, CallbackFunction callback) override;
	virtual void StopSearch() override;
	//------------
private:
	//member variables
	PrefixTree prefixTree_;
	//------------

	//methods
	//------------
};