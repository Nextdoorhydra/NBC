#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";
    int cnt = 0;

    while (n-- > 0)
    {
        auto s = cnt++ % 2 == 0 ? "수" : "박";
        answer += s;
    }

    return answer;
}