#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d)
{
    long long answer = 0;
    long long llk = k, lld = d;

    auto getC = [=](long long x) -> long long {
        return floor(sqrt(lld * lld - x * x));
        };

    for (long long r = 0; r <= lld; r += llk)
    {
        answer += getC(r) / llk + 1;
    }

    return answer;
}