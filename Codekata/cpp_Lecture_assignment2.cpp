#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 고객 인터페이스 (Observer 역할)
class Customer {
public:
    virtual void update(const string& status) = 0; // 순수 가상 함수
};

// 일반 고객 클래스
class RegularCustomer : public Customer {
private:
    string name;
public:
    RegularCustomer(const string& name) : name(name) {}

    void update(const string& status) {
        cout << "Regular customer " << name << " received update: " << status << endl;
    }
};

class BusinessCustomer : public Customer {
private:
    string name;
public:
    BusinessCustomer(const string& name) : name(name) {}

    void update(const string& status) {
        cout << "Business customer " << name << " received update: " << status << endl;
    }
};

// TODO: VIP 고객 클래스 (Customer를 상속받아 구현)
class VIPCustomer : public Customer {
private:
    string name;
public:
    VIPCustomer(const string& name) : name(name) {}

    void update(const string& status) {
        cout << "VIP customer " << name << " received VIP update: " << status << endl;
    }
};

// TODO: 배송 회사 클래스 (DeliveryService)
class DeliveryService {
private:
    vector<Customer*> customers;
    std::string currentStatus;
public:
    void addCustomer(Customer* customer) {
        customers.push_back(customer);
    }

    void removeCustomer(Customer* customer) {
        customers.erase(std::remove(customers.begin(), customers.end(), customer), customers.end());
    }

    void updateStatus(const std::string status) {
        currentStatus = status;
        notifyCustomers();
    }

    void notifyCustomers() const {
        for (auto c : customers) {
            c->update(currentStatus);
        }
    }
};

// Main 함수
int main() {
    DeliveryService service;

    // 고객 객체 생성
    RegularCustomer* customer1 = new RegularCustomer("Alice");
    VIPCustomer* customer2 = new VIPCustomer("Bob");
    BusinessCustomer* customer3 = new BusinessCustomer("CompanyX");

    // 고객 등록
    service.addCustomer(customer1);
    service.addCustomer(customer2);
    service.addCustomer(customer3);

    // 배송 상태 업데이트 및 알림
    cout << "Updating status: 배송 준비 중" << endl;
    service.updateStatus("배송 준비 중");

    cout << "\nUpdating status: 배송 완료" << endl;
    service.updateStatus("배송 완료");

    // 메모리 해제
    delete customer1;
    delete customer2;
    delete customer3;

    return 0;
}