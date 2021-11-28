#pragma once
#include "Exception.h"
#include <string>
namespace Exception {
	class SubsequenceFaild : public MyException {
	public:
		std::string what() override;
	};
}
