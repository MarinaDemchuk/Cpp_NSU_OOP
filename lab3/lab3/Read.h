#pragma once
#include "Block.h"
#include "ReaderException.h"
#include "Exception.h"
namespace Blocks {
	class ReadFile : public Blocks {
	public:
		std::list<std::string>& execute(std::list <std::string>& text, std::vector<std::string>& args) override;
		BlockType gettype() override;
		~ReadFile();
	private:
		std::ifstream input;
		Exception::ReadException faild;
	};
}
