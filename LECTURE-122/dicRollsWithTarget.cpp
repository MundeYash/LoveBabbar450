
// Given n number of dices with m faces (means 1 to  m )can appear on the dice , return the number of distinct ways of rolling n dices with m possible to make target sum 
#include<bits/stdc++.h>
using namespace std ; 


//Simple Recursion approach // TIme : limit exceeded 

         // helper Function 
                long long solve (int dices , int faces , int targetSum ){
                    // base cases 
                    
                    if (targetSum<0 )return 0 ; //negative target value 
                    
                    if (dices == 0 and targetSum !=0 ) return 0 ; // 0 number of dices and some target value 
                    
                    if (targetSum ==0 and dices != 0 ) return 0 ; // target value is 0 while dices has some faces
                    
                    if (dices ==0 and targetSum ==0 )return 1 ; // both number of dices and target value is 0 , means do nothing on way 
                    
                    
                    long long ans =0 ; 
                    
                    for (int i=1 ;i<=faces  ; i++ ){
                        
                        ans += solve(dices-1 , faces , targetSum -i );
                        
                        
                    }
                    
                    return ans ;
                    
                    
        }
          
// Dynamic Programming approach : USE Memoization 
                long long solveMemo (int dices , int faces , int targetSum ){
                                    // base cases 
                                    
                                    if (targetSum<0 )return 0 ; //negative target value 
                                    
                                    if (dices == 0 and targetSum !=0 ) return 0 ; // 0 number of dices and some target value 
                                    
                                    if (targetSum ==0 and dices != 0 ) return 0 ; // target value is 0 while dices has some faces
                                    
                                    if (dices ==0 and targetSum ==0 )return 1 ; // both number of dices and target value is 0 , means do nothing on way 
                                    
                                    
                                    long long ans =0 ; 
                                    
                                    for (int i=1 ;i<=faces  ; i++ ){
                                        
                                        ans += solveMemo(dices-1 , faces , targetSum -i );
                                        
                                        
                                    }
                                    
                                    return ans ;
                                    
                                    
                        }



  long long noOfWays(int M , int N , int X) {
                
                // return solve(N ,M , X);


                    // two parameters are changing that means 2D dp 

                    vector<vector<int>> dp(N+1 , vector<int>(X+1 , -1 )) ;
                return solveMemo(N ,M , X);
            
            }
            // *******************************


            int main ()
            {

                int n ; 
                cout<<"Enter the number of dices"<<endl;
                cin>> n ; 

                int m ; 
                cout<<"Enter the number of faces on each dice "<<endl;
                cin>> m ; 

                int target ; 
                cout<<"Enter the target value "<<endl; 
                cin>> target ; 

                cout<<"The number of distinct possible ways to use the "<<n<<" dices which m faces are : "<<noOfWays(m , n ,target     )<<endl;
                return 0 ; 
            }



/*Question Link: 
gfg: https://practice.geeksforgeeks.org/problems/dice-throw5349/1 (done ->g,)
leetcode : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/?envType=daily-question&envId=2023-12-26 (done)
code studio : 
interview bit : 
*/