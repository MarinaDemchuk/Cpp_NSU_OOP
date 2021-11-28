#include "GrepCreature.h"
namespace Blocks {
	Blocks* GrepCreature::createBlock()
	{
		return new Grep();
	}
}
