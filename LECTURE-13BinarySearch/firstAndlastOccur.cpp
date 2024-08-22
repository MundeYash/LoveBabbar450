#include <iostream>
using namespace std;
// Program for finding out the first and Last Occurence in the last or array
int first_occur(int a[], int n, int key)
{
    int start = 0, end = n - 1 ,  ans =-1 ;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (key == a[mid])
        {
             ans = mid;
            // left most ke liye left aur check karlo ek bar (for confirmation )
            end = mid - 1;
           
        }
        else if (key > a[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

    }
    return ans ;
}
int last_occur(int a[], int n, int key)
{
    int start = 0, end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (key == a[mid])
        {
            ans = mid;
            // right most ke liye right aur check karlo ek bar (for confirmation )
            start = mid + 1;
          
        }
        else if (key > a[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans ;
}
int main()
{
    int a[] = {0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3};
    int n = sizeof(a) / sizeof(int);
    cout << "The first OCcurence is :" << first_occur(a, n, 0) << endl;
    cout << "the last Occurence : " << last_occur(a, n, 0) << endl;

    cout << "This is the code for the finding out the first and Last Occurence \n";
    return 0;
}
/*
first occur 
last occur 

leetcode : 
gfg : 
code studio : 
interviewbit : https://www.interviewbit.com/problems/count-element-occurence/#:~:text=Given%20a%20sorted%20array%20of%20integers%2C%20find%20the,8%2C%2010%5D%20and%20target%20value%208%2C%20return%202. (done)
*/