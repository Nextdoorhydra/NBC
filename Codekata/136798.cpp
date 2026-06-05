#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power)
{
    int answer = 0;

    vector<int> prime;
    vector<int> numbers(100'001, 1);

    numbers[0] = 0;
    numbers[1] = 0;

    for (int i = 2; i < numbers.size(); i++)
    {
        if (numbers[i] == 0) continue;

        for (int j = i + i; j < numbers.size(); j += i)
        {
            numbers[j] = 0;
        }

        prime.push_back(i);
    }

    answer++; // 1

    for (int i = 2; i <= number; i++)
    {
        int result = 1;
        int n = i;

        for (int p : prime)
        {
            // if (p * p > i) break;

            int cnt = 0;

            while (n % p == 0)
            {
                n /= p;
                cnt++;
            }

            result *= (cnt + 1);
        }

        if (result == 1)
            answer += 2;
        else
            answer += result > limit ? power : result;
    }

    return answer;
}