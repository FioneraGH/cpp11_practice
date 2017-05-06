#ifndef __TYPE_CLASS_H__
#define __TYPE_CLASS_H__
namespace type_class {
    void test();
    class Base {
        public:
            Base();
            Base(int a);
            Base(const Base& other);
            Base& operator= (const Base& other);

            Base(Base&& other);
            Base& operator= (Base&& other);
            ~Base();

        protected:
            int getMemberB() {
                return memberB;
            }
            int deleteC(int a ,int b = 100,bool test=true);

        private:
            static const int size = 512;
            int memberA;
            int memberB;
            int* pMemberC;
    };
};

#endif
