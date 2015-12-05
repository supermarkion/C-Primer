// string1.cpp -- String class methods
#include <cstring>				// string.h for some
#include "string1.h"			// includes <iostream>
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static methods
int String::HowMany()
{
	return num_strings;
}

// class methods
String::String (const char * s)	// construct String from C string
{
	len = std::strlen(s);		// set size
	str = new char[len + 1];	// allot storage
	std::strcpy(str, s);		// initialize pointer
	num_strings++;				// set object count
}

String::String ()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String (const String & st)
{
	num_strings++;				// handle static member update
	len = st.len;				// same length
	str = new char[len + 1];	// allot space
	std::strcpy(str, st.str);	// copy string to new location
}

String::~String()				// necessary destructor
{
	--num_strings;				// required
	delete [] str;				// required
}

String & String::operator= (const String & st)
{
	if (this == &st) {
		return *this;
	}
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String & String::operator= (const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char & String::operator[] (int i)
{
	return str[i];
}

const char & String::operator[] (int i) const
{
	return str[i];
}

bool operator< (const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator> (const String &st1, const String &st2)
{
	return st2.str < st1.str;
}

bool operator== (const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<< (ostream & os, const String & st)
{
	os << st.str;
	return os;
}

istream & operator>> (istream & is, String & st)
{
	char temp[st.maxLimit()];
	is.get(temp, st.maxLimit());
	if (is) {
		st = temp;
	}
	while (is && is.get() != '\n') {
		continue;
	}
	return is;
}