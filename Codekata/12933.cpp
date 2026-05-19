#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;
    vector<long long> v;

    while(n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    
    sort(v.begin(), v.end(), greater<long long>());

    return answer;
}