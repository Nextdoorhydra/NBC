#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;

    vector<int> wall(n + 1, 1);

    for (int i : section)
    {
        wall[i] = 0;
    }

    for (int i = 1; i < wall.size(); i++)
    {
        if (wall[i] == 0)
        {
            for (int j = i; j < i + m && j < wall.size(); j++)
            {
                wall[j]++;
            }

            answer++;
        }
    }

    return answer;
}