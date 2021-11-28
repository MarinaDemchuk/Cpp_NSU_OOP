#pragma once
#include <iostream>
#include "Block.h"
namespace Blocks {
	class Factory {
	public :
		virtual Blocks* createBlock() = 0;
		virtual ~Factory() {}
	};
}
