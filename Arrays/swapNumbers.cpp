#include <bits/stdc++.h>
using namespace std;
// Implement the function for swapping two numbers : 3 ways (using extra bucket , using + and - , using Xor operation )
void way1(int &a, int &b)
{
    // method 1  :using the extra variable

    int temp = a;
    a = b;
    b = temp;

    return;
}

// method2 : using + and - operation
void way2(int &a, int &b)
{
    // method 2 : using addition and subtraction
    a = max(a, b);
    b = min(a, b);

    // step1 :
    a = a + b;
    b = a - b;
    a = a - b;
}

// method 3 : using the xor operation

void way3(int &a, int &b)
{
    // using the xor swap algo

    // xor three times (a^b)
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main()
{
    int a = 10, b = 5;
    cout << "a->" << a << ",b->" << b << endl;
    // way1(a, b);
    // way2(a, b);
    way3(a, b);

    cout << "a->" << a << ",b->" << b << endl;
    return 0;
}
/*
gfg: https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1 (done)
code studio : https://www.codingninjas.com/studio/problems/swap-two-numbers_1112577?leftPanelTabValue=SUBMISSION (done)
*/