#include "Components.h"
#include "Actor.h"

Components::Components(Actor* pOwner) : mOwner(pOwner), mUpdateOrder(1)
{
}

Components::Components(Actor* pOwner, int pUpdateOrder) : mOwner(pOwner), mUpdateOrder(pUpdateOrder)
{
}
