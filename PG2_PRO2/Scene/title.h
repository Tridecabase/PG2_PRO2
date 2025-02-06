#ifndef TITLE_H
#define TITLE_H

#include "base_scene.h"

class Title : public BaseScene
{
public:
	Title() = default;
	~Title() override;

	void Init() override;
	void Update() override;
	void Render() override;

private:

};

#endif // !TITLE_H