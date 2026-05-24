#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul)
{
    string prefix = "김서방은 ";
    string suffix = "에 있다";

    int i = 0;

    for (const auto& human : seoul)
    {
        if (human == "Kim")
        {
            return prefix + to_string(i) + suffix;
        }
        i++;
    }

    return "";
}
