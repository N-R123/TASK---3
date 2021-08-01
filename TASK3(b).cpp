/**************************          COLOURING THE FLAG            *********************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,i,j;
    cin >>n;  /* taking input of integer  */
    int sum=0,add=1;
    bool check;
    /*  starting from the second flag  */
    for(i=2;i<=n;i++)
    {
        check=true;
        for(j=2;j<=i/2;j++)
        {
        	/*  if flag found coprime then break  */
            if(i%j==0)
            {
                check=false;
                break;
            }
        }
        /*  if on checking found true then add  */
        if(check==1)
        {
            sum+=add;
            add++; /*  increment after each addition  */
        }
    }
    /*  print the sum of all DISTINCT values  */
    cout <<sum;
    return 0;
}
