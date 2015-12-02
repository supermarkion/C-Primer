#include<iostream>
#include<vector>

using namespace std;
/*
int main() {

	std::vector<int> b_lake = {3, 2, 0, 1}; // boyang lake
	std::vector<int> d_lake = {1, 4, 3, 3}; // dongting lake
	std::vector<int> t_lake = {0, 3, 0, 4}; // taihu lake
	std::vector<int> h_lake = {4, 1, 4, 2}; // hongze lake
	int count = 0;
	for (int i = 0; i < b_lake.size(); i++) {
		for (int j = 0; j < d_lake.size(); j++) {
			if (i != j) {
				for (int k = 0; k < t_lake.size(); k++) {
					if (k != i && k != j) {
						for (int n = 0; n < h_lake.size(); n++) {
							if (n != i && n != j && n != k) {
								if (b_lake[i] + d_lake[j] + t_lake[k] + h_lake[n] == 10 && b_lake[i] * d_lake[j] * t_lake[k] * h_lake[n] == 24) {
									count++;
									cout << "DoYang Lake ranke at: " << b_lake[i] << endl;
									cout << "Dongting Lake ranke at: : " << d_lake[j] << endl;
									cout << "Taihu Lake ranke at: : " << t_lake[k] << endl;
									cout << "Hongze Lake ranke at: : " << h_lake[n] << endl;
									cout << "\n";
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "Solution number is: " << count << endl;

	return 0;
}
*/
int main() {
    int d,h,p,t, a[4];
    for(d = 1; d <= 4; d++) {
        for(h = 1; h <= 4; h++) {
              for(p = 1; p <= 4; p++) {
                for(t = 1; t <= 4; t++) {              
                     if((d != h && d! = p && d != t && h != p && h != t && p != t)
                          &&((d == 3) + (h == 1) + (p == 2) + (t == 4) == 1)
                          &&((d == 2) + (h == 4) + (p == 3) + (t == 1) == 1)
                          &&((h == 3) + (t == 4) == 1)
                          &&((d ==1 ) + (h == 3) + (p == 4) + (t == 2) == 1)
                          &&((d + h + p + t) == 10)) {
                        cout << d << endl << h << endl << p << endl << t<< endl;
                    }           
                }
            }
        }
    }
    return 0;    
}