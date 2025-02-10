#pragma once

#include "Core/xion.h"

class Collision
{
public:
	Collision() = default;
	~Collision() = default;

	//点の当たり判定
	bool PointPoint(float x1, float y1, float x2, float y2);
	bool TriPoint(float x1, float y1, float x2, float y2, float x3, float y3, float px, float py);
	bool RectPoint(float rx, float ry, float rw, float rh, float px, float py);
	bool CirclePoint(float cx, float cy, float r, float px, float py);
	bool PolyPoint(Vector2 vertices[], float px, float py);

	//円の当たり判定
	bool RectCircle(float cx, float cy, float radius, float rx, float ry, float rw, float rh);
	bool CircleCircle(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r);
	bool PolygonPoint(Vector2 vertices[], float px, float py);

	//矩形の当たり判定
	bool RectRect(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);
};