#include<iostream>
#include"TimeSpan.h"
using namespace std;
void testOperatorMinus();
void testDriver();
int main()
{
	
	testDriver();

	return 0;
}
void testConstructorAndSetTimeFunction()
{
		TimeSpan rs(1,2.5,0);
	/*TimeSpan ts(0, 0, 7400);
	TimeSpan secondsOnly(-100);*/

	//Test setTime()
	int second = -1000000000;	//this is the largest addition of 0 before significant change in output value
	rs.setTime(second);

	/*cout << "hours: " << ts.getHours() << endl;
	cout << "minutes: " << ts.getMinutes() << endl;
	cout << "seconds: " << ts.getSeconds() << endl;*/

	cout << endl;
	cout << endl;
	cout << "hours: " << rs.getHours() << endl;
	cout << "minutes: " << rs.getMinutes() << endl;
	cout << "seconds: " << rs.getSeconds() << endl;

	cout << endl;
	cout << endl;
	//cout << "seconds: " << secondsOnly.getSeconds() << endl;
}
void testOperatorPlus()
{
	TimeSpan dur1(400);
	cout << "duration 1: " << endl;
	cout << dur1.getHours() << endl;
	cout << dur1.getMinutes() << endl;
	cout << dur1.getSeconds() << endl;

	

	
	TimeSpan dur2(200);
	cout << "duration 2: " << endl;

	cout << dur2.getHours() << endl;
	cout << dur2.getMinutes() << endl;
	cout << dur2.getSeconds() << endl;

	TimeSpan dur3 = dur1 + dur2;
	cout << "duration 3: " << endl;

	cout << dur3.getHours() << endl;
	cout << dur3.getMinutes() << endl;
	cout << dur3.getSeconds() << endl;
}
void testOperatorMinus()
{
	TimeSpan dur1(400);
	cout << "duration 1: " << endl;
	cout << dur1.getHours() << endl;
	cout << dur1.getMinutes() << endl;
	cout << dur1.getSeconds() << endl;

	

	
	TimeSpan dur2(200);
	cout << "duration 2: " << endl;

	cout << dur2.getHours() << endl;
	cout << dur2.getMinutes() << endl;
	cout << dur2.getSeconds() << endl;

	TimeSpan dur3 = dur1 - dur2;
	cout << "duration 3: " << endl;

	cout << dur3.getHours() << endl;
	cout << dur3.getMinutes() << endl;
	cout << dur3.getSeconds() << endl;
}
void testNegation()
{
	TimeSpan dur1(10,20,30);
	-dur1;
	cout << dur1.getHours() << endl;
	cout << dur1.getMinutes() << endl;
	cout << dur1.getSeconds() << endl;
}
void testIsEquals()
{
	TimeSpan dur1(10,10,10);
	TimeSpan dur2(10,10,10);
	if(dur1 == dur2){
		cout << "yes" << endl;
	}
	else
		cout << "false" << endl;
}
void testPlusEqualsOperator()
{
	TimeSpan dur1(10,10,10);
	TimeSpan dur2(10,10,10);

	dur1 += dur2;
	cout << dur1.getHours() << endl;
	cout << dur1.getMinutes() << endl;
	cout << dur1.getSeconds() << endl;
}
void testMinusEqualsOperator()
{
	TimeSpan dur1(30,30,30);
	TimeSpan dur2(50,50,90);

	dur1 -= dur2;
	cout << dur1.getHours() << endl;
	cout << dur1.getMinutes() << endl;
	cout << dur1.getSeconds() << endl;
}
void testDriver()
{
	int waitVar;
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
	TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;
	dur7 = dur1 + dur3;
	cout<< dur1;
	cout<< dur2;
	cout<< dur3;
	cout<< dur4;
	cout<< dur5;
	cout<< dur6;
	cout<< dur7;
	dur7 += dur3;
	cout<< dur3;
	cout<< dur7;
	if (dur3 != dur6)
	{
	cout<<"Durations are different."<<endl;
	}
	else
	{
	cout<<"Durations are the same"<<endl; 
	}
}