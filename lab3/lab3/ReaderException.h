#pragma once
#include <string>
#include "Exception.h"
namespace Exception {
	class ReadException : public MyException {
	public:
		std::string what() override;
	};
}
