/************************       RONNY THE SNAKE      *********************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans(int n,int count)
{
    int sum=0;
    /*  if 'n' is in a single digit then return count(total number of operations)  */
    if(n<10)
        return count;
    else
    {
    /*  again add all the digits  */
        while(n!=0)
        {
            sum+=(n%10);
            n/=10;
        }
        /*  increment the count  */
        count++;
        /*  again call the ans fun  */
        return ans(sum,count);
    }
}
int main() { 
    /*  Given integer is to large so store it as a string  */ 
    string n;
    cin >>n;
    int i,sum=0,count=0;
    /*  if already integer is in a single digit then no need to do operation */
    if(n.size()==1)
    {
        cout <<count;
        return 0;
    }
    else
    {
    /*  else doing first operation  */
    for(i=0;i<n.size();i++)
    {
        sum=sum+n[i]-'0';
    }
        count++;
    /*  checking after first operation,if not in a single digit then call the ans function  */     
        if(sum<10)
            cout <<count;
        else
            cout <<ans(sum,count);  /*  call and passing two arguments*/
    }
    return 0;
}
