#include "Grep.h"
namespace Blocks {
	std::list<std::string>& Grep::execute(std::list<std::string>& text, std::vector<std::string>& args)
	{
		std::list <std::string> my_list;
		std::string word = args[1];
		for (auto it = text.begin(); it != text.end(); ++it) {
			if ((*it).find(word) != std::string::npos) {
				my_list.push_back((*it));
			}
		}
		return my_list;
	}
	BlockType Grep::gettype()
	{
		return BlockType::INOUT;
	}
}