#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
using namespace std;

string solve(string A) {
    unordered_map<char, int> umap;
    vector<int> visit(30, -1);
    stack<char> s;
    for(auto i:A)
        umap[i]++;
    char c;
    for(int i=0;i<A.length();i++)
    {
        c=A[i];
        if(visit[c-97]!=-1)
        {
            umap[c]--;
            continue;
        }
        if(s.empty())
        {
            //cout<<"Pushing : "<<c<<endl;
            s.push(c);
            visit[c-97]=i;
            umap[c]--;
        }
        else
        {
            char x = s.top();
            //cout<<"C = "<<c<<" "<<"X = "<<x<<endl;
            if(c>x)
            {
                //cout<<"Pushing : "<<c<<endl;
                s.push(c);
                visit[c-97]=i;
                umap[c]--;
            }
            else
            {
                while(!s.empty() && umap[x]>0 && c<=x)
                {
                    //cout<<"x = "<<x<<endl;
                    visit[x-97]=-1;
                    //cout<<"Popping : "<<x<<endl;
                    s.pop();
                    if(!s.empty())
                        x=s.top();
                }
                //cout<<"Pushing : "<<c<<endl;
                s.push(c);
                visit[c-97]=i;
                umap[c]--;
            }
        }
    }
    string ans="";
    while(!s.empty())
    {
        ans+=s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}