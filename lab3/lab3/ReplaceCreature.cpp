#include "ReplaceCreature.h"
namespace Blocks {
	Blocks* ReplaceCreature::createBlock()
	{
		return new Replace();
	}
}
