﻿#pragma once

#include "model_base.hpp"
#include "prefix_tree.hpp"


class Model : public ModelBase {
public:
	//special members
	virtual ~Model() override = default;
	//------------

	//overriding methods
	virtual void ScanFileSystem() override;
	virtual void SearchPrefix(const std::string& prefix, CallbackFunction callback) override;
	virtual void StopSearch() override;
	//------------
private:
	//member variables
	PrefixTree prefixTree_;
	//------------

	//methods
	//------------
};