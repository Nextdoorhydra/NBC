#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    auto getRank = [](int number_of_corretion) -> int {
        return number_of_corretion < 1 ? 6 : 7 - number_of_corretion;
        };

    int correction = 0;
    int doodle = 0;

    for (int num : lottos)
    {
        if (num == 0)
            doodle++;
        else if (find(win_nums.begin(), win_nums.end(), num) != win_nums.end())
            correction++;
    }

    return { getRank(correction + doodle), getRank(correction) };
}