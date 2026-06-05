#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> number)
{
    int answer = 0;

    vector<int> trio(number.size(), 0);
    trio[number.size() - 3] = 1;
    trio[number.size() - 2] = 1;
    trio[number.size() - 1] = 1;

    do
    {
        int sum = 0;

        for (int i = 0; i < trio.size(); i++)
        {
            if (trio[i] == 1)
            {
                sum += number[i];
            }
        }

        if (sum == 0)
            answer++;
    } while (next_permutation(trio.begin(), trio.end()));

    return answer;
}