#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

bool isValidBox(const vector<string> &A, int r, int c)
{
    unordered_map<char, int> umap;
    for(int i=r;i<r+3;i++)
    {
        for(int j=c;j<c+3;j++)
        {
            if(A[i][j]!='.' && umap.find(A[i][j])!=umap.end())
                return 0;
            else
                umap.insert({A[i][j], 1});
        }
    }
    return 1;
}

int isValidSudoku(const vector<string> &A) {
    // Col wise check
    /*for(int i=0;i<9;i++)
    {
        unordered_map<char, int> umap;
        for(int j=0;j<9;j++)
        {
            if(A[i][j]!='.' && umap.find(A[i][j])!=umap.end())
            {
                cout<<"i = "<<i<<" "<<"j = "<<j<<" "<<A[i][j]<<endl;
                return 0;
            }
            else if(A[i][j]!='.')
            {
                cout<<A[i][j]<<" ";
                umap.insert({A[i][j], 1});
            }
        }
        cout<<endl;
    }*/
    //cout<<"Col completed"<<endl;
    // Row wise check
    for(int i=0;i<9;i++)
    {
        unordered_map<char, int> umap;
        cout<<"Insertion"<<endl;
        for(int j=0;j<9;j++)
        {
            if(A[j][i]!='.' && umap.find(A[j][i])!=umap.end())
            {
                cout<<"i = "<<i<<" "<<"j = "<<j<<" "<<A[j][i]<<endl;
                return 0;
            }
            else if(A[j][i]!='.')
            {
                cout<<A[j][i]<<" ";
                umap.insert({A[j][i], 1});
            }
        }
        cout<<endl;
    }
    //cout<<"Row completed"<<endl;
    /*for(int i=0;i<9;i=i+3)
    {
        for(int j=0;j<9;j=j+3)
            if(!isValidBox(A, i, j))
                return 0;
    }*/
    return 1;
}

int main()
{
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cout<<a[i]<<endl;
    }
    cout<<isValidSudoku(a)<<endl;
    return 0;   
}