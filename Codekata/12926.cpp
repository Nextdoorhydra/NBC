#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    string answer = "";
    char newChar = 0;

    for (const char& c : s)
    {
        if (c == ' ')
        {
            newChar = ' ';
        }
        else if ('a' <= c && c <= 'z')
        {
            newChar = (c - 'a' + n) % 26 + 'a';
        }
        else if ('A' <= c && c <= 'Z')
        {
            newChar = (c - 'A' + n) % 26 + 'A';
        }

        answer.push_back(newChar);
    }

    return answer;
}

int main()
{
    solution("z", 1);
    return 0;
}