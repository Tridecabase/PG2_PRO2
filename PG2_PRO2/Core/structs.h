#ifndef STRUCTS_H
#define STRUCTS_H

/*ACTORステータスを管理する構造体*/
typedef struct ActorState {
	float x;
	float y;
	float vx;
	float vy;
	float radius;
	float angle;
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int a;
	int hp;
	int max_hp;
}ActorState;

#endif // !STRUCTS_H