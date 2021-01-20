#pragma once
#include "Course.h"
class TrackCourse :
	public Course
{
	vector<string> TrackCrs;
public:
	TrackCourse();
	vector<string> getTrackCrs()const;
	virtual ~TrackCourse();
};

