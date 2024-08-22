#include<bits/stdc++.h>
using namespace std ; 
int power2NUms (int a ,int b ){// a^b 
int ans =1 ; 

for (int i=1 ;i<=b ;i++){
    ans *= a ;

}
 return ans ;

}

int main (){
    // find power of two number using the function 
    int x ,  n ; 
    cin>>x>> n ;
   cout<<"power of "<<x<<" to "<<n<<" is: "<<  power2NUms(x,n)<<endl;

    return 0 ; 
}