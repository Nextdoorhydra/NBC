#include <iostream>
#include <utility> // std::move, std::swap

class MemoryBlock
{
private:
    int* data;
    size_t size;

public:
    // 1. 기본 생성자
    MemoryBlock(size_t s = 0) : size(s), data(s ? new int[s]() : nullptr)
    {
        std::cout << "기본 생성자 호출\n";
    }

    // 2. 소멸자
    ~MemoryBlock()
    {
        delete[] data;
        std::cout << "소멸자 호출\n";
    }

    // 3. 복사 생성자 (원본 보존, 깊은 복사)
    MemoryBlock(const MemoryBlock& other) : size(other.size), data(new int[other.size])
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
        std::cout << "복사 생성자 호출 (Deep Copy)\n";
    }

    // 4. 이동 생성자 (소유권 이전, 얕은 복사 후 원본 초기화)
    // noexcept: 이동 중에는 예외가 발생하지 않음을 컴파일러에 보증 (STL 최적화에 필수)
    // 만약 예외 나면 자비없이 std::terminate()의 대가를 치른다 ㄷㄷ
    MemoryBlock(MemoryBlock&& other) noexcept : size(other.size), data(other.data)
    {
        other.size = 0;
        other.data = nullptr; // 원본의 포인터를 끊어 이중 해제 방지
        std::cout << "이동 생성자 호출 (Move)\n";
    }

    // 5. 복사 대입 연산자 (기존 자원 버리고, 깊은 복사)
    MemoryBlock& operator=(const MemoryBlock& other)
    {
        if (this != &other)
        { // 자기 자신에 대한 대입 방지 (A = A;)
            delete[] data;    // 내 기존 자원 버리기

            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
            std::cout << "복사 대입 연산자 호출\n";
        }
        return *this;
    }

    // 6. 이동 대입 연산자 (기존 자원 버리고, 소유권 뺏어오기)
    MemoryBlock& operator=(MemoryBlock&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;     // 1. 내 기존 자원 버리기

            data = other.data; // 2. 자원 가로채기
            size = other.size;

            other.data = nullptr; // 3. 원본 무력화
            other.size = 0;
            std::cout << "이동 대입 연산자 호출\n";
        }
        return *this;
    }
};

int main()
{
    MemoryBlock mb = MemoryBlock(); // 기본 생성자 호출
    MemoryBlock mb2 = MemoryBlock(mb); // 복사 생성자 호출 - 원본 유지 깊은 복사
    MemoryBlock mb3 = std::move(mb2); // 이동 생성자 호출 - 소유권 이전
    mb3 = mb; // 복사 대입 생성자 호출 - 기존 자원 제거 + 원본 유지 깊은복사
    mb3 = std::move(mb); // 이동 대입 생성자 호출 - 기존 자원 제거 + 소유권 이전

    return 0;
}