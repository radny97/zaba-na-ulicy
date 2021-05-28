#include "PlaygroundGraphics.h"

void PlaygroundGraphics::SetPlaygroundSprite()
{
	this->playgroundSprite = new PlaygroundSprite();
}

void PlaygroundGraphics::SetTrackSprites(Point positionOfTrack)
{
	TrackSprite* track = new TrackSprite();
	track->setPosition(positionOfTrack.coordinateX, positionOfTrack.coordinateY - (Utilities::trackGrade*(Utilities::widthOfTrack / 2)));
	track->setRotation(Utilities::trackGradeDegrees);
	this->trackSprites.push_back(*track);
}