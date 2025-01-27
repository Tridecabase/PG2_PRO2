#ifndef BASE_SCENE_H
#define BASE_SCENE_H

#include "Core/xion.h"

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();

	virtual void Init();
	virtual void Update();
	virtual void Render();

protected:
	unsigned int back_color;
};

#endif // !BASE_SCENE_H