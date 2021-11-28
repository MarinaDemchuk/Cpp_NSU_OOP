#include "Replace.h"
#include "Ñonstants.h"
namespace Blocks {
	std::list<std::string>& Replace::execute(std::list<std::string>& text, std::vector<std::string>& args)
	{
		std::string word1 = args[Constants::START_FILE];
		std::string word2 = args[Constants::TWO_ARGUMENT];
		for (auto it = text.begin(); it != text.end(); ++it) {
			std::string word = "";
			for (int i = 0; i < (*it).size(); ++i) {
				if ((*it)[i] >= Constants::START_LITTLE_ENGLISH && (*it)[i] <= Constants::END_LITTLE_ENGLISH) {
					word += (*it)[i];
					if (word == word1) {
						auto pos = (*it).find(word1);
						(*it).erase(pos, word1.size());
						(*it).insert(pos, word2);
						word = "";
					}
				}
				else {
					word = "";
				}
			}

		}
		return text;
	}
	BlockType Replace::gettype()
	{
		return BlockType::INOUT;
	}
}