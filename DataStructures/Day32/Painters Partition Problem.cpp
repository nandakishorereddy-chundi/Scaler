#include<iostream>
#include<vector>
#define ll long long
using namespace std;

#define ll long long

bool isPossible(vector<int> &C, ll m, int A)
{
    ll sum=0, cnt=1;
    for(auto i:C)
    {
        if(i>m)
            return 0;
        if(sum+i>m)
        {
            cnt++;
            if(cnt>A)
                return 0;
            sum=i;
        }
        else
            sum+=i;
    }
    return 1;
}

ll func(vector<int> &C, ll s, ll e, int A)
{
    ll ans=-1;
    while(s<=e)
    {
        ll m=(s+e)/2;
        //cout<<"m = "<<m<<endl;
        if(isPossible(C,m,A))
        {
            //cout<<"true"<<endl;
            ans=m;
            e=m-1;
        }
        else
        {
            //cout<<"false"<<endl;
            s=m+1;
        }
    }
    return ans;
}
int paint(int A, int B, vector<int> &C) {
    ll sum=0, ans;
    for(auto i:C)
        sum+=i;
    ans = func(C, 0, sum, A);
    return (ans*B)%10000003;
}

int main()
{
    int A,B,n;
    cin>>A>>B>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<paint(A,B,a)<<endl;;
}