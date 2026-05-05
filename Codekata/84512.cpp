#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string word) {
    int idx = 1;
    std::string newString = "";
    unordered_map<std::string, int> m;

    int digit = 0;
    int chCount[]{ 0, 0, 0, 0, 0 };
    char chSet[]{ 'A', 'E', 'I', 'O', 'U' };

    auto chToIdx = [](char c) { return c == 'A' ? 0 : c == 'E' ? 1 : c == 'I' ? 2 : c == 'O' ? 3 : c == 'U' ? 4 : -1; };

    // expand - 확장 불가 지점까지 숫자 추가
    while (digit < 5) {
        newString.push_back(chSet[chCount[digit]++]);
        digit++;

        m[newString] = idx++;
    }

    digit = 4;

    // collapse - 붕괴 불가 지점까지 숫자 제거
    while (1) {
        newString.pop_back();
        newString.push_back(chSet[chCount[digit]++]);

        m[newString] = idx++;

        if (chCount[digit] == 5) {
            while (chCount[digit] == 5) {
                newString.pop_back();
                chCount[digit] = 0;
                digit--;
            }

            if (digit == -1)
                return m[word];

            newString.pop_back();
            newString.push_back(chSet[chCount[digit]++]);
            m[newString] = idx++;

            digit++;

            // expand
            while (digit < 5) {
                newString.push_back(chSet[chCount[digit]++]);
                digit++;

                m[newString] = idx++;
            }
            digit = 4;
        }
    }
}