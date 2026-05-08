#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void print(vector<int>answer, int n)
{
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << ' ';
        for (int k = 0; k < i + 1; k++)
        {
            cout << setfill(' ') << setw(2) << answer[idx++] << ' ';
        }
        cout << endl;
    }
}

vector<int> solution(int n)
{
    if (n == 1) return vector<int> { 1 };
    if (n == 2) return vector<int> { 1, 2, 3 };

    int num = 1;
    int size = n * (n + 1) / 2;
    vector<int> answer(size, 0);
    auto getRow = [&answer](int idx)
        {
            int row = 1, det = 1;
            while (1)
            {
                if (idx < det)
                    return row;
                else
                {
                    row++;
                    det = row * (row + 1) / 2;
                }
            }
        };

    vector<int> Rows;

    for (int i = 0; answer[i] == 0;)
    {

        for (; i < size; i += getRow(i))
        {
            if (answer[i] != 0)
            {
                break;
            }
            answer[i] = num++;
        }

        for (i = i - getRow(i) + 2; i < size; i++)
        {
            if (answer[i] != 0)
            {
                i--;
                break;
            }
            answer[i] = num++;
        }

        for (i = i - getRow(i); i > 0; i -= getRow(i))
        {
            if (answer[i] != 0)
            {
                break;
            }
            answer[i] = num++;
        }

        i += getRow(i);
        i += getRow(i);
        i++;
    }

    return answer;
}

int main()
{

    solution(3);

    return 0;
}