#include <iostream>
#include <vector>
using namespace std;

int bulbs(vector<int> &A)
{
    int i=0, cnt=0;
    while(i<A.size())
    {
        if(A[i]==0)
        {
            while(A[i]==0 && i<A.size())
                i++;
            if(i==A.size())
                return 1+(cnt*2);
            cnt++;
        }
        if(A[i]==1)
        {
            while(A[i]==1 && i<A.size())
                i++;
            if(i==A.size())
                return cnt*2;
        }
    }
    return cnt*2;
}

int main()
{
    int n, ans;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    ans = bulbs(a);
    cout<<ans<<endl;
    return 0;
}
