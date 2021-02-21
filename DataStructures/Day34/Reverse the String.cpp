#include<iostream>
#include<string>
#include<stack>
using namespace std;

string solve(string A) {
    string ans="";
    stack<string> s;
    for(auto i:A)
    {
        if(i==' ')
        {
            if(ans.length()>0)
            {
                if(ans[ans.length()-1]!=i)
                    ans+=i;
            }
        }
        else
            ans+=i;
    }
    //cout<<"ans = "<<ans<<endl;
    string word="";
    for(auto i:ans)
    {
        if(i==' ')
        {
            word+=i;
            s.push(word);
            word="";
        }
        else
            word+=i;
    }
    word+=' ';
    s.push(word);
    ans="";
    while(!s.empty())
    {
        ans+=s.top();
        s.pop();
    }
    if(ans[0]==' ')
        ans=ans.substr(1, ans.length());
    if(ans[ans.length()-1]==' ')
        ans=ans.substr(0, ans.length()-1);
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}