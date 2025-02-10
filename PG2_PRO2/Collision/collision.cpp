#include "collision.h"

//点と点の当たり判定
bool Collision::PointPoint(float x1, float y1, float x2, float y2) {
	if (x1 == x2 && y1 == y2) {
		return true;
	}
	return false;
}

//三角形と点の当たり判定
bool Collision::TriPoint(float x1, float y1, float x2, float y2, float x3, float y3, float px, float py) {

	double areaOrig = fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));

	double area1 = fabs((x1 - px) * (y2 - py) - (x2 - px) * (y1 - py));
	double area2 = fabs((x2 - px) * (y3 - py) - (x3 - px) * (y2 - py));
	double area3 = fabs((x3 - px) * (y1 - py) - (x1 - px) * (y3 - py));

	if (static_cast<int>(area1 + area2 + area3) == static_cast<int>(areaOrig)) {
		return true;
	}
	return false;
}

//矩形と点の当たり判定
bool  Collision::RectPoint(float rx, float ry, float rw, float rh, float px, float py) {

	if (px >= rx &&
		px <= rx + rw &&
		py >= ry &&
		py <= ry + rh) {
		return true;
	}
	return false;
}

//円と点の当たり判定
bool  Collision::CirclePoint(float cx, float cy, float r, float px, float py) {

	float distX = px - cx;
	float distY = py - cy;
	float distance = sqrt((distX * distX) + (distY * distY));

	if (distance <= r) {
		return true;
	}
	return false;
}

//多角形と点の当たり判定
bool Collision::PolyPoint(Vector2 vertices[], float px, float py) {
	bool collision = false;

	int next = 0;
	for (int current = 0; current < sizeof(vertices); current++) {

		next = current + 1;
		if (next == sizeof(vertices)) {
			next = 0;
		}

		Vector2 vc = vertices[current];
		Vector2 vn = vertices[next];

		if (((vc.y >= py && vn.y < py) || (vc.y < py && vn.y >= py)) &&
			(px < (vn.x - vc.x) * (py - vc.y) / (vn.y - vc.y) + vc.x)) {
			collision = !collision;
		}
	}
	return collision;
}

//矩形と円の当たり判定
bool Collision::RectCircle(float cx, float cy, float radius, float rx, float ry, float rw, float rh) {

	float testX = cx;
	float testY = cy;

	if (cx < rx)         testX = rx;
	else if (cx > rx + rw) testX = rx + rw;
	if (cy < ry)         testY = ry;
	else if (cy > ry + rh) testY = ry + rh;

	float distX = cx - testX;
	float distY = cy - testY;
	float distance = sqrt((distX * distX) + (distY * distY));

	if (distance <= radius) {
		return true;
	}
	return false;
}

//円と円の当たり判定
bool Collision::CircleCircle(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r) {

	float distX = c1x - c2x;
	float distY = c1y - c2y;
	float distance = sqrt((distX * distX) + (distY * distY));

	if (distance <= c1r + c2r) {
		return true;
	}
	return false;
}

//多角形と円の当たり判定
bool Collision::PolygonPoint(Vector2 vertices[], float px, float py) {
	bool collision = false;

	int next = 0;
	for (int current = 0; current < sizeof(vertices); current++) {

		next = current + 1;
		if (next == sizeof(vertices)) next = 0;

		Vector2 vc = vertices[current];
		Vector2 vn = vertices[next];

		if (((vc.y > py && vn.y < py) || (vc.y < py && vn.y > py)) &&
			(px < (vn.x - vc.x) * (py - vc.y) / (vn.y - vc.y) + vc.x)) {
			collision = !collision;
		}
	}
	return collision;
}

//矩形と矩形の当たり判定
bool Collision::RectRect(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) {

	if (r1x + r1w >= r2x && 
		r1x <= r2x + r2w && 
		r1y + r1h >= r2y && 
		r1y <= r2y + r2h) {
		return true;
	}
	return false;
}