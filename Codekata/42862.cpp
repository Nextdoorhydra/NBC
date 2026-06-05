#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    vector<int> students = vector(n, 1);

    for (int l : lost)
        students[l - 1]--;

    for (int r : reserve)
        students[r - 1]++;

    if (students[0] == 0 && students[1] == 2)
    {
        students[0]++;
        students[1]--;
    }

    if (students[students.size() - 1] == 0 && students[students.size() - 2] == 2)
    {
        students[students.size() - 1]++;
        students[students.size() - 2]--;
    }

    // 앞에 사람 것을 우선으로 빌림
    for (int i = 1; i < students.size() - 1; i++)
    {
        if (students[i] == 0)
        {
            if (students[i - 1] > 1)
            {
                students[i]++;
                students[i - 1]--;
            }
            else if (students[i + 1] > 1)
            {
                students[i]++;
                students[i + 1]--;
            }
        }
    }

    return count_if(students.begin(), students.end(), [](int i) { return i >= 1; });
}