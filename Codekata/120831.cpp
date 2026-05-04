#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    n = n % 2 == 0 ? n / 2 : (n - 1) / 2;
    int answer = n * (n + 1);
    return answer;
}