#include "DumpCreature.h"
namespace Blocks {
	Blocks* DumpCreature::createBlock()
	{
		return new Dump();
	}
}
