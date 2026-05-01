#include <iostream>
#include <memory>

struct B_Solved;

struct A_Solved {
    std::shared_ptr<B_Solved> b_ptr;
    A_Solved() { std::cout << "A_Solved 생성\n"; }
    ~A_Solved() { std::cout << "A_Solved 소멸\n"; }
};

struct B_Solved {
    // shared_ptr 대신 weak_ptr을 사용하여 순환 참조 방지
    std::weak_ptr<A_Solved> a_ptr;

    B_Solved() { std::cout << "B_Solved 생성\n"; }
    ~B_Solved() { std::cout << "B_Solved 소멸\n"; }

    void useA() {
        // weak_ptr 사용 전 lock()으로 객체 생존 여부 확인
        if (std::shared_ptr<A_Solved> shared_a = a_ptr.lock()) {
            std::cout << "A 객체 접근 성공. 현재 A 참조 카운트: " << shared_a.use_count() << "\n";
        }
        else {
            std::cout << "A 객체가 이미 소멸되었습니다.\n";
        }
    }
};

int main() {
    {
        std::shared_ptr<A_Solved> a = std::make_shared<A_Solved>();
        std::shared_ptr<B_Solved> b = std::make_shared<B_Solved>();

        a->b_ptr = b;
        b->a_ptr = a; // weak_ptr이므로 a의 참조 카운트를 증가시키지 않음

        std::cout << "연결 후 a 참조 카운트: " << a.use_count() << "\n"; // 1 유지

        b->useA(); // lock() 성공
    }
    // 스코프 종료:
    // 1. a가 파괴되면서 A 객체의 카운트가 0이 되어 A 객체 소멸.
    // 2. A가 소멸되면서 내부의 b_ptr(shared_ptr)도 파괴되어 B 객체의 카운트가 0이 됨. B 객체 소멸.
    // 정상적으로 모든 메모리가 해제됨.

    std::cout << "스코프 종료됨 (정상 소멸)\n";
    return 0;
}