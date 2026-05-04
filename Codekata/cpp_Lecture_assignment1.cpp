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
 
    return 0;
}