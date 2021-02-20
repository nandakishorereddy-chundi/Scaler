#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

string solve(string A) {
    string ans = "";
    queue<char> q;
    unordered_map<char, int> umap;
    for(auto i:A)
    {
        if(umap.find(i)==umap.end())
        {
            if(q.empty())
                ans+=i;
            else
                ans+=q.front();
            q.push(i);
            umap[i]=1;
        }
        else
        {
            umap[i]++;
            while(!q.empty() && umap[q.front()]>1)
                q.pop();
            if(q.empty())
                ans+='#';
            else
                ans+=q.front();
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}