#pragma once
#include <string>
#include "Exception.h"
namespace Exception{
	class WriteExceptionFaild : public MyException {
		public:
		std::string what() override;
	};
}
