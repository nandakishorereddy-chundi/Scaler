#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > ans;
void print(vector<int> &temp)
{
    for(auto i:temp)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void print_ans()
{
    for(auto i:ans)
    {
        print(i);
    }
    return;
}

void recur_func(int index, int A, int B, vector<int> &temp, int f_size)
{
    if(A<B)
        return;
    if(B==1)
    {
        if(index<=A && temp.size()<f_size)
            temp.push_back(index);
        //cout<<"Printing Temp"<<endl;
        //print(temp);
        ans.push_back(temp);
        return;
    }
    int i=index;
    for(;i<=A;)
    {
        temp.push_back(i);
        recur_func(i+1, A, B-1, temp, f_size);
        i = temp.back()+1;
        temp.pop_back();
    }
}

vector<vector<int> > combine(int A, int B) {
    vector<int> temp;
    int f_size = B;
    ans.clear();
    for(int i=1;i+B<=A+1;i++)
    {
        temp.clear();
        recur_func(i, A, B, temp, f_size);
    }
    return ans;
}

int main()
{
    int a,b;
    cin>>a>>b;
    ans=combine(a,b);
    print_ans();
    return 0;
}