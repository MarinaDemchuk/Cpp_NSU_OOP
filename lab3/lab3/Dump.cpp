#include "Dump.h"
namespace Blocks {
	std::list<std::string>& Dump::execute(std::list<std::string>& text, std::vector<std::string>& args)
	{
		out.open(args[1]);
		if (!out.is_open()) {
			std::cout << "error out1" << std::endl;
		}
		for (auto it = text.begin(); it != text.end(); ++it) {
			out << (*it) << std::endl;
		}
		return text;
}
	BlockType Dump::gettype()
	{
		return BlockType::INOUT;
	}
	Dump::~Dump()
	{
		out.close();
	}
}