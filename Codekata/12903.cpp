#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    // 0 -> 1 / 2 = 0
    // 0 1 -> 2 / 2 = 1
    // 0 1 2 -> 3 / 2 = 1
    // 0 1 2 3 4 -> 5 / 2 = 2
    bool isEven = s.size() % 2 == 0;
    int len = s.size() / 2 - (isEven ? 1 : 0);
    return s.substr(len, isEven ? 2 : 1);
}

int main()
{
    solution("abcde");
}