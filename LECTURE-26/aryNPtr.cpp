#include <bits/stdc++.h>
using namespace std;
// Concept: Arrays And the Pointers together
int main()
{
    int a[100] = {2, 3, 11, 100};

    for (int i = 0; i < 4; i++)
    {
        cout << *(a + i) << endl;
    }

    // other way of writing the array pointer
    for (int i=0 ;i<4 ;i++){
        cout<<a[i]<<" "; 

    }
    cout<<endl;
    for (int i=0 ;i<4 ;i++){
        cout<<i[a]<<" ";
    }
    cout<<endl;
    return 0;
}