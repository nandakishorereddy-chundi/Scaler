#include<iostream>
using namespace std;

int ans=-1;
int func(int s, int e, int A)
{
    if(s>e)
        return ans;
    if(s==e)
    {
        if(s<=A/s)
            return s;
        else
            return s-1;
    }
    int m=(s+e)/2;
    if(m==A/m)
        return m;
    if(m>A/m)
        return func(s,m-1,A);
    if(m<A/m)
    {
        ans=m;
        return func(m+1,e,A);
    }
}

int sqrt(int A) {
    if(A==0 || A==1)
        return A;
    return func(0, A, A);
}

int main()
{
    int n;
    cin>>n;
    cout<<sqrt(n)<<endl;
    return 0;
}