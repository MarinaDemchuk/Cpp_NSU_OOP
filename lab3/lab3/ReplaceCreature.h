#pragma once
#include "Factory.h"
#include "Replace.h"
namespace Blocks {
	class ReplaceCreature : public Factory {
	public:
		Blocks* createBlock();
	};
}
