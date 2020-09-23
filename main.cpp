#include <iostream>
using namespace std;

void checkCPU()
{
    union MyUnion {
        int a;
        char c;
    }test;
    test.a = 1;
    if (test.c == 1)
        cout << "little endian" << endl;
    else cout << "big endian" << endl;

    // little end
    char* cPtr = &test.c;
    long int val = *cPtr & 0xFF;
    val |= *(cPtr+1) << 8 & 0xFF00;
    val |= *(cPtr+2) << 16 & 0xFF0000;
    val |= *(cPtr+3) << 24 & 0xFF000000;
    cout << "test.a=" << test.a << endl;
    cout << "val=" << val << endl;

    // big end
    long int val_ = *(cPtr + 3) & 0xFF;
    val_ |= *(cPtr + 2) << 8 & 0xFF00;
    val_ |= *(cPtr + 1) << 16 & 0xFF0000;
    val_ |= *cPtr << 24 & 0xFF000000;
    cout << "test.a=" << test.a << endl;
    cout << "val_=" << val_ << endl;
}

int main()
{
    checkCPU();

    cout << "\n---------------------------------------------\n" << endl;
    unsigned int uiVal_1 = 0x12345678;
    char cc[4] = { 0 };
    memcpy(&cc[0], &uiVal_1, sizeof(cc));
    cout << "cc[0] & 0xFF : " << (cc[0] & 0xFF) << endl;
    cout << "cc[1] << 8 & 0xFF00 : " << (cc[1] << 8 & 0xFF00) << endl;
    cout << "cc[2] << 16 & 0xFF0000 : " << (cc[2] << 16 & 0xFF0000) << endl;
    cout << "cc[3] << 24 & 0xFF000000 : " << (cc[3] << 24 & 0xFF000000) << endl;
    int cc_ = cc[0] & 0xFF;
    cc_ |= cc[1] << 8 & 0xFF00;
    cc_ |= cc[2] << 16 & 0xFF0000;
    cc_ |= cc[3] << 24 & 0xFF000000;
    cout << "uiVal_1=" << uiVal_1 << endl;
    cout << "cc_=" << cc_ << endl;


    char* c = (char*)&uiVal_1;
    for (int i = 0; i < sizeof(uiVal_1); i++)
    {
        printf("%x \t %x \n", (c + i), *(c + i));
    }

    return 0;
}
