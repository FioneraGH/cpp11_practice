#include "test.h"
#include "TypeClass.h"
#include <iostream>
using namespace std;
using namespace type_class;

int main(int argc, char* argv[]) {
    if(argc > 1) {
        cout << argc << ":" << (argv[1]) << endl;
    }
    cout << &main << ":" << (*main) << endl;

    int i = 4;
    int& aliasI = i;
    int* p = &i;
    void* px = nullptr;
    string body = "hello";
    int* pz = new int;
    cout << pz << endl;
    cout << body << ":" << body.length() << R"(:hello \n world)"  << endl;
    cout << px << ":" << (px != nullptr)  << endl;
    cout << p << ":" << (*p) << ":" << sizeof(int*) << endl;
    cout << aliasI << endl;
    cout << &aliasI << endl;
    cout << test_namespace::PlusNum(3, (*p)) << endl;

    cout << "======= split line =======" << endl;
    test();
    return 0;
}
