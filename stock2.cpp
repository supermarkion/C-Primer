// stock2.cpp -- improved version
#include <iostream>
#include <cstring>
#include "stock2.h"

// construction defintion
Stock::Stock()							// default constructor
{
	std::cout << "Default constructor called\n";
	std::strcpy(company, "no name");	// different mothod to assign string
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr)
{
	std::cout << "Constructor using " << co << " called\n";
	std::strncpy(company, co, 29);		// different mothod to assign string
	company[29] = '\0';
	if (n < 0) {
		std::cerr << "Number of shares can't be negative:"
			<< company << " shares set to 0.\n";
		shares = 0;
	} else {
		shares = n;
	}
	share_val = pr;
	set_tot();
}

// destructor defition
Stock::~Stock()
{
	std::cout << "Bye. " << company << "!\n";
}

// other methods
void Stock::buy(int num, double price)
{
	if (num < 0)
	{
		std::cerr << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	} else {
		shares += num;
		share_val = price;
		set_tot();	
	}
}

void Stock::sell(int num, double price)
{
	using std::cerr;
	if (num < 0) {
		cerr << "Number of shares sold cannot be negative. "
			<< "Transaction is aborted.\n";
	} else if (num > shares) {
		cerr << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	} else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	using std::cout;
	using std::endl;
	cout << "Company: " << company
		<< " Shares: " << shares << endl
		<< " Shares Price: $" << share_val
		<< " Total Worth: $" << total_val << endl;
}

const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val) {
		return s;
	} else {
		return *this;
	}
}