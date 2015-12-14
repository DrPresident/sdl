#include <iostream>

using namespace std;

class Base{
    public:
        Base(){ baseNum = 0; }
        int getBaseNum(Base *obj){ return obj->baseNum++; }
    protected:
        int baseNum;
};

class Derived : public Base{
    public:
        Derived(){ derivedNum = 0; }
    protected:
        int derivedNum;
};

int main(){

    Derived foo;
    Derived bar;
    
    for(int i = 0; i < 5; i++)
        cout << bar.getBaseNum(&foo) << endl;

    return 0;
}


