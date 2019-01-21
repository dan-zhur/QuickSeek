#pragma once

#include "model_base.hpp"
#include "prefix_tree.hpp"


class Model : public ModelBase {
public:
	//special members
	virtual ~Model() override = default;
	//------------

	//overriding methods
	void ScanFileSystem() override;
	void SearchPrefix(const std::string& prefix, CallbackFunction callback) override;
	void StopSearch() override;
	//------------
private:
	//member variables
	PrefixTree _prefix_tree;
	//------------

	//methods
	//------------
};