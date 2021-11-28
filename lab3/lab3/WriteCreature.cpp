#include "WriteCreature.h"
namespace Blocks {
	Blocks* WriteCreature::createBlock()
	{
		return new WriteFile();
	}
}
