#include "Playground.h"

Playground::Playground()
{
	this->width = Utilities::screenResolutionX;
	this->height = Utilities::screenResolutionY;

	this->GeneratePlayground(this->width, this->height);
}

void Playground::GeneratePlayground(int widthOfWindow, int heightOfWindow)
{
	//tu bêdzie jakieœ losowanie wed³ug levela gry
	int numberOfTracks = 4;
	int widthOfTrack = 140;
	int widthOfSpaceBetweenTracks = 60;

	std::list<int> xCoordinatesOfFrogStandingPoints;

	//dodaj trasê maj¹c punkt w po³owie wysokoœci planszy

	int xCoordinateOfMiddleOfPlayground = widthOfWindow / 2;
	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground);

	int xCoordinateDifference = (widthOfSpaceBetweenTracks + widthOfTrack) / 2;

	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground + xCoordinateDifference);
	AddTrackBasedOnXCoordinate(xCoordinateOfMiddleOfPlayground + xCoordinateDifference, heightOfWindow, true);

	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground - xCoordinateDifference);
	AddTrackBasedOnXCoordinate(xCoordinateOfMiddleOfPlayground - xCoordinateDifference, heightOfWindow, false);

	for (int i = 0; i < (numberOfTracks/2)-1; i++)
	{
		xCoordinateDifference += widthOfTrack;

		xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground + xCoordinateDifference);
		AddTrackBasedOnXCoordinate(xCoordinateOfMiddleOfPlayground + xCoordinateDifference, heightOfWindow, true);

		xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground - xCoordinateDifference);
		AddTrackBasedOnXCoordinate(xCoordinateOfMiddleOfPlayground - xCoordinateDifference, heightOfWindow, false);
	}
	xCoordinateDifference += (widthOfSpaceBetweenTracks + widthOfTrack) / 2;
	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground + xCoordinateDifference);
	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground - xCoordinateDifference);

	xCoordinatesOfFrogStandingPoints.sort();
	int iteratorOfPoint = 0;
	for (auto const& iteratorOfxCoordinate : xCoordinatesOfFrogStandingPoints) 
	{
		this->frogStandingPoints.insert(std::make_pair(iteratorOfPoint,Point(iteratorOfxCoordinate, (heightOfWindow / 2))));
		iteratorOfPoint++;
	}

}

void Playground::AddTrackBasedOnXCoordinate(int xCoordinate, int heightOfWindow, bool fromDownToUp)
{
	int xDifferenceFromParameterCoordinate;
	xDifferenceFromParameterCoordinate = (heightOfWindow / 2) / Utilities::trackGrade; //k¹t nachylenia

	if (fromDownToUp == true)
	{
		Track newTrack = {
		//Point(xCoordinate + xDifferenceFromParameterCoordinate, 0),
		Point(xCoordinate - xDifferenceFromParameterCoordinate, heightOfWindow),
		fromDownToUp
		};
		this->tracks.push_back(newTrack);
	}
	else
	{
		Track newTrack = {
		Point(xCoordinate + xDifferenceFromParameterCoordinate, 0),
		//Point(xCoordinate - xDifferenceFromParameterCoordinate, heightOfWindow),
		fromDownToUp
		};
		this->tracks.push_back(newTrack);
	}
}