#include "BoxCollider2DC.h"

BoxCollider2DC::BoxCollider2DC(Transform2D pColliderBox, Actor* pParentActor) : Components(pParentActor, 0), mColliderBox(pColliderBox), mParentActor(pParentActor)
{

}
