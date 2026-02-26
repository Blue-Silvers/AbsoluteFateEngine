#include "IInputListener.h"
#include "TheDescentMovingC.h"

class TheDescentController : public TheDescentMovingC, public IInputListener
{
private:
	float mMoveSpeed = 12;

	bool wireframe = true;

public:
	TheDescentController(Actor* pActor);
	bool changeAnim = false;
	void OnNotify(SDL_Event& pEvent) override;
	float GetMoveSpeed() { return mMoveSpeed; }
	void SetMoveSpeed(float pMoveSpeed) { mMoveSpeed = pMoveSpeed; }
};
