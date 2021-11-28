#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "Factory.h"
#include "DumpCreature.h"
#include "GrepCreature.h"
#include "ReaderCreature.h"
#include "ReplaceCreature.h"
#include "SortCreature.h"
#include "WriteCreature.h"
#include "Exception.h"
#include "SubsequenceFaild.h"
#include "ReaderException.h"
#include "WriteFaild.h"
namespace Exit {
	class WorkFlowExit {
	public:
		WorkFlowExit(std::vector<std::string>&, 
			std::list <std::pair<std::string, std::vector<std::string>>>&);
		void DoWorkFlow();
	private:
		std::vector<std::string> my_vector;
		std::list <std::pair<std::string, std::vector<std::string>>> text;
		std::list<std::string> my_list;
		Exception::SubsequenceFaild faild;
	};
}
