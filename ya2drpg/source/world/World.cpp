#include "World.h"


World::World(void)
{
}


World::~World(void)
{
}


void World::Preload(Direction direction)
{
	// mau-switch
	switch (direction) {
		case Direction::up:
			this->_Up();
			break;
		case Direction::right:
			this->_Right();
			break;
		case Direction::down:
			this->_Down();
			break;
		case Direction::left:
			this->_Left();
			break;
		default:
			break;
	}

	this->_SetChunksForViewport();
}


void World::Dispose()
{
}


void World::_SetChunksForViewport()
{
	int position = 0;
	for (int n = 0; n < 20; n++) {
		if (n % 5 != 0 
			&& n / 5 != 0 
			&& n / 5 != 3
		) {
			this->_visibleChunks[position] = this->_chunks[n];
		}
	}
}


void World::_Up()
{
	for (int n = 20; n > -5; n--) {
		if (n >= 15) {
			continue;
		}
		if (n >= 0) {
			this->_chunks[n + 5] = this->_chunks[n];
		} else {
			this->_chunks[n + 5] = new Chunk(1);
		}
	}
}

void World::_Right()
{
	for (int n = 0; n < 21; n++) {
		if (n % 5 != 0) {
			this->_chunks[n - 1] = this->_chunks[n];
		} else {
			if (n > 0) {
				this->_chunks[n - 1] = new Chunk(1);
			}
		}
	}
}

void World::_Down()
{
	for (int n = 0; n < 25; n++) {
		if (n < 5) {
			continue;
		}
		if (n < 20) {
			this->_chunks[n - 5] = this->_chunks[n];
		} else {
			this->_chunks[n - 5] = new Chunk(1);
		}
	}
}

void World::_Left()
{
	for (int n = 20; n >= -1; n--) {
		if (n % 5 != 4) {
			this->_chunks[n + 1] = this->_chunks[n];
		} else {
			if (n < 15) {
				this->_chunks[n + 1] = new Chunk(1);
			}
		}
	}
}