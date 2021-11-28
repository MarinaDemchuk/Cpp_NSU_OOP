#pragma once
#include "Factory.h"
#include "Grep.h"
namespace Blocks {
	class GrepCreature : public Factory {
	public:
		Blocks* createBlock();
	};
}
