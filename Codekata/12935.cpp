#include <string>
#include <vector>
#include <limits.h>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer = arr; // 깊은 복사
    int min = INT_MAX;
    vector<int>::iterator pos = answer.end();

    for (auto i = answer.begin(); i != answer.end(); i++)
    {
        if (min > *i)
        {
            min = *i;
            pos = i;
        }
    }

    answer.erase(pos);

    return answer.size() == 0 ? vector<int> { -1 } : answer;
}

int main()
{
    solution(vector<int>({ 10 }));
}