#pragma once
#include <list>
#include <vector>
#include <iostream>
#include "BlocType.h"
#include "fstream"
#include <string>
#include <fstream>
namespace Blocks {
	class Blocks {
	public:
		virtual std::list<std::string>& execute(std::list <std::string>& text, std::vector<std::string>& args) = 0;
		virtual BlockType gettype() = 0;
	};
}