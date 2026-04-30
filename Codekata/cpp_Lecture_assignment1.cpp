#include <iostream>
using namespace std;

class HeavyObject {
public:
    HeavyObject() { cout << "객체 생성됨 (무거운 작업)\n"; }
    ~HeavyObject() { cout << "객체 소멸됨\n"; }
    void doSomething() const { cout << "작업 수행 중...\n"; }
};

// 임시 객체를 값으로 반환하는 함수
HeavyObject createObject() {
    return HeavyObject();
}

int main2() {
    cout << "[일반적인 호출]\n";
    createObject();
    // 반환된 임시 객체는 위 줄(statement)이 끝나는 즉시 소멸됨
    cout << "위 줄에서 이미 소멸되었습니다.\n\n";

    cout << "[상수 레퍼런스로 수명 연장]\n";
    const HeavyObject& ref = createObject();
    // 임시 객체가 바로 소멸하지 않고, 'ref'의 수명이 끝날 때까지 살아남음

    ref.doSomething(); // 안전하게 접근 가능

    cout << "main 함수 종료 직전...\n";
    return 0;
} // 여기서 ref가 스코프를 벗어나며 임시 객체 소멸