#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    bool isMakable = true;

    for (int i = 0, j = 0, k = 0; i < goal.size(); i++)
    {
        if (j < cards1.size() && goal[i] == cards1[j])
        {
            j++;
        }
        else if (k < cards2.size() && goal[i] == cards2[k])
        {
            k++;
        }
        else
        {
            isMakable = false;
            break;
        }
    }

    return isMakable ? "Yes" : "No";
}