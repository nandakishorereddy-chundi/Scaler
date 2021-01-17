#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &A) {
    auto p1=A.begin();
    auto p2=p1+1;
    auto p3=p2+1;
    while(p1!=A.end() && p2!=A.end() && p3!=A.end())
    {
        if(*p1==*p2 && *p2==*p3)
        {
            while(*p2==*p3 && p3!=A.end())
                p3++;
            A.erase(p2+1, p3);
        }
        p1=p2;
        p2=p1+1;
        p3=p2+1;
    }
    return A.size();
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<removeDuplicates(a)<<endl;
    return 0;
}