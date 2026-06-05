#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string buf = "";
    vector<int> v;

    for (char c : s + ' ')
    {
        if (c == ' ')
        {
            v.push_back(stoi(buf));
            buf.clear();
        }
        else
            buf.push_back(c);
    }

    sort(v.begin(), v.end());

    return to_string(v[0]) + ' ' + to_string(v[v.size() - 1]);
}