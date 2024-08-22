
#include <bits/stdc++.h>
using namespace std;

//  Permutation of String    :   given a string , we need to generate all the possible permutation of string using the recursion 
  void solve(string nums , int index ,    set<string> &ans  ){
        // base case 
        int n =nums.size() ;
        if (index >= n ){
            ans.insert(nums) ;
            return ;
           
        }

        // recursive case 
        for (int j=index ; j<n ; j++){
            swap(nums[index] , nums[j]) ; 
            solve(nums , index +1   , ans ) ;

            // backtracking 
            swap(nums[index], nums[j]) ; // just like removing the answer popback
        }
    }

vector<string> Permutation(string  nums) 
{
	 set < string > ans;
    //   recurPermute(0, nums, ans);
		solve(nums,  0, ans) ;
	  vector<string> finalAns(ans.begin() , ans.end()) ;
      return finalAns;
}
void print(vector<string> ans, int n)
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

  string a = "ABC";
    int n = a.size();

    vector<string> ans = Permutation(a);

    print(ans, ans.size());

    return 0;
}
