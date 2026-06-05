#include <string>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    set<int> answer;
    vector<int> combination(numbers.size(), 0);

    combination[combination.size() - 1] = 1;
    combination[combination.size() - 2] = 1;

    sort(numbers.begin(), numbers.end());

    do
    {
        int num = 0;

        for (int i = 0; i < combination.size(); i++)
        {
            if (combination[i])
            {
                num += numbers[i];
            }
        }


        answer.insert(num);
    } while (next_permutation(combination.begin(), combination.end()));

    vector<int> ans;

    for (auto& i : answer)
    {
        ans.push_back(i);
    }

    sort(ans.begin(), ans.end());

    return ans;
}