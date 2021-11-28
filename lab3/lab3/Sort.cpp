#include "Sort.h"
namespace Blocks {
		bool Comparator(std::string a, std::string b)
		{
			return a < b ;
		}
	std::list<std::string>& Sort::execute(std::list<std::string>& text, std::vector<std::string>& args)
	{ 
		text.sort(Comparator);
		return text;
	}
	BlockType Sort::gettype()
	{
		return BlockType::INOUT;
	}
}