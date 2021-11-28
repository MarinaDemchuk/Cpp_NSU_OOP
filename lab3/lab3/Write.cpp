#include "Write.h"
#include "Ñonstants.h"
namespace Blocks {
	std::list<std::string>& WriteFile::execute(std::list<std::string>& text, std::vector<std::string>& args)
	{
		out1.open(args[Constants::START_FILE]);
		if (!out1.is_open()) {
			throw faild;
		}
		for (auto it = text.begin(); it != text.end(); ++it) {
			out1 << (*it) << std::endl;
		}
		return text;
	}
	BlockType WriteFile::gettype()
	{
		return BlockType::OUT;
	}
	WriteFile::~WriteFile()
	{
		out1.close();
	}
}