#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(vector<int> &A) {
    unordered_map<int, int> umap;
    for(int i=0;i<A.size();i++)
    {
        if(umap.find(A[i])==umap.end())
            umap.insert({A[i], 1});
        else
            umap[A[i]]++;
    }
    int cnt=0;
    for(int i=0;i<A.size();i++)
        for(int j=i+1;j<A.size();j++)
            if(umap.find(A[i]+A[j])!=umap.end())
                cnt++;
    return cnt;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(a)<<endl;
    return 0;
}