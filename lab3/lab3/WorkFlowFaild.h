#pragma once
#include "Exception.h"
#include <string>
namespace Exception {
	class WorkFlowFaild : public MyException {
	public :
		std::string what() override;
	};
}
