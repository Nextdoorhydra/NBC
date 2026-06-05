#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;
    list<string> rank;
    map<string, list<string>::iterator> cache;

    for (auto& s : players)
    {
        rank.push_back(s);
        cache[s] = prev(rank.end());
    }

    for (auto& c : callings)
    {
        list<string>::iterator iter;

        iter = cache[c];

        auto 허접 = prev(iter);
        auto 넣을거 = *iter;

        cache[넣을거] = rank.insert(허접, 넣을거);
        rank.erase(iter);
    }

    for (auto& s : rank)
    {
        answer.push_back(s);
    }

    return answer;
}