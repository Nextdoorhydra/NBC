#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    vector<int> answer;
    // vector<vector<int>> map = vector(wallpaper.size(), vector(wallpaper[0].size(), 0));
    int minLeft = INT_MAX;
    int minUp = INT_MAX;
    int maxRight = INT_MIN;
    int maxDown = INT_MIN;

    for (int r = 0; r < wallpaper.size(); r++)
    {
        for (int c = 0; c < wallpaper[0].size(); c++)
        {
            if (wallpaper[r][c] == '#')
            {
                minLeft = min(minLeft, c);
                minUp = min(minUp, r);
                maxRight = max(maxRight, c);
                maxDown = max(maxDown, r);
            }
        }
    }

    return { minUp, minLeft, maxDown + 1, maxRight + 1 };
}