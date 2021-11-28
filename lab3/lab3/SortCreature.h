#pragma once
#include "Factory.h"
#include "Sort.h"
namespace Blocks {
	class SortCreature : public Factory {
	public:
		Blocks* createBlock();
	};
}
