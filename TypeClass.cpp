#include <iostream>
#include <cstring>
#include "TypeClass.h"
using namespace std;

namespace type_class {

    Base::Base() : memberA(0), memberB(100), pMemberC(new int[size]) {
        cout << "In default constructor" << endl;
    }

    Base::Base(int a) : memberA{a}, memberB{100}, pMemberC{new int[Base::size]} {
        cout << "In normal constructor" << endl;
    }

    Base::Base(const Base& other) : memberA{other.memberA},memberB{other.memberB},pMemberC{nullptr}{
        cout << "In copy constructor" << endl;
        if (other.pMemberC != nullptr) {
            pMemberC = new int[size];
            memcpy(pMemberC,other.pMemberC,size);
        }
    }

    Base& Base::operator=(const Base& other) {
        this->memberA = other.memberA;
        (*this).memberB = other.memberB;
        if (pMemberC != nullptr) {
            delete[] pMemberC;
            pMemberC = nullptr;
        }
        if (other.pMemberC != nullptr) {
            pMemberC = new int[size];
            memcpy(pMemberC, other.pMemberC, size);
        }
        return *this;
    }

    Base::Base(Base&& other) : memberA(other.memberA), memberB(other.memberB), pMemberC(other.pMemberC) {
        cout << "In move constructor" << endl;
        other.pMemberC = nullptr;
    }

    Base& Base::operator=(Base&& other) {
        memberA = other.memberA;
        memberB = other.memberB;
        if (pMemberC != nullptr) {
            delete[] pMemberC;
            pMemberC = nullptr;
        }
        pMemberC = other.pMemberC;
        other.pMemberC = nullptr;
    }

    Base::~Base() {
        cout << "In destructor" << endl;
        if (pMemberC != nullptr) {
            delete[] pMemberC;
            pMemberC = nullptr;
        }
    }

    Base getTemporyBase() {
        Base tmp;
        return tmp;
    }

    void test() {
        Base&& a = getTemporyBase();
    }
}
