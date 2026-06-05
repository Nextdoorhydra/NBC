#include <string>
#include <cmath>
#include <vector>
#include <limits.h>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int max_width = INT_MIN;
    int max_height = INT_MIN;

    for (auto& s : sizes)
    {
        int w, h;

        if (s[0] > s[1])
        {
            w = s[0];
            h = s[1];
        }
        else
        {
            w = s[1];
            h = s[0];
        }

        max_width = max(w, max_width);
        max_height = max(h, max_height);
    }

    return max_width * max_height;
}