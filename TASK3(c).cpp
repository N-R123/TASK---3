/********************************            THE STRONGEST WALL               ***********************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

/*  Here the check function to check whether sum is answer or not,if yes return 1 else return 0  */
int check(vector<ll>vec,ll m,ll sum)
{
/*  if sum found 0 then return 1  */
    if(sum==0)
        return 1;
    else
    {
    /*  if sum becomes negative then return 0  */
        if(sum<0)
        return 0;
        else
        {
            for(ll i=m-1;i>=0;i--)
            {
            if(check(vec,i,sum-vec[i]))  /*  else again call the check function,if found then return 1 */
                return 1;
            }
        }
    }
        return 0;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll n,m,i,t,sum=0,ans,flag=0;
    /*  take input of wall length and number of bricks  */
    cin>>n>>m;
    vector<ll> vec;
    for(i=0;i<m;i++)
    {
    /*  take input of strength of M bricks  */
        cin>>t;
        /*  and push strength of bricks in a vector  */ 
        vec.push_back(t);
        /*  adding strength of all the bricks  */
        sum+=vec[i];
    }
    /*  if we require the wall of unit 1  */
    if(n==1)
    {
        cout<<sum;
    }
    else
    {
    /*  sort the vector in ascending order  */
    sort(vec.begin(),vec.end());
    sum/=2;  /*  half the sum of strengths  */
    ans=sum+1;  
    /*  run the while loop untill flag!=0  */
    while(flag==0)
    { 
        ans--;  /*  decrement the ans and check  */ 
        sum=ans;
        flag=check(vec,m,sum);  /*  call the check function by passing three arguments  */
    }
    cout<<ans;  /*  print the ans on the screen  */
    }
    return 0;
}
