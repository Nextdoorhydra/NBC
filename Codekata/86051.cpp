#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 0;
    set<int> s;

    for (auto& num : s)
    {
        s.insert(num);
    }

    for (int i = 0; i < 10; i++)
    {
        if(s.find(i) == s.end())
        {
            answer += i;
        }
    }

    return answer;
}

int main()
{
    solution({ 0, 1, 2, 3, 4 });
}