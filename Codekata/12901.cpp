#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(int a, int b)
{
    string answer = "";
    int current = 4; // 0 % 7
    unordered_map<string, int> dic;
    auto makeKey = [](int a, int b) -> string {
        return to_string(a) + "-" + to_string(b);
        };

    // 1 3 5 7 8 10 12 - 31
    // 4 6 9 11 - 30
    // 2 - 29
    for (int m = 1; m <= 12; m++)
    {
        for (int d = 1; d <= 31; d++)
        {
            if (m == 2)
                if (d > 29)
                    break;
            if (m == 4 || m == 6 || m == 9 || m == 11)
                if (d > 30)
                    break;

            cout << makeKey(m, d) << ' ' << current << endl;
            dic[makeKey(m, d)] = current++;

            current %= 7;
        }
    }

    switch (dic[makeKey(a, b)])
    {
    case 0:
        answer = "MON";
        break;
    case 1:
        answer = "TUE";
        break;
    case 2:
        answer = "WED";
        break;
    case 3:
        answer = "THU";
        break;
    case 4:
        answer = "FRI";
        break;
    case 5:
        answer = "SAT";
        break;
    case 6:
        answer = "SUN";
        break;
    }

    return answer;
}

int main()
{
    solution(5, 24);

    return 0;
}