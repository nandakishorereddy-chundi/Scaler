#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

vector<vector<int> > anagrams(const vector<string> &A) {
    vector<vector<int> > ans, fans;
    unordered_map<string, vector<int> > umap;
    string s;
    for(int i=0;i<A.size();i++)
    {
        s=A[i];
        sort(s.begin(), s.end());
        if(umap.find(s)==umap.end())
        {
            vector<int> temp(1, i+1);
            umap.insert({s, temp});
        }
        else
            umap[s].push_back(i+1);
    }
    for(auto it:umap)
        ans.push_back(it.second);
    return ans;
}

int main()
{
    int n;
    vector<vector<int> >ans;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    ans = anagrams(a);
}