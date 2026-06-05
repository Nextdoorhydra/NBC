#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n)
{
    sort(strings.begin(), strings.end(), [&n](const string& s1, const string& s2) -> bool {
        char c1 = s1[n];
        char c2 = s2[n];

        if (c1 == c2)
        {
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] == s2[i])
                    continue;
                else
                    return s1[i] < s2[i];
            }
        }

        return c1 < c2;
        });

    return strings;
}