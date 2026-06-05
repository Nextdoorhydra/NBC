#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (const auto& c : commands)
    {
        auto sep = vector<int>(array.begin() + c[0] - 1, array.begin() + c[1]);
        sort(sep.begin(), sep.end());

        answer.push_back(sep[c[2] - 1]);
    }

    return answer;
}

int main()
{
    solution({ 1,5,2,6,3,7,4 }, { {2,5,3} ,{4,4,1} ,{1,7,3} });
    return 0;
}