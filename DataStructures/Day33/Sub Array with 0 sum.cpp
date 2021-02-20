#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

#define ll long long
int solve(vector<int> &A) {
    vector<ll> prefixSum(A.size(), 0);
    prefixSum[0]=A[0];
    for(int i=1;i<A.size();i++)
        prefixSum[i]=prefixSum[i-1]+A[i];
    unordered_map<ll, bool> umap;
    umap.insert({0, 1});
    for(auto i:prefixSum)
    {
        if(umap.find(i)!=umap.end())
            return 1;
        else
            umap[i]=1;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n), ans;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(a)<<endl;
    return 0;
}