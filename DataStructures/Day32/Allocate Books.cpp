#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int>&A, int m, int B)
{
    int sum=0, cnt=0, fg=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>m)
            return false;
        sum+=A[i];
        if(sum>m)
        {
            //cout<<"sum = "<<sum<<endl;
            cnt++;
            sum=0;
            if(fg==1)
                i--;
            fg=0;
            //cout<<"cnt = "<<cnt<<endl;
            if(cnt>=B)
            {
                if(cnt==B && i<A.size()-1)
                    return false;
                return false;
            }
        }
        else
            fg=1;
    }
    return true;
}

int func(vector<int> &A, int s, int e, int B)
{
    int ans=e, m;
    bool isTrue;
    while(s<=e)
    {
        m=(s+e)/2;
        //cout<<"s = e = m = "<<s<<" "<<e<<" "<<m<<endl;
        isTrue = search(A,m,B);
        //cout<<"isTrue = "<<isTrue<<endl;
        if(isTrue)
        {
             ans=m;
             e=m-1;
        }
        else
            s=m+1;   
    }
    return ans;
}
int books(vector<int> &A, int B) {
    if(B>A.size())
        return -1;
    int sum=0;
    for(auto i:A)
        sum+=i;
    return func(A,0,sum,B);
}

int main()
{
    int n,b;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>b;
    cout<<books(a, b)<<endl;
    return 0;
}