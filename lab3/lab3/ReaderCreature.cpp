#include "ReaderCreature.h"
namespace Blocks {
	Blocks* ReaderCreature::createBlock()
	{
		return new ReadFile();
	}
}
