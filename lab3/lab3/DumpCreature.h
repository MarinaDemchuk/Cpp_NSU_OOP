#pragma once
#include "Factory.h"
#include "Dump.h"
namespace Blocks {
	class DumpCreature : public Factory {
	public:
		Blocks* createBlock();
	};
}
