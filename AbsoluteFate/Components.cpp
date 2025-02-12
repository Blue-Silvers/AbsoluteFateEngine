#include "Components.h"
#include "Actor.h"

Components::Components(Actor* pOwner, int pUpdateOrder)
{
	mOwner = pOwner;
	mUpdateOrder = pUpdateOrder;
}
