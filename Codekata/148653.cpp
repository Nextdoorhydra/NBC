#include <cmath>
#include <string>
#include <vector>

using namespace std;
vector<int> step = { 1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000 };

int dp(int start, int storey, int val = 0) {
    if (start < 0)
        return 0;

    val += storey / step[start];

    int nextStorey = storey % step[start];
    int nextStorey2 = abs(nextStorey - step[start]);

    val += min(dp(start - 1, nextStorey), dp(start - 1, nextStorey2, 1));

    return val;
}

int solution(int storey) {
    int answer = 0;
    int start = -1;
    int direction = -1;
    
    for (int i = step.size() - 1; i >= 0; --i) {
        if (storey < step[i])
            continue;
        start = i + 1;
        break;
    }

    answer = dp(start, storey);

    return answer;
}

int main() {
    int storey = 6;
    printf("%d\n", storey);
    int result = solution(storey);

    printf("%d", result);

    return 0;
}