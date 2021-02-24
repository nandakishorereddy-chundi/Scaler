#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> get_kmp(const string B)
{
    vector<int> kmp(B.length(), 0);
    kmp[0]=0;
    int j=0;
    for(int i=1;i<B.size();i++)
    {
        if(B[i]==B[j])
        {
            kmp[i]=j+1;
            j++;
        }
        else
        {
            while(j>0 && B[j]!=B[i])
                j=kmp[j-1];
            if(B[j]==B[i])
            {
                kmp[i]=j+1;
                j++;
            }
            else
                kmp[i]=0;
        }
    }
    return kmp;
}

void print(vector<int> &kmp)
{
    for(auto i:kmp)
        cout<<i<<" ";
    cout<<endl;
}

int strStr(const string A, const string B) {
    if(B.length()>A.length())
        return -1;
    vector<int> kmp(B.length(), 0);
    kmp = get_kmp(B);
    //print(kmp);
    int j=0, i=0;
    while(i<A.length())
    {
        if(A[i]==B[j])
        {
            j++;
            if(j==B.length())
                return i-j+1;
        }
        else
        {
            while(j>0 && A[i]!=B[j])
                j=kmp[j-1];
            if(A[i]==B[j])
                continue;
        }
        i++;
    }
    return -1;
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<strStr(a,b)<<endl;
    return 0;
}