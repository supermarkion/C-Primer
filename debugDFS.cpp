#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


bool isValid(const string &s) 
{
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

void dfs(string& s, vector<string>& path, vector<string> &ret, int index) 
{
    int len = s.size();
    if (path.size() == 4) 
    {
        if (index == len) 
        {
            stringstream ss;
            for (const auto &str : path)
            {
                ss << str << ".";
            }
            string sol = ss.str();
            sol.pop_back();
            ret.emplace_back(sol);
        }
        return; // find a solution
    }
    for (int i = index; i < index + 3 && i < len; i++) 
    {
        string sub = s.substr(index, i + 1 - index);
        
        if (s[index] == '0' && i != index)
        {
            break;
        }
        if (!isValid(sub)) 
        {
            continue;
        }
        cout << "substring is: " << sub  << ", index: " << index << ", i + 1 - index + 1: " << i + 1 - index << endl;
        path.emplace_back(sub);
        dfs(s, path, ret, i + 1);
        path.pop_back();
    }
}


/**
* @param s the IP string
* @return All possible valid IP addresses
*/
vector<string> restoreIpAddresses(string& s) 
{
    // Write your code here
    vector<string> ret;
    if (s.empty() || s.length() < 4)
    {
        return ret;
    }
    vector<string> path;
        
    dfs(s, path, ret, 0);
    return ret;
}

int main() {
    string s = "0000";
    vector<string> result = restoreIpAddresses(s);
    for (const auto & element : result) {
        cout << element << endl;
    }
}