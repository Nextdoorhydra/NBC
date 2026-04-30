#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    float n1 = num1;
    int answer = n1 / num2 * 1'000;
    return answer;
}