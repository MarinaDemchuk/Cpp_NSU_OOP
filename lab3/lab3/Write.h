#pragma once
#include "Block.h"
#include "WriteFaild.h"
namespace Blocks {
	class WriteFile : public Blocks {
	public:
		std::list<std::string>& execute(std::list <std::string>& text, std::vector<std::string>& args) override;
		BlockType gettype() override;
		~WriteFile();
	private:
		Exception::WriteExceptionFaild faild;
		std::ofstream out1;
	};
}
