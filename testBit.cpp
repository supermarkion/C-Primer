#include <iostream>

using namespace std;

int main() 
{
    int a = 31;
    int b = 14;
    int c = a ^ b;
    cout << "first c is: " << c << endl;
    for (; c != 0; c &= c - 1)
    {
        cout << "c is: " << c << endl;
    }
}
