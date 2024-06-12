// date -06 December 2023 (Convert the temperaure  )
#include <bits/stdc++.h>
using namespace std;
double ToKelvin(int temp)
{
    return (temp + (273.00));
}

double ToFahreinheit(int temp)
{
    return (temp * (1.80) + (32.00));
}

int main()
{
    int celciusTemp;
    cin >> celciusTemp;

    cout << "The temperature in the kevlin is -> " << ToKelvin(celciusTemp)<<"K" << endl;
    cout << "The temperature in the fahrehiet is ->  " << ToFahreinheit(celciusTemp)<<"F" << endl;
    return 0;
}

/*
Convert the temperaure

Leetcode : https://leetcode.com/problems/convert-the-temperature/description/ (done)
codestudio :
gfg : https://www.geeksforgeeks.org/problems/celsius-to-fahrenheit-conversion5212/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article(done)
interview bit :


*/
