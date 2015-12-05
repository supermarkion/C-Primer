// stonewt1.h -- revised defintion for Stonwt class
#ifndef STONEWT1_H_
#define STONEWT1_H_
class Stonewt
{
private:
	enum {Lbs_per_stn = 14};		// pounds per stone
	int stone;						// whole stones
	double pds_left;				// fractional pounds
	double pounds;					// entire weight in pounds
public:
	Stonewt(double lbs);			// constructor for double pounds
	Stonewt(int std, double lbs);	// cosntructor for stone, lbs
	Stonewt();						// default constructor
	~Stonewt();
	void show_lbs() const;			// show weight in pounds format
	void show_stn() const;			// show weight in stone format
	operator int() const;
	operator double() const;
};
#endif