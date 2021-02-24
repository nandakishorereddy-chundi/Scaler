#include<iostream>
#include<stack>
#include<string>
using namespace std;

string solve(string A) {
    stack<char> s;
    string ans="";
    for(auto c:A)
    {
        if(s.empty())
            s.push(c);
        else
        {
            if(c==s.top())
                s.pop();
            else
                s.push(c);
        }
    }
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