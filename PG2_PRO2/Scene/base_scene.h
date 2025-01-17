#ifndef BASE_SCENE_H
#define BASE_SCENE_H

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();

	virtual void Init();
	virtual void Update();
	virtual void Render();

private:

};

#endif // !BASE_SCENE_H