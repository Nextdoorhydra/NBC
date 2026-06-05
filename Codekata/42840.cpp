#include <string>
#include <vector>

using namespace std;

class Supoza
{
public:
    Supoza(vector<int> marks) : Marks(marks)
    {
        cnt = 0;
    }

    int GetScore(vector<int> test)
    {
        int result = 0;

        for (int t : test)
        {
            if (t == Marks[cnt])
            {
                result++;
            }

            cnt++;
            cnt %= Marks.size();
        }

        return result;
    }

private:
    vector<int> Marks;
    int cnt;
};

vector<int> solution(vector<int> answers)
{
    Supoza spz1({ 1, 2, 3, 4 ,5 }), spz2({ 2, 1, 2, 3, 2, 4, 2, 5 }), spz3({ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 });

    int r1 = spz1.GetScore(answers), r2 = spz2.GetScore(answers), r3 = spz3.GetScore(answers);

    if (r1 < r2)
    {
        if (r2 < r3)
            return { 3 };
        else if (r2 == r3)
            return { 2, 3 };
        else
            return { 2 };
    }
    else if (r1 == r2)
    {
        if (r2 < r3)
            return { 3 };
        else if (r2 == r3)
            return { 1, 2, 3 };
        else
            return { 1, 2 };
    }
    else
    {
        if (r1 < r3)
            return { 3 };
        else if (r1 == r3)
            return { 1, 3 };
        else
            return { 1 };
    }
}