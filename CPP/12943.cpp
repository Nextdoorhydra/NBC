#include <string>
#include <vector>

using namespace std;

int solution(int num)
{
    long long n = num;

    if (num == 1)
        return 0;

    int answer = 0;
    auto IsEven = [](long long num) { return num % 2 == 0; };

     while (n != 1)
     {
         if(IsEven(n))
         {
             n /= 2;
         }
         else
         {
             n = n * 3 + 1;
         }

         answer++;

         if (answer == 500)
             return -1;
     }

    return answer;
}