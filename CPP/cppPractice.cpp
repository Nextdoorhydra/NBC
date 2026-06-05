#include<IOStream>
#include<string>

using namespace std;

class Parent1
{
    int a;
public:
    Parent1()
    {

    }

    virtual void a1()
    {

    }
};

class Parent2
{
public:
    Parent2()
    {

    }

    virtual void a2()
    {

    }
};


class Player : public Parent1, public Parent2
{
public:
    Player()
    {

    }

    virtual void a1() override
    {

    }
};

int main()
{
    nullptr_t npr;

    cout << sizeof(nullptr);
    cout << sizeof(void*);

    return 0;
}