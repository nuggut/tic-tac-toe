#include <iostream>
#include <string>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int currentplayer;
char currentmarker;
void drawboard(){
    cout<<"  "<<board[0][0]<<"|"<<"  "<<board[0][1]<<"|"<<"  "<<board[0][2]<<"\n";
    cout<<"---|---|---\n";
    cout<<"  "<<board[1][0]<<"|"<<"  "<<board[1][1]<<"|"<<"  "<<board[1][2]<<"\n";
    cout<<"---|---|---\n";
    cout<<"  "<<board[2][0]<<"|"<<"  "<<board[2][1]<<"|"<<"  "<<board[2][2]<<"\n";
}
bool playmaker(int slot){
    int row = (slot - 1)/3;
    int col = (slot - 1)%3;
    if (board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = currentmarker;
        return true;
    }else{
        return false;
        }
}
int winner(){
    for(int i=0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentplayer;
        if(board[0][i] == board[1][0] && board[1][i] == board[2][i]) return currentplayer;
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentplayer;
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentplayer;
    }
    return 0;
}
void swapPlayersandMakers(){
    if(currentmarker == 'X') currentmarker = 'O';
    else currentmarker = 'X';
    if(currentplayer == 1) currentplayer = 2;
    else currentplayer = 1;
}


int main(){
currentplayer = 1;
currentmarker = 'X';
drawboard();
cout<<currentplayer<<" player please play ";
int slot;
cin>>slot;
while(true){
while(!playmaker(slot)){
    drawboard();
    cout<<"this position is full please choose another ";
    cin>>slot;
}
drawboard();
if(winner()){
   cout<<"player "<<winner()<<" has won ";
   break;
}else{
    swapPlayersandMakers();
    cout<<currentplayer<<" player please play ";
    cin>>slot;
    continue;
    }
}
return 0;   
}