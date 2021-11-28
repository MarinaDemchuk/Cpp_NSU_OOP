#pragma once
#include "Block.h"
namespace Blocks {
	class Sort : public Blocks {
	public:
		std::list<std::string>& execute(std::list <std::string>& text, std::vector<std::string>& args) override;
		BlockType gettype() override;
	};
}
