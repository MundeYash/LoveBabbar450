

#include <bits/stdc++.h>
using namespace std;

//  Permutation of vector    :   given a string , we need to generate all the possible permutation of string using the recursion 
// time : O(n! * n ) , O(N)
  void solve(vector<int>nums , vector<int>&ds  , int freq[] ,    vector<vector<int>> & ans  ){
        // base case 
        int n =nums.size() ;
        if (ds.size() == nums.size() ){
            ans.push_back(ds) ;
            return ;
           
        }

        // recursive case 
        for (int j=0 ; j<n ; j++){
            
           if (!freq[j]){// means it currenct value is unmarked 
           ds.push_back(nums[j]) ;
           freq[j] = 1; // maked the current value 
           solve(nums , ds , freq, ans ) ; 

           // backtracking 
           freq[j]=0 ; // again unmarked it 
           ds.pop_back();



           }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size() ; 
        vector<vector<int >> ans  ; 
        if (n==0 || n==1 ) {
            ans.push_back(nums) ; 
            return ans ; 
        }
       
        // using a data structure for update of integers included in answer of permutaion 
        int freq[n] = {0} ;// map 
        vector<int> ds ; 
        solve(nums , ds , freq , ans );

        return ans ;
        
    }
void print(vector<vector<int>> ans, int n)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

   vector<int> a = {1,2,3} ;
    int n = a.size();

    vector<vector<int>> ans = permute(a);

    print(ans, ans.size());

    return 0;
}
//https://www.codingninjas.com/studio/problems/permutations-of-a-string_1172219    (done )
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1 (done )
/*
https://practice.geeksforgeeks.org/problems/permutations-and-sum3001/1
https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1  (done )


https://www.codingninjas.com/studio/problems/permutations-of-a-string_985254  (done )
*/

