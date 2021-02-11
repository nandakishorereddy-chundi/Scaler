#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>&A, int m, int B)
{
    int ptr=A[0], cnt=1;
    for(auto i:A)
    {
        if(i-ptr>=m)
        {
            cnt++;
            ptr=i;
            if(cnt==B)
                return 1;
        }
    }
    return 0;
}

int func(vector<int> &A, int s, int e, int B)
{
    int ans=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        //cout<<"mid = "<<mid<<endl;
        if(isPossible(A,mid,B))
        {
            //cout<<"True"<<endl;
            ans=mid;
            s=mid+1;
        }
        else
        {
            //cout<<"False"<<endl;
            e=mid-1;
        }
    }
    return ans;
}

int solve(vector<int> &A, int B) {
    int _min, _max;
    sort(A.begin(), A.end());
    _min = A[0];
    _max = A[A.size()-1];
    return func(A, 0, _max, B);
}

int main()
{
    int n,B;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>B;
    cout<<solve(a, B)<<endl;
    return 0;
}