#include <bits/stdc++.h>
using namespace std;
// time : O(n-> source to destination distance ) , space : O(n-> recursive stack space )

int walkingSteps(int src, int des)
{      // base case 
    if (src == des)
        return 0;
            // recursive case / recurene relation 
    return 1 + walkingSteps(src + 1, des);
}
int main()
{
    cout << "The walking distance from the source to the destination is : " << walkingSteps(2, 10) << endl;
    return 0;
}