#pragma once

#include "ModelBase.h"
#include "PrefixTree.h"
#include <thread>
#include <qdir.h>

class Model : public ModelBase
{
public:
	//construction / deletion
	virtual ~Model() override {}
	//------------

	//overriding methods
	virtual void ScanFileSystem() override;
	virtual void SearchPrefix(String prefix, CallbackFunction callback) override;
	virtual void StopSearch() override;
	//------------
private:
	//member variables
	PrefixTree prefixTree_;
	//------------

	//methods
	//------------
};