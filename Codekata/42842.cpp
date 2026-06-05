#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int r = 0, c = 0;

    for (int i = 1; i <= yellow; i++)
    {
        r = i + 2;
        c = yellow / i;

        int count = r * 2 + c * 2 + yellow % i;

        if (count == brown)
        {
            answer.push_back(c + 2);
            answer.push_back(i + 2);
            break;
        }
    }

    return answer;
}