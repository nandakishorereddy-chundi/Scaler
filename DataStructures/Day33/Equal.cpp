#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool basic_check(vector<int> v1, vector<int> v2)
{
    if(v1[0]==v2[0] || v1[0]==v2[1] || v1[1]==v2[0] || v1[1]==v2[1])
        return 0;
    return 1;
}

bool get_min(vector<int> v1, vector<int> v2)
{
    if(v1[0]<v2[0])
        return 0;
    if(v1[0]>v2[0])
        return 1;
    if(v1[1]<v2[1])
        return 0;
    if(v1[1]>v2[1])
        return 1;
    if(v1[2]<v2[2])
        return 0;
    if(v1[2]>v2[2])
        return 1;
    if(v1[3]<v2[3])
        return 0;
    else
        return 1;
}

vector<int> equal(vector<int> &A) {
    int A1, B1, C1, D1;
    vector<int> ans(4, INT_MAX);
    bool fg=0;
    unordered_map<int, vector<int> > umap;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            if(umap.find(A[i]+A[j])==umap.end())
            {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                umap.insert({A[i]+A[j], tmp});
            }
            else
            {
                vector<int> tmp=umap[A[i]+A[j]];
                vector<int> tmp2;
                tmp2.push_back(i);
                tmp2.push_back(j);
                if(basic_check(tmp, tmp2)==0)
                    continue;
                tmp.push_back(i);
                tmp.push_back(j);
                if(get_min(ans, tmp)==0)
                    ans=ans;
                else
                {
                    fg=1;
                    ans=tmp;
                }
            }
        }
    }
    if(fg==0)
    {
        vector<int> temp;
        return temp;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n), ans;
    for(int i=0;i<n;i++)
        cin>>a[i];
    ans = equal(a);
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
    return 0;
}