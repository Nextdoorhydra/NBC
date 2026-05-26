#include <iostream>

bool isLittleEndian()
{
    int num = 1;
    // 첫 번째 바이트의 주소를 char형으로 변환하여 값 확인
    if (*(char*)&num == 1)
    {
        return true; // 리틀 엔디안
    }
    else
    {
        return false; // 빅 엔디안
    }
}

int main()
{
    if (isLittleEndian())
    {
        std::cout << "현재 시스템: Little Endian" << std::endl;
    }
    else
    {
        std::cout << "현재 시스템: Big Endian" << std::endl;
    }
    return 0;
}
