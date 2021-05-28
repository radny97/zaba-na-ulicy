#pragma once
#include "PlaygroundSprite.h"
#include "TrackSprite.h"
#include "Point.h"
#include "Utilities.h"
#include <list>

class PlaygroundGraphics
{
public:
	PlaygroundGraphics() {};
	void SetPlaygroundSprite();
	void SetTrackSprites(Point positionOfTrack);

	std::list<TrackSprite> trackSprites;
	PlaygroundSprite* playgroundSprite;
};

