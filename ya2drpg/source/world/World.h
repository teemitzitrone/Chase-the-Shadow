#pragma once
#include "Chunk.h"
#include <vector>

enum Direction
{
	up, 
	right,
	down,
	left,
};

class World
{
	Chunk* _chunks[20];
	Chunk* _visibleChunks[6];
	Chunk* _duHastTolleHaende;

private:
	void _SetChunksForViewport();
	void _Up();
	void _Down();
	void _Left();
	void _Right();

public:
	World(void);
	virtual ~World(void);
	
	void Preload(Direction);
	void Dispose();
};

