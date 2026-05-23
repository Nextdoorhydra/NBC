#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <utility>

using namespace std;

int solution(int N, vector<vector<int> > road, int K)
{
    unordered_set<int> answer;
    map<pair<int, int>, int> m;
    vector<bool> visited(N + 1, false);
    vector<vector<pair<int, int>>> adjacency(N + 1, vector<pair<int, int>>());
    auto comp = [](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);

    for (auto& r : road)
    {
        auto pos1 = make_pair(r[0], r[1]);
        auto pos2 = make_pair(r[1], r[0]);

        if (m.find(pos1) == m.end()) m[pos1] = 10001;
        if (m.find(pos2) == m.end()) m[pos2] = 10001;

        m[pos1] = min(m[pos1], r[2]);
        m[pos2] = min(m[pos2], r[2]);

        adjacency[r[0]].push_back(pos2);
        adjacency[r[1]].push_back(pos1);
    }

    q.push({1, 0});

    while (!q.empty())
    {
        auto current = q.top();
        q.pop();
        answer.insert(current.first);

        visited[current.first] = true;

        for(auto& next : adjacency[current.first])
        {
            int nextCost = current.second + m[{current.first, next.first}];
            if (visited[next.first] || nextCost > K) continue;
            q.push({ next.first, nextCost });
        }
    }

    return answer.size();
}

int main()
{
    int N = 5;
    vector<vector<int> > road = { {1, 2, 1}, {2, 3, 1} };
    int K = 3;
    cout << solution(N, road, K) << endl;
    return 0;
}