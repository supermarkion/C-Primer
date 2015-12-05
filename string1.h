// string1.h -- fixing and augmented string class definition
#include <iostream>
using std::ostream;
using std::istream;

#ifndef STRING1_H_
#define STRING1_H_
class String
{
private:
	char * str;						// pointer to string
	int len;						// length of string
	static int num_strings;			// number of objects
	static const int CINLIM = 80;	// cin input limit
public:
	String (const char * s);		// constructor
	String ();						// default constructor
	String (const String & );		// copy construction
	~String();
	int length() const { return len; };
	int maxLimit() const { return CINLIM; };
	
	String & operator= (const String & st);
	String & operator= (const char * s);
	char & operator[] (int i);
	const char & operator[] (int i) const;

	friend bool operator< (const String &st1, const String &st2);
	friend bool operator> (const String &st1, const String &st2);
	friend bool operator== (const String &st1, const String &st2);
	friend ostream & operator<< (ostream & os, const String &st);
	friend istream & operator>> (istream & is, String & st);

	static int HowMany();
};
#endif
