/********************************          THE WEAKEST WALL            ****************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

/*  Here the ans_chk function which return int  */
int ans_chk(vector<ll>v,ll chk,int n,int k){
    int count=0,flag=0;
    ll sum=0,i;
    /*  starting a for loop  */
    for(i=0;i<n;i++)
    {
    /*  if on adding v[i],check where sum exceed chk or not  */
        if(sum+v[i]<=chk)
        {
            sum+=v[i];
        }
        else
        {
            count++;  /*  if exceed then increment the count and set sum equal to v[i]  */
            sum=v[i];
        }
    }
    /*  if count is stricktly less than k then  */
    if(count<k)
        flag=1;
    return flag;  
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int k,n;
    /*  Take input of wall length and numbers of bricks  */
    cin>>k>>n;
    vector<ll>v;
    ll i,t,sum=0;
    for(i=0;i<n;i++)
    {
    /*  Take input of strength of bricks and push it into a vector  */
        cin>>t;
        v.push_back(t);
        /*   adding strength of all bricks   */
        sum+=v[i];
    }
    ll answer,fst,chk;
    fst=*max_element(v.begin(),v.end());
    /*  starting a while loop which runs untill fst become strictly greater than sum  */
    while(fst<=sum){
        chk=(fst+sum)/2;
        if(ans_chk(v,chk,n,k))  /*  call the ans_chk function by passing 4 argumnets  */
        {
            answer=chk;  /*  make answer equal to chk  */
            sum=chk-1;  /*  assign the sum by chk-1;  */
        }
        else
            fst=chk+1;  
    }
    cout<<answer<<endl;  /*  print the answer on screen  */
    return 0;
}

