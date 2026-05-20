#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
    bool answer = true;

    int val = x;
    int det = 0;

    while (x)
    {
        det += x % 10;
        x /= 10;
    }

    answer = val % det == 0;

    return answer;
}