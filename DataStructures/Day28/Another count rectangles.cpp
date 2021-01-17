#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, int B) {
    int p1, p2, cnt=0;
    const unsigned int mod = 1000000007;
    p1=0;
    p2=A.size()-1;
    while(p1<=p2)
    {
        if(p1==p2 && A[p1]<=B/A[p2] && B%A[p2]!=0)
        {
            cnt=(cnt+1+mod)%mod;
            break;
        }
        else if(A[p1]==B/A[p2] && B%A[p2]!=0)
        {
            cnt=(cnt+1+(2*(p2-p1))+mod)%mod;
            p1++;
        }
        else if(A[p1]<B/A[p2])
        {
            cnt=(cnt+1+(2*(p2-p1))+mod)%mod;
            p1++;
        }
        else
            p2--;
    }
    return cnt;
}

int main()
{
    int n, m;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    cout<<solve(a, m)<<endl;
    return 0;
}