﻿#pragma once

#include "ControllerBase.h"
#include <thread>


class Controller : public ControllerBase
{
public:
	//constuction / destruction
	virtual ~Controller();
	//------------------------------

	//overriding methods
	virtual void Run() override;
	virtual void SearchButtonPressed(const String& whatToSearch) override;
	virtual void StopSearchButtonPressed() override;
	//------------------------------

	//methods
	void SetModel(ModelBase* model) { model_ = model; }
	void SetView(ViewBase* view) { view_ = view; }
	//------------------------------
private:
	//methods
	void RunHelper_();
	//------------------------------

	//member variables
	ModelBase* model_;
	ViewBase* view_;

	std::thread runningThread_;
	//------------------------------
};