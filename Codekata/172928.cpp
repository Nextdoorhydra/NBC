#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes)
{
    pair<int, int> current = make_pair(0, 0);

    for (int r = 0; r < park.size(); r++)
        for (int c = 0; c < park[0].size(); c++)
        {
            if (park[r][c] != 'S') continue;
            current = make_pair(r, c);
            goto OUT;
        }
OUT:
    auto isPassable = [=](int r, int c) {
        return 0 <= r && r < park.size() && 0 <= c && c < park[0].size();
        };

    auto doCommand = [&](const string& c) {
        char dir = c[0];
        int mv = c[2] - '0';
        pair<int, int> next;

        switch (dir)
        {
        case 'N':
            next = make_pair(current.first - mv, current.second);
            break;
        case 'S':
            next = make_pair(current.first + mv, current.second);
            break;
        case 'W':
            next = make_pair(current.first, current.second - mv);
            break;
        case 'E':
            next = make_pair(current.first, current.second + mv);
            break;
        }

        if (isPassable(next.first, next.second))
        {
            if (current.first <= next.first)
            {
                for (int r = current.first; r <= next.first; r++)
                {
                    if (park[r][current.second] == 'X') return;
                }
            }
            else
            {
                for (int r = current.first; r >= next.first; r--)
                {
                    if (park[r][current.second] == 'X') return;
                }
            }

            if (current.second <= next.second)
            {
                for (int c = current.second; c <= next.second; c++)
                {
                    if (park[current.first][c] == 'X') return;
                }
            }
            else
            {
                for (int c = current.second; c >= next.second; c--)
                {
                    if (park[current.first][c] == 'X') return;
                }
            }

            current = next;
        }
        };

    for (auto& r : routes)
    {
        doCommand(r);
    }

    return { current.first, current.second };
}

int main()
{
    solution({ "OXO", "XSX", "OXO" }, { "S 1", "E 1", "W 1", "N 1" });
    return 0;
}