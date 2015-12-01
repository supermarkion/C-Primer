#include <iostream>
const char * quanlitfy[4] = 
{
	"10. -- 0meter race.\n",
	"mud tug-of-war.\n",
	"masters canoe jousting.\n",
	"pie-throwing festival.\n"
};
int main() 
{
	using namespace std;
	int age;
	cout << "Enter your age in years: ";
	cin >> age;
	int index;
	if(age > 17 && age < 35) {
		index = 0;
	} else if (age >= 35 && age < 50) {
		index = 1;
	} else if (age > 50 && age < 65) {
		index = 2;
	} else {
		index = 3;
	}
	cout << "You quanlitfy for the " << quanlitfy[index];
	return 0;
}