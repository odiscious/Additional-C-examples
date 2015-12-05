#ifndef TimeSpan_H
#define TimeSpan_H
#include<string>;
using namespace std;

class TimeSpan {
	friend istream& operator>>(istream &, TimeSpan &);
	friend ostream& operator<<(ostream &, const TimeSpan &);
public:

	TimeSpan();	//constructor 
	TimeSpan(const int &);
	TimeSpan(const float &mins, const int &secs);
	TimeSpan(const float &, const float &, const int &);

	void TimeSpan::setTime(int &secs);
	int TimeSpan::convertTimeSpanToSeconds() const;

	int convertToSeconds(const float &hrs, 
		const float &mins, const int &secs) const;

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	void setHours(const int&);
	void setMinutes(const int&);
	void setSeconds(const int&);
	~TimeSpan();//destructor

	TimeSpan operator+(const TimeSpan &timeSpan) const;
	TimeSpan& operator-();
	TimeSpan operator-(TimeSpan &timeSpan) const;

	bool operator==(const TimeSpan &duration) const;
	bool operator!=(TimeSpan &duration);
	TimeSpan& operator+=(TimeSpan &duration);
	TimeSpan& operator-=(TimeSpan &duration);

private:
	int hours, minutes, seconds;
};
#endif