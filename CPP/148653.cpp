#include <cmath>
#include <string>
#include <vector>

using namespace std;

// condition 1 < story <= 100,000,000
int solution(int storey) {
    int answer = INT_MAX;
    int direction = -1;
    vector<int> step = { 1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000 };
    vector<int> stack;

    stack.push_back(storey);

    while (!stack.empty()) {
        int cnt = 0;
        int currentStorey = stack.back();
        stack.pop_back();

        for (int i = step.size() - 1; i >= 0; --i) {
            if (currentStorey < step[i])
                continue;
            answer += currentStorey / step[i];
            int nextStorey = currentStorey % step[i];
            if (i != 0) stack.push_back(abs(nextStorey - step[i]));

            currentStorey = nextStorey;

            cnt++;
            printf("%d %d\n", currentStorey, answer);
        }

        answer = min(answer, currentStorey);
    }

    return answer;
}

int main() {
    int storey = 153;
    printf("%d\n", storey);
    int result = solution(storey);

    printf("%d", result);

    return 0;
}