#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    vector<int> nums;
    map<char, int> map;

    // 전처리
    for (auto& c : Y)
    {
        if (map.find(c) == map.end())
            map[c] = 1;
        else
            map[c]++;
    }

    // 짝꿍 구하기
    for (auto& c : X)
    {
        if (map.find(c) != map.end() && map[c] > 0)
        {
            map[c]--;
            nums.push_back(c - '0');
        }
    }

    if (nums.size() == 0)
        return "-1";
    else if (all_of(nums.begin(), nums.end(), [](int i) { return i == 0; }))
        return "0";

    // 짝꿍 내림차순
    sort(nums.begin(), nums.end(), greater<int>());

    // 짝궁 to_string
    for (int n : nums)
    {
        answer += to_string(n);
    }

    return answer;
}

int main()
{
    solution("100", "123450");
    return 0;
}