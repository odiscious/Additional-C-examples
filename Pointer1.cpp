/*
 *  Pointer1.cpp
 *
 *  Created by Rob Nash on 9/26/13.
 *  Copyright (c) 2013 Rob Nash. All rights reserved.
 *
 *  Modified by Michael Stiber on 1/6/14 and 4/3/14.
 */


#include <iostream>
using namespace std;


void display1(int l, int m, int n, int o, int* p) {
  cout << "\ndisplay1():" << endl;
  cout << "var1 is " << l << endl;
  cout << "var2 is " << m << endl;
  cout << "var3 is " << n << endl;
  cout << "var4 is " << o << endl;
  cout << "address of l (var1) is " << &l << endl;
}

void display2(int l, int m, int n, int o, int& p) {
	cout << "value stored at the address of 'p' or *p (address): " << p<< endl;
	cout << "address of p is the same address of the int OBJ that is passed in: " << &p << endl;
	cout << "Address for m: " << &m << endl;
  cout << "\ndisplay2():" << endl;
  cout << "var1 is " << l << endl;
  cout << "var2 is " << m << endl;
  cout << "var3 is " << n << endl;
  cout << "var4 is " << o << endl;
  cout << "address of l (var1) is " << &l << endl;
}

int main()
{
  int a = 3;
  int b,c,d;
  int* aPtr, bPtr;  //Pitfall: note that bPtr is an int, not an int *
  b=3;
  c=5;
  d = a + b + c;
    
  aPtr = &a;
  int valueOfA = *aPtr;
  cout << "value of 'a' via the pointer 'aPtr' (dereferenced): " << valueOfA << endl;
  cout << "value for a : " << &a << endl;
  display1(a,b,c,d,aPtr);
  display2(a,b,c,d,*aPtr);
    
    
  cout << "aPtr's value is " << *aPtr << endl;
  cout << "This is the same as &a, or " << &a << endl;
    
    
  cout << "aPtr points to the following value:  " << *aPtr << endl;
  cout << "This is the same as a, or " << a <<endl;
  cout << endl;

  // Your additional code here.
    
}