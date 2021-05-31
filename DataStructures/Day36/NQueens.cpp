#include<iostream>
#include<vector>
using namespace std;

vector<vector<string> >ans;

void print_board(vector<string>board, int n)
{
    for(int i=0;i<n;i++)
        cout<<board[i]<<endl;
}

void print_ans()
{
    int n = ans.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<endl;
        cout<<endl;
    }
}

void construct_board(vector<string>&board, int n)
{
    string temp(n, '.');
    fill(board.begin(), board.end(), temp);
    return;
}

bool isValid(int r, int c, vector<string> &board, int n)
{
    //col check
    for(int i=r;i>=0;i--)
        if(board[i][c]=='Q')
            return 0;
    //left diagnoal
    for(int i=r,j=c;i>=0 && j>=0;i--,j--)
        if(board[i][j]=='Q')
            return 0;
    //right diagnoal
    for(int i=r,j=c;i>=0 && j<n;i--,j++)
        if(board[i][j]=='Q')
            return 0;
    return 1;
}

void bt(int ix, vector<string> &board, int n)
{
    if(ix==n)
    {
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isValid(ix,i,board,n))
        {
            board[ix][i] = 'Q';
            bt(ix+1, board, n);
            board[ix][i] = '.';
        }
    }
}

vector<vector<string> > solveNQueens(int A) {
    ans.clear();
    vector<string> board(A);
    construct_board(board, A);
    //print_board(board, A);
    bt(0, board, A);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    ans = solveNQueens(n);
    print_ans();
    return 0;
}