#include <bits/stdc++.h>
using namespace std;
int length(vector<char> ch)
{
    int count = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}


// Approach 1 for checking  Whether a string  is Palindrome or not 
 //Approach 1 : find reverse of string and than compare 
 string reverse(string s)
{
    int st=0 , e=s.size()-1 ;
    while (st<=e ){
     swap(s[st] ,s [e]) ; 
     st++ ; 
     e--;
    }
    return s ;
    
}

bool Approach1Palindrome(string s){
    string x = reverse(s) ;
    int n = s.size();
    for (int i=0 ;i<n  ; i++){
        if (s[i]!= x[i]){
            return false ;
        }
    }
    return true ;

}


// function for checking  a string is palindrome or not
bool checkPalindrome(char ch[])
{
    vector<char> ans;

    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] >= 'A' and ch[i] <= 'Z')
        {
            // convert to lower case
            char temp = ch[i] - 'A' + 'a';
            ans.push_back(temp);
        }
        else if (ch[i] >= 'a' and ch[i] <= 'z')
        {
            ans.push_back(ch[i]);
        }
        else if (ch[i] >= '1' and ch[i] <= '9')
        {
            ans.push_back(ch[i]);
        }
    }
    cout << ch << endl;

    cout << "Printing the Answer thing:";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    cout << endl;

    int s = 0, e = ans.size() - 1;
    while (s <= e)
    {
        cout<<ans[s]<<"->"<<ans[e]<<endl;
        if (ans[s] != ans[e])
        {
            return false;
        }
        s++;
        e--;
    }

    return true;
}
int main()
{

// this is approach 1 implementation 
string s = "noawon";
cout<<Approach1Palindrome(s)<<endl;


    // this is approach 2 implementation
    // char ch[] = "$1Go22Og1#";
    // cout << checkPalindrome(ch) << endl;
    return 0;
}