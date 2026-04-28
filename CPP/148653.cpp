#include <cmath>
#include <string>
#include <vector>

using namespace std;

// condition 1 < story <= 100,000,000
int solution(int storey) {
    int answer = 0;
    int direction = -1;
    vector<int> step = { 1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000 };

    for(int i = step.size() - 1; i >= 0; --i) {
        if (storey < step[i])
            continue;
        answer += storey / step[i];
        int nextStorey = storey % step[i];

        if (abs(nextStorey - step[i]) < nextStorey) {
            storey = abs(nextStorey - step[i]);
            answer++;
        }
        else {
            storey = nextStorey;
        }

        printf("%d %d\n", storey, answer);
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