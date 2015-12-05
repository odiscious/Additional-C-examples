#include "TimeSpan.h"
//-----------------------------------------------------------------------------
//TimeSpan
//Constructs a TimeSpan Object with hours, minutes, and seconds set to zero.
	TimeSpan::TimeSpan()
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

//-----------------------------------------------------------------------------
//TimeSpan
//params: A reference to a variable of Type int that is not modified in the 
//constructor.
//Constructs a TimeSpan Object that sets the time based on the amount of 
//seconds that is passed in.
	TimeSpan::TimeSpan(const int &secs)
	{
		int seconds = secs;
		setTime(seconds);
	}

//-----------------------------------------------------------------------------
//TimeSpan
//params: References to variables of Types float, int that are not modified  
//in the constructor.
//Constructs a TimeSpan Object that sets the hours, minutes, and seconds
//based on the amount of minutes and seconds that are passed in.
	TimeSpan::TimeSpan(const float &mins, const int &secs)
	{
		int tempSecs = convertToSeconds(0, mins, secs);
		setTime(tempSecs);
	}

//-----------------------------------------------------------------------------
//TimeSpan
//params: References to variables of Types float, int that are not modified  
//in the constructor.
//Constructs a TimeSpan Object that sets the hours, minutes, and seconds
//based on the amount of, hours, minutes, and seconds, that are passed in.
	TimeSpan::TimeSpan(const float &hr, const float &mins, const int &secs)
	{
		//TODO: CONTINUE TO TEST
		int tempSecs = convertToSeconds(hr, mins, secs);
		setTime(tempSecs);
	}

//-----------------------------------------------------------------------------
//setTime
//params: A reference to a variable of Type int.
//Converts and Sets the hours, minutes, and seconds of the current TimeSpan 
//Object based on the referenced value that is passed in.
	void TimeSpan::setTime(int &time)
	{
		hours = time / 3600;
		float tempTime = time - (hours*3600);
		minutes = tempTime / 60;
		tempTime -= (minutes*60);
		//using implicit casting from float to int via C++
		seconds = tempTime;
	}

//-----------------------------------------------------------------------------
//convertTimeSpanToSeconds
//Converts the current TimeSpan Object's hours, minutes, and seconds to 
//seconds and returns the value as an int.
	int TimeSpan::convertTimeSpanToSeconds() const
	{
		int secs = getSeconds();
		int mins = getMinutes();
		int hrs = getHours();
		secs = convertToSeconds(hrs, mins, secs);
		return secs;
	}

//-----------------------------------------------------------------------------
//convetToSeconds
//params: Types float, int to represent the hours, minutes, and seconds
//Converts the times passed in to a total of seconds and returns that value
//as an int.
	int TimeSpan::convertToSeconds(const float &hrs, 
		const float &mins, const int &secs) const
	{
		int tempSecs = (hrs*3600) + (mins*60) + secs;
		return tempSecs;
	}

//-----------------------------------------------------------------------------
//~TimeSpan
//A destructor for this class
//There is no need to call this function, because memory management is not an
//issue; therefore, there is no code to delete memory within the destructor.
	TimeSpan::~TimeSpan()
	{
	}

//-----------------------------------------------------------------------------
//getHours
//returns the hours as an int of the current TimeSpan Object
	int TimeSpan::getHours() const
	{
		return hours;
	}

//-----------------------------------------------------------------------------
//getMinutes
//returns the minutes as an int of the current TimeSpan Object
	int TimeSpan::getMinutes() const
	{
		return minutes;
	}

//-----------------------------------------------------------------------------
//getSeconds
//returns the seconds as an int of the current TimeSpan Object
	int TimeSpan::getSeconds() const
	{
		return seconds;
	}

//-----------------------------------------------------------------------------
//setHours
//params: A reference to a variable of Type int that represents the hours
//which the current TimeSpan Object is to be set to.
//Sets the minutes as an int of the current TimeSpan Object
	void TimeSpan::setHours(const int &hrs)
	{
		hours = hrs;
	}

//-----------------------------------------------------------------------------
//setMinutes
//params: A reference to a variable of Type int that represents the minutes
//which the current TimeSpan Object is to be set to.
//Sets the minutes as an int of the current TimeSpan Object
	void TimeSpan::setMinutes(const int &mins)
	{
		minutes = mins;
	}

//-----------------------------------------------------------------------------
//setMinutes
//params: A reference to a variable of Type int that represents the seconds
//which the current TimeSpan Object is to be set to.
//Sets the seconds as an int of the current TimeSpan Object
	void TimeSpan::setSeconds(const int &secs)
	{
		seconds = secs;
	}

//-----------------------------------------------------------------------------
//operator+
//params: a reference to a TimeSpan Object that is not modified in this
//function.
//Adds two TimeSpan Object's hours, minutes, and seconds together - without 
//altering their state.  Returns a TimeSpan Object that is the Sum 
//of two TimeSpan Objects.
TimeSpan TimeSpan::operator+(const TimeSpan &timeSpan) const
{
	int temp1 = convertTimeSpanToSeconds();
	int temp2 = timeSpan.convertTimeSpanToSeconds();
	int totalSeconds =  temp1 +  temp2;
	TimeSpan tempDuration(totalSeconds);

	return tempDuration;
}

//-----------------------------------------------------------------------------
//operator-
//params: The TimeSpan Object that is to have its signs for, hours, minutes, and
//seconds, inverted.
//Inverts the +/- sign of the values for hours, minutes, and seconds of the
//current Object.
TimeSpan TimeSpan::operator-(TimeSpan &timeSpan) const 
{
	int temp1 = convertTimeSpanToSeconds();
	int temp2 = timeSpan.convertTimeSpanToSeconds();
	int totalSeconds =  temp1 -  temp2;
	TimeSpan tempDuration(totalSeconds);

	return tempDuration;
}

//-----------------------------------------------------------------------------
//operator-
//Urinary operator: inverts the sign for hours, minutes, and seconds of the
//TimeSpan Object
TimeSpan& TimeSpan::operator-()
{
	hours *= -1;
	minutes *= -1;
	seconds *= -1;
	return *this;
}

//-----------------------------------------------------------------------------
//operator==
//params: A TimeSpan object to be compared against another TimeSpan Object
//Compares two TimeSpan objects and returns true if they're the same. 
//False, otherwise.
bool TimeSpan::operator==(const TimeSpan &duration) const
{
	bool isTrue = (hours == duration.getHours())&& 
		(minutes == duration.getMinutes()) && 
		(seconds == duration.getSeconds());
	return isTrue;
}

//-----------------------------------------------------------------------------
//operator!=
//params: A TimeSpan object to be compared against another TimeSpan Object
//Compares two TimeSpan objects and returns true if they're not the same. 
//False, otherwise.
bool TimeSpan::operator!=(TimeSpan &duration)
{
	bool isTrue = (hours != duration.getHours())|| 
		(minutes != duration.getMinutes()) || 
		(seconds != duration.getSeconds());
	return isTrue;
}

//-----------------------------------------------------------------------------
//operator+=
//params: One TimeSpan Object
//Adds the hours, minutes, and seconds from the TimeSpan that is passed in to
//the current TimeSpan Object.
//A reference to the current Object is returned.
TimeSpan& TimeSpan::operator+=(TimeSpan &duration)
{
	int tempTotalSec = seconds + duration.getSeconds();
	int tempMin = minutes + duration.getMinutes();
	int tempHrs = hours + duration.getHours();
	
	tempTotalSec = convertToSeconds(tempHrs, tempMin, tempTotalSec);
	setTime(tempTotalSec);

	return *this;
}

//-----------------------------------------------------------------------------
//operator-=
//params: One TimeSpan Object
//Subtracts the hours, minutes, and seconds of the TimeSpan that is passed from
//the current TimeSpan Object.
//A reference to the current Object is returned.
TimeSpan& TimeSpan::operator-=(TimeSpan &duration)
{
	int tempTotalSec = seconds - duration.getSeconds();
	int tempMin = minutes - duration.getMinutes();
	int tempHrs = hours - duration.getHours();
	
	tempTotalSec = convertToSeconds(tempHrs, tempMin, tempTotalSec);
	setTime(tempTotalSec);

	return *this;
}

//-----------------------------------------------------------------------------
//operator<<
//params: A reference to variables of Type ostream, TimeSpan
//TimeSpan Object is not modified - const
//Prints out a TimeSpan Objects data to the console, when called.
ostream&  operator<<(ostream &outStream, const TimeSpan &duration)
{
	outStream << "Horurs: " << duration.getHours() << "	Minutes:  "
		<< duration.getMinutes() << "	Seconds: " 
		<< duration.getSeconds() << endl;
	return outStream;
}

//-----------------------------------------------------------------------------
//operator>>
//params: A reference to variables of Type istream, TimeSpan
//Prints out a TimeSpan Objects data to the console, when called.
istream& operator>>(istream &inStream, TimeSpan &duration)
{
	int num, dem;
	inStream >> duration.hours >> duration.minutes >> duration.seconds;
	return inStream;
}