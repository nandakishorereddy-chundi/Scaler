#include "../stdc++.h"
using namespace std;

#define ll long long

ll to_INT(string A)
{
    ll val=0;
    for(int i=0;i<A.length();i++)
    {
        val*=10;
        val+=(A[i]-48);
    }
    return val;
}

int isPossible(ll num, ll base, int length)
{
    ll val=0;
    for(int i=0;i<length;i++)
    {
        val*=base;
        val+=1;
    }
    if(val>num)
        return -1;
    if(val==num)
        return 0;
    if(val<num)
        return 1;
}

ll func(ll num, ll s, ll e, int length)
{
    while(s<=e)
    {
        ll m = (s+e)/2;
        //cout<<"m = "<<m<<endl;
        int val = isPossible(num,m,length);
        if(val==0)
            return m;
        if(val==1)
            s=m+1;
        else
            e=m-1;
    }
    return 0;
}

string to_str(ll k)
{
    string ans = "";
    while(k)
    {
        ans+=((k%10)+48);
        k/=10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string solve(string A) {
    ll num = to_INT(A);
    ll k;
    int upper_limit = ceil(log2(num));
    //cout<<"upper limit = "<<upper_limit<<endl;
    for(int i=upper_limit;i>=2;i--)
    {
        k=func(num, 2, num-1, i);
        if(k)
            break;
    }
    string ans = to_str(k);
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}