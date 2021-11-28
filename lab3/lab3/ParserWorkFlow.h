#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "Exception.h"
#include "WorkFlowFaild.h"
namespace WorkFlow {
	class WorkFlowExecutor {
	private:
		std::ifstream input;
		std::string str;
		std::list<std::pair<std::string, std::vector<std::string>>> manual;
		std::vector<std::string> command_sequence;
		Exception::WorkFlowFaild p;
	public:
		void execute();
		WorkFlowExecutor(std::string file_name);
		std::list <std::pair<std::string, std::vector<std::string>>> get_list();
		std::vector<std::string> get_command();
	};
}