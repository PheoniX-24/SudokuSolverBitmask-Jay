#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int BoardSize = 9;
const int CellSize = 3;

int board[BoardSize][BoardSize];

int log2arr[10010];
int takenRow[BoardSize]; 
int takenCol[BoardSize];
int takenGrid [CellSize][CellSize];

int ans = 0;

void makemove(int ch, int row, int col){ 
    board[row][col]=ch;
    takenRow[row]^=(1<<ch);
    takenCol[col]^=(1<<ch); 
    takenGrid[row/CellSize] [col/CellSize] ^= (1<<ch);
}

void revertmove(int ch,int row, int col){
    board[row][col]=0;
    takenRow[row]^=(1<<ch);
    takenCol[col]^=(1<<ch);
    takenGrid [row/CellSize] [col/CellSize] ^= (1<<ch);
}

int getchoices(int row, int col){ 
    int taken = (takenRow[row] | takenCol[col] | takenGrid[row/CellSize][col/CellSize]);
    int nottaken = ((1<<(BoardSize+1))-1)^taken;
    // int nottaken = (~taken)&((1<< (BoardSize+1))-1);
    if(nottaken&1) nottaken^=1;
    return nottaken;
}

void rec(int row, int col){
    if(col==BoardSize){
        rec(row+1,0);
        return;
    }

    if(row==BoardSize){
        // base case
        ans++;

        cout<<"Answer "<<ans<<endl; 
        for(int i=0;i<BoardSize; i++) { 
            for(int j=0;j<BoardSize;j++){ 
                cout<<board[i][j]<<" ";
            } 
            cout<<endl;
        }
        return;
    }

    if(board[row][col]==0){
        //we need to fill
        int chmask= getchoices(row, col);
        while(chmask){
            // get last 1
            int last1 = chmask^(chmask&(chmask-1));
            // find position of last 1 
            int last1pos = log2arr[last1];

            //use that as a valid move
            makemove(last1pos,row,col);
            rec(row, col+1);
            revertmove(last1pos, row, col); 
            // remove last 1.
            chmask = chmask&(chmask-1);
        }
    }
    else{
        // pre-filled (Assume there is a solution (prefilled values don't collide))
        rec(row, col+1);
    }
}

void solve(){
    for(int i=0;i<=9;i++){ 
        log2arr[1<<i]=i;
    }
    for(int i=0;i<BoardSize; i++){ 
        for(int j=0;j<BoardSize;j++){ 
            int ch; 
            cin>>ch; 
            makemove(ch,i,j); 
        }
    }

    rec(0,0);

    //cout<<ans<<endl;

}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
     int i = 1;
    cin >> t;
    while (t--) {
        cout << "Case #" << i << ": \n";
        solve();
        i++;
    }
    return 0;
}
