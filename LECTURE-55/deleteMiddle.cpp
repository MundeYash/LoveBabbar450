//Delete the middle element in the stack , if more than one middle exists in cases of even size delete the first one 


#include<bits/stdc++.h>
using namespace std  ; 

void print(stack<int> s){
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

// helper function for deleting middle element 
void solve(stack<int>&s , int &count , int n  ){
    // base case 
    if (count == (n/2)){
        // means this element to be deleted 
        s.pop();
        return ;
    }

    //recursive 
    int num = s.top();
    s.pop();
    count ++;
    solve(s,count  , n);
    // after coming back 
    s.push(num);


}
void deleteMiddle(stack<int>&s , int n ){
    // concept : Recursion 
    int count =0 ;

    solve(s,count , n );
    return ;

}

int main (){
    stack<int>s ;
    vector<int> arr = {1,2,3,4,5,6}; 
    int n = arr.size();

    // inserting elements in the stack 
    for (int i=0 ;i<n ;i++ ){
        s.push(arr[i]);
    } 
    print(s);

    // after deleting the middle element 
    deleteMiddle(s,n);

    print(s);



    return 0 ;
}
/*
Links : 
gfg : https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1 (done)
codestudio : https://www.codingninjas.com/studio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio (done)

interview BIt ;
Leetcode:




// similiar question must try and practice 
https://www.geeksforgeeks.org/problems/special-stack/1      (done)

*/