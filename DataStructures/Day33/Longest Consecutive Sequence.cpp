#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestConsecutive(const vector<int> &A) {
    unordered_map<int, bool> umap;
    for(auto i:A)
        umap[i]=1;
    int cnt=1, ans=INT_MIN;
    for(auto i:A)
    {
        if(umap.find(i-1)!=umap.end())
            continue;
        int j=i;
        //cout<<"j = "<<j<<endl;
        cnt=1;
        while(1)
        {
            if(umap.find(j+1)!=umap.end())
                cnt++;
            else
            {
                ans=max(ans, cnt);
                //cout<<"ans = "<<ans<<endl;
                break;
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<longestConsecutive(a)<<endl;
    return 0;
}