#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;
    vector<long long> v;
    string str = "";

    while(n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    
    sort(v.begin(), v.end(), greater<long long>());

    for(auto i : v)
        str += to_string(i);

    answer = stoll(str);

    return answer;
};