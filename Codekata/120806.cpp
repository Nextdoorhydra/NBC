#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    float n1 = num1;
    float n2 = n1 / num2;
    int n3 = (int)(n2 * 1'000);
    return n3;
}