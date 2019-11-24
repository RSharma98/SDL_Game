#ifndef BLACKOVERLAYOBJECT_H
#define BLACKOVERLAYOBJECT_H

#include "GameObject.h"
#include "Time.h"

class BlackOverlayObject : public GameObject {
public:
	BlackOverlayObject();
	~BlackOverlayObject();
	void Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY);
	void Update();
	void BringIn();
	void BringOut();
	bool IsBringingIn() { return bringIn; }
	bool IsBringingOut() { return bringOut; }
	bool CompletedBringIn() { return completedBringIn; }
	bool CompletedBringOut() { return completedBringOut; }

private:
	bool bringIn;
	bool bringOut;
	bool completedBringIn;
	bool completedBringOut;
};

#endif // !BLACKOVERLAYOBJECT_H
