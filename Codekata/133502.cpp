#include <stdio.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    // bread - vegi - meat - bread

    // -----init-------
    int answer = 0, i1 = 0, i2 = 0, i3 = 0;
    stack<int>stand;

    // -----process-----
    for (int i = 0; i < ingredient.size(); i++) {
        if (stand.size() > 2 && ingredient[i] == 1) {
            i3 = stand.top();
            stand.pop();

            i2 = stand.top();
            stand.pop();

            i1 = stand.top();
            stand.pop();

            if (i3 == i2 + 1 && i2 == i1 + 1) {
                answer++;
                continue;
            }
            else {
                stand.push(i1);
                stand.push(i2);
                stand.push(i3);
            }
        }

        stand.push(ingredient[i]);
    }

    return answer;
}

int main(void) {
    vector<int> a = { 1, 2, 3, 1 };
    printf("%d", solution(a));
    return 0;
}