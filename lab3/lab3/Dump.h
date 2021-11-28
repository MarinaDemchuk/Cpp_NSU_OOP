#pragma once
#include "Block.h"
namespace Blocks {
	class Dump : public Blocks {
	public:
		std::list<std::string>& execute(std::list <std::string>& text, std::vector<std::string>& args) override;
		BlockType gettype() override;
		~Dump();
	private:
		std::ofstream out;
	};
}
