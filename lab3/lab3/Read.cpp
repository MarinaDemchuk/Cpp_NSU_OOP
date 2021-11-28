#include "Read.h"
namespace Blocks{
std::list<std::string>& ReadFile::execute(std::list<std::string>&text, std::vector<std::string>&args)
{
	input.open(args[1]);
	if (!input.is_open()) {
		throw faild;
	}
	while (!input.eof()) {
		std::string str;
		getline(input, str);
		text.push_back(str);
	}

	return text;
}
BlockType ReadFile::gettype()
{

	return BlockType::IN;
}
ReadFile::~ReadFile()
{
	input.close();
}
}