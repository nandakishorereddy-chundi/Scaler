#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >ans;

void print()
{
    for(auto it:ans)
    {
        for(int i=0;i<it.size();i++)
            cout<<it[i]<<" ";
        cout<<endl;
    }
}

void bt(int ix, vector<int> temp, vector<int> &A, int B)
{
    if(B<=0 || ix == A.size())
    {
        if(B==0)
            ans.push_back(temp);
        return;
    }
    temp.push_back(A[ix]);
    bt(ix, temp, A, B-A[ix]);
    temp.pop_back();
    bt(ix+1, temp, A, B);
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    ans.clear();
    sort(A.begin(), A.end());
    vector<int> temp, b;
    temp.clear();
    for(int i=0;i<A.size();i++)
    {
        if(i==0 || A[i]!=A[i-1])
            b.push_back(A[i]);
    }
    bt(0, temp, b, B);
    return ans;
}

int main()
{
    int n,B;
    cin>>n;
    vector<int> a(n), b;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>B;
    for(int i=0;i<n;i++)
    {
        if(i==0 || a[i]!=a[i-1])
            b.push_back(a[i]);
    }
    vector<int> temp;
    ans = combinationSum(b, B);
    print();
}