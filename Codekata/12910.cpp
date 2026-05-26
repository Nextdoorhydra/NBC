#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;

    for (const auto& n : arr)
    {
        if (n % divisor == 0)
            answer.push_back(n);
    }

    if (answer.empty())
        return { -1 };

    std::sort(answer.begin(), answer.end(), less<int>());

    return answer;
}