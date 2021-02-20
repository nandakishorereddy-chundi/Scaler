#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> lszero(vector<int> &A) {
    vector<int> prefixSum(A.size(), 0);
    vector<int> ans;
    int diff=INT_MIN+3, FI, LI=INT_MIN+3;
    prefixSum[0]=A[0];
    for(int i=1;i<A.size();i++)
        prefixSum[i]=prefixSum[i-1]+A[i];
    unordered_map<int, pair<int, int> > umap;
    umap.insert({0, {-1, -1}});
    for(int i=0;i<A.size();i++)
    {
        if(umap.find(prefixSum[i])!=umap.end())
        {
            pair<int, int> p = umap[prefixSum[i]];
            p.second = i;
            umap[prefixSum[i]] = p;
        }
        else
        {
            pair<int, int> p;
            p.first = i;
            p.second = INT_MIN+3;
            umap.insert({prefixSum[i], p});
        }
    }
    for(auto itr:umap)
    {
        pair<int, int> p = itr.second;
        if(p.second-p.first>=diff && p.second!=INT_MIN+3)
        {
            if((p.second-p.first==diff && p.first<FI) || p.second-p.first>diff)
            {
                FI=p.first+1;
                LI=p.second;
                diff=LI-FI+1;
            }
        }
    }
    auto start = A.begin()+FI;
    auto end = A.begin()+LI+1;
    vector<int> temp;
    if(LI==INT_MIN+3)
        return temp;
    return vector<int>(start, end);
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n), ans;
    for(int i=0;i<n;i++)
        cin>>a[i];
    ans = lszero(a);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}