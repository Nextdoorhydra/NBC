#include <string>
#include <vector>

using namespace std;

string solution(string phone_number)
{
    string answer = "";
    int cnt = 0;
    
    for (const auto& c : phone_number)
    {
        cnt++;

        answer.push_back(cnt <= phone_number.size() - 4 ? '*' : c);
    }

    return answer;
}