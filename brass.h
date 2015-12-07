// brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_

// Brass Account class
class Brass
{
private:
	enum {MAX = 35};
	char fullName[MAX];
	long acctNum;
	double balance;
public:
	Brass (const char * s = "Nullboy", long an = -1,
				double bal = 0.0);
	void Deposit (double amt);
	virtual void Withdraw (double amt);
	double Balance()const;
	virtual void ViewAcct()const;
	virtual ~Brass() {}
};

// Brass Plus Account class
class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double ownsBank;
public:
	BrassPlus(const char * s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500,
		double r = 0.10);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax (double m) { maxLoan = m; }
	void ResetRate (double r) { rate = r; }
	void ResetOwes() { ownsBank = 0; }
};

#endif