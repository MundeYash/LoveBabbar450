#include <bits/stdc++.h>
using namespace std;
// String Compression : convert given string character to its frequencey and store them in new string and return
//  time :O(N^2) , space : O(1)
int compress(string &chars)
{
    int n = chars.size();
    int ansIndex = 0;
    int i = 0;
    while (i < n)
    {
        int j = (i + 1);
        while (j < n and chars[i] == chars[j])
        {
            // equal character value case
            j++;
        }

        // coming here means traversed the whole array or different character values encountered
        // old array ko store karlo
        chars[ansIndex++] = chars[i];

        int count = j - i;

        if (count > 1)
        {

            // converting the count in single digit and save it in anser

            string cnt = to_string(count);
            // iterate over the count
            for (auto ch : cnt)
            {

                chars[ansIndex++] = ch;
            }
        }

        // moving to new different character
        i = j;
    }
      string ans ; 
        for (int i=0 ;i<ansIndex ;i++){
            ans.push_back(chars[i]);
        }
        cout<<ans<<endl;
    return ansIndex;
}
// input ->"hellosirji" output->h,1,e,1,l,2,o,1,s,1,i,2,r,1,j,1
int main()
{
    string s = "aabbccccdddddeeeeeee";
    cout<<s<<endl;
    cout << "the string compression ans is " << compress(s) << endl;

    return 0;
}