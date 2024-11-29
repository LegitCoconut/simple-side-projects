// a simple tick tak toe game using cpp , played on terminal
#include <iostream>
using namespace std;
int main(){
    cout<<"WELCOME TO TICK TACK TOE GAME "<<endl<<endl;
     char game[3][3]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
          };
    const char playx='X';
    const char playo='O';
    char currentplayer= playx;
    int row , column;
    char winner=' ';

    for(int i=0;i<9;i++){   
        // print the board
        cout<<"  "<<game[0][0]<<" | "<<game[0][1]<<" | "<<game[0][2]<<endl;
        cout<<" -----------"<<endl;
        cout<<"  "<<game[1][0]<<" | "<<game[1][1]<<" | "<<game[1][2]<<endl;
        cout<<" -----------"<<endl;
        cout<<"  "<<game[2][0]<<" | "<<game[2][1]<<" | "<<game[2][2]<<endl<<endl;

        cout<<"current player is : "<<currentplayer<<endl;
         winner=' ';

        while(true) // checking conditions for input values
        {
            cout<<"enter row and column (0-2) :";
            cin>>row>>column;

            if(row < 0 || row >2 || column < 0 || column > 2){
                cout<<"invalid input, Please try again"<<endl;
                continue;
            }
            else if (game[row][column] != ' '){
                cout<<"Tile is full, Please try again"<<endl;
                continue;
            }
            else{
                break;
            }
        }
        game[row][column] = currentplayer;
        currentplayer = (currentplayer == playx) ? playo : playx ; // switching b/w users

        // checking winning conditions rows
       for(int r=0;r<3;r++){
        if(game[r][0] != ' ' && game[r][0] == game[r][1] && game[r][1] == game[r][2]) winner= game[r][0];
        }
        for(int j=0;j<3;j++){
            if(game[0][j]!=' ' && game[0][j]==game[1][j] && game[1][j]==game[2][j]) winner= game[0][j];
        }
        if(game[0][0] !=' ' && game[0][0] == game[1][1] && game[1][1]==game[2][2]) winner= game[0][0];
        if(game[0][2]!=' ' && game[0][2] == game[1][1] && game[1][1] == game[2][2]) winner= game[0][2];
        if(winner !=' '){
            cout<<"  "<<game[0][0]<<" | "<<game[0][1]<<" | "<<game[0][2]<<endl;
            cout<<" -----------"<<endl;
            cout<<"  "<<game[1][0]<<" | "<<game[1][1]<<" | "<<game[1][2]<<endl;
            cout<<" -----------"<<endl;
            cout<<"  "<<game[2][0]<<" | "<<game[2][1]<<" | "<<game[2][2]<<endl<<endl;
            cout<<"winner of the match is player : "<<winner<<endl;
            break;
        }   
    }
    if(winner == ' ')cout<<"game is tie ,start over !";
    return 0;
}
