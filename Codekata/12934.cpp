#include <string>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

long long solution(long long n)
{   
    double sqrrt_n = sqrt(n);

    if(abs(sqrrt_n - round(sqrrt_n)) > numeric_limits<double>::epsilon())
        return -1;
    else
    {
        return (sqrrt_n + 1) * (sqrrt_n + 1);
    }
}