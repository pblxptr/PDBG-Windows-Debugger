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
#include "ConsoleCommandHandler.h"
#include <sstream>

class Dbg : public IDebugger {
	// Inherited via IDebugger
	virtual bool run(std::string application) override
	{
		return false;
	}
	virtual bool setSingleStep(DWORD threadId, bool raiseEvent = true) override
	{
		return false;
	}
	virtual bool jumpNextInstruction() override
	{
		return false;
	}
	virtual bool addBreakpoint(LPVOID address, HANDLE hProcess, DWORD threadId) override
	{
		return false;
	}
	virtual bool removeBreakpoint(LPVOID address, HANDLE hProcess) override
	{
		return false;
	}
	virtual std::vector<std::shared_ptr<nBreakpoint>> getBreakpoints() override
	{
		return std::vector<std::shared_ptr<nBreakpoint>>();
	}
	virtual std::vector<DWORD> getThreads() override
	{
		return std::vector<DWORD>();
	}
};

int main()
{
	auto dbg = std::make_shared<Dbg>();
	auto cmd1 = std::make_shared<AddBreakpoint>();
	auto cmd2 = std::make_shared<ShowBreakpoints>();

	std::map<std::string, std::shared_ptr<IConsoleCommand>> commands;
	commands[cmd1->optcode()] = cmd1;
	commands[cmd2->optcode()] = cmd2;

	while (true)
	{
		std::string line = "";
		std::string command;
		std::string args;

		std::cout << "Type command: ";
		std::getline(std::cin, line);

		std::stringstream ss(line);

		ss >> command >> args;

		if (commands.find(command) == commands.end()) {
			std::cout << "Commands:" << std::endl;
			for (auto &x : commands) {
				std::cout << " -> " << x.first << std::endl;
			}

			continue;
		}

		auto x = commands[command];
		x->parse(args);

		if (!x->validate()) {
			std::cout << x->helper() << std::endl;
			continue;
		}

		x->handle(dbg);

		if (x->needBreak()) {
			break;
		}
	}


	//std::shared_ptr<EventBus> bus = std::make_shared<EventBus>();
	//std::shared_ptr<ResourceManager> rm = std::make_shared<ResourceManager>();
	//std::shared_ptr<ISingleStepper> dbgStepper = std::make_shared<SingleStepper>(bus, rm);
	//std::shared_ptr<Debugger> dbg = std::make_shared<Debugger>(bus, rm, dbgStepper);

	//auto controller = std::make_unique<ConsoleController>(dbg, bus);
	//controller->run();

	getchar();
	
	return 0;
}

