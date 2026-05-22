#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    queue<pair<int, int>> q;

    int moves[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    auto IsValid = [&](int y, int x) -> bool
    {
        return y >= 0 && y < maps.size() && x >= 0 && x < maps[0].size() && !visited[y][x];
    };

    for(int y = 0; y < maps.size(); y++)
    {
        for(int x = 0; x < maps[0].size(); x++)
        {
            if (visited[y][x] || maps[y][x] == 'X') continue;

            q.push({ y, x });

            visited[y][x] = true;
            int cost = maps[y][x] - '0';

            while (!q.empty())
            {
                pair<int, int> current = q.front();
                q.pop();

                for (auto& move : moves)
                {
                    int dy = current.first + move[0];
                    int dx = current.second + move[1];

                    if (IsValid(dy, dx) && maps[dy][dx] != 'X')
                    {
                        cost += maps[dy][dx] - '0';
                        visited[dy][dx] = true;
                        q.push({ dy, dx });
                    }
                }
            }

            answer.push_back(cost);
        }
    }

    if (answer.size() == 0) answer.push_back(-1);

    sort(answer.begin(), answer.end(), less<int>());

    return answer;
}

int main()
{
    vector<string> maps = { "X591X", "X1X5X", "X231X", "1XXX1" };
    vector<int> result = solution(maps);
    for (int cost : result)
    {
        printf("%d ", cost);
    }
    return 0;
}