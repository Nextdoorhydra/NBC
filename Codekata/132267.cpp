#include <string>
#include <vector>

using namespace std;

// n에서 a만큼 주면 마트가 b만큼 새로 줌
// 새로 받는 콜라병 = n/a * b
// 남은 콜라병의 수 = n/a * b + n % a
// answer = 콜라병의 수
int solution(int a, int b, int n)
{
    if (n < a) return 0;

    int coke = n / a * b;
    int remainCoke = n / a * b + n % a;

    return coke + solution(a, b, remainCoke);
}