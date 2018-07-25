// PDbg.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <memory>

#include "Signal.h"
#include "Debugger.h"
#include "ConsoleController.h"
#include "EventBus.h"
#include "SingleStepper.h"

int main()
{
	std::shared_ptr<EventBus> bus = std::make_shared<EventBus>();
	std::shared_ptr<ResourceManager> rm = std::make_shared<ResourceManager>();
	std::shared_ptr<ISingleStepper> dbgStepper = std::make_shared<SingleStepper>(bus, rm);
	std::shared_ptr<Debugger> dbg = std::make_shared<Debugger>(bus, rm);

	auto controller = std::make_unique<ConsoleController>(dbg, bus);
	controller->run();

	getchar();
	
	return 0;
}

