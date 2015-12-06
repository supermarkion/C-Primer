// tabtenn0.h -- a table-tennis base class
#ifndef TABTENNO_H_
#define TABTENNO_H_
// simple base class
class TableTennisPlayer
{
private:
	enum {LIM = 20};
	char firstname[LIM];
	char lastname[LIM];
	bool hasTable;
public:
	TableTennisPlayer (const char * fn = "none", const char * ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return hasTable; };
	void ResetTABLE ( bool v ) { hasTable = v; };
};
#endif