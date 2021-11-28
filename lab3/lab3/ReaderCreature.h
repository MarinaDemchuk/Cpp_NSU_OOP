#pragma once
#include "Factory.h"
#include "Read.h"
namespace Blocks {
	class ReaderCreature : public Factory {
	public:
		Blocks* createBlock();
	};
}
