#pragma once
#include "Factory.h"
#include "Write.h"
namespace Blocks {
	class WriteCreature : public Factory {
	public:
		Blocks* createBlock();
	};
}
