#include  <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>    // if compiled for windows , windows.h will be compiled
using namespace std;


std::string red = "\033[31m";                // define red color for ascii
std::string green = "\033[32m";              // define green color for ascii
std::string yellow = "\033[33m";             // define yellow color for ascii
std::string reset = "\033[0m";               // reset back to white colour

void print_banner();                         // print banner function
void clear();                                // clear screen function 
char print_map(char ship[10][10]);           // print input map 
int substart();                              // substart menu of the game
void tutorial();                             // print tutorial function 
int main();                                  // start game menu function 
string typing(string printlword, int speed); // typing effect function 


string pl1="player1" , pl2="player2" ;                          // player name storing variable
char a1[10][10] ={                          //player 1 placed map 

		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','x','x','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'}
	};

char a2[10][10]={                         // player 1 bombing map 
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'}
	};

char b1[10][10] ={                        // player 2 placed map
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'}
	};

	char b2[10][10] ={                    // player 2 bombing map 
		{'*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*','*','*'}
	};

void print_banner() {                // print banner function declared 
cout<<red<< R"(
                                       ,----,       ,----,   ,--,                                                         
                                     ,/   .`|     ,/   .`|,---.'|                                 ,--,        ,-.----.    
          ,---,.    ,---,          ,`   .'  :   ,`   .'  :|   | :       ,---,.  .--.--.         ,--.'|   ,---,\    /  \   
        ,'  .'  \  '  .' \       ;    ;     / ;    ;     /:   : |     ,'  .' | /  /    '.    ,--,  | :,`--.' ||   :    \  
      ,---.' .' | /  ;    '.   .'___,/    ,'.'___,/    ,' |   ' :   ,---.'   ||  :  /`. / ,---.'|  : '|   :  :|   |  .\ : 
      |   |  |: |:  :       \  |    :     | |    :     |  ;   ; '   |   |   .';  |  |--`  |   | : _' |:   |  '.   :  |: | 
      :   :  :  /:  |   /\   \ ;    |.';  ; ;    |.';  ;  '   | |__ :   :  |-,|  :  ;_    :   : |.'  ||   :  ||   |   \ : 
      :   |    ; |  :  ' ;.   :`----'  |  | `----'  |  |  |   | :.'|:   |  ;/| \  \    `. |   ' '  ; :'   '  ;|   : .   / 
      |   :     \|  |  ;/  \   \   '   :  ;     '   :  ;  '   :    ;|   :   .'  `----.   \'   |  .'. ||   |  |;   | |`-'  
      |   |   . |'  :  | \  \ ,'   |   |  '     |   |  '  |   |  ./ |   |  |-,  __ \  \  ||   | :  | ''   :  ;|   | ;     
      '   :  '; ||  |  '  '--'     '   :  |     '   :  |  ;   : ;   '   :  ;/| /  /`--'  /'   : |  : ;|   |  ':   ' |     
      |   |  | ; |  :  :           ;   |.'      ;   |.'   |   ,/    |   |    \'--'.     / |   | '  ,/ '   :  |:   : :     
      |   :   /  |  | ,'           '---'        '---'     '---'     |   :   .'  `--'---'  ;   : ;--'  ;   |.' |   | :     
      |   | ,'   `--''                                              |   | ,'              |   ,/      '---'   `---'.|     
      `----'                                                        `----'                '---'                 `---`     
                               Developed by LegitCoconut ( https://github.com/LegitCoconut )

                            
)"<<reset;
}


void clear() {    //function used for clearing the screen.
  system("cls");
  std::cout << "\033[2J\033[H";    
}

string typing(string printlword, int speed , int pak){  // function which does the typing effect
  for(int i=0; printlword[i] != '\0'; i++){
    cout<<printlword[i];
    Sleep(speed);
  }
  if(pak ==1){
      cout<<red<<"\n \n press any key to continue ......."<<reset;
      cin.ignore();
      cin.get();
    }
}

void tutorial(){
  clear();
  print_banner();
  const string str =  "\033[32m WELCOME TO BATTLESHIP CLI GAME - READ THE TUTORIAL CORRECTLY \n \n EACH PLAYER WILL HAVE A MAP OF 10x10 , WHERE YOU SHOULD PLACE YOUR SHIPS WHEN THE GAME STARTS \n \nEACH PLAYER WILL HAVE 5 SHIPS THAT CAN BE PLACED IN THE MAP \033[33m \n\n  Carrier (5 spaces) ( <==C=> ) \n  Battleship (4 spaces) ( <=B> ) \n  Patrol (3 spaces) ( <P> ) \n  Submarine (3 spaces) ( <S> ) \n  Destroyer ( 2 spaces ) ( <D )\033[0m \n\nFIRST YOU WILL BE PROMPTED TO ENTER PLAYERS NAME , FOLLOWED BT PLACING EACH SHIPS INTO THE MAP \nA MENU WILL APPEAR WHERE YOU CAN REORDER THE SHIP , RENAME PLAYERS AND EXIT BACK TO MAIN MENU \nNOW YOU CAN BOMB EACH OTHERS MAP WITH THE X-Y COORDINATES AND IF ALL BOATS ARE FOUND , THEN THAT PLAYER LOSES. \n";
  typing(str,25,0);
  cout<<red<<"\n\n Press any key to continue.....";
  cin.ignore();
  cin.get();
}

char print_map(char ship[10][10]){    // function to print a particular map 
  cout<<"      0 1 2 3 4 5 6 7 8 9 "<<"\n";
  cout<<"      | | | | | | | | | | "<<"\n\n";
  for(int i=0; i<10 ; i++){
    cout<<i<<"-- - ";
    for(int j=0; j<10; j++){
      if(ship[i][j] != '*'){
        cout<<red<<ship[i][j]<<reset<<" "; 
      }
      else{
        cout<<ship[i][j]<<" ";
      }
    }
    cout<<"\n";
  }
  return 0;
}

int substart(){
  clear();
  print_banner();
  if(pl1 == "player1" && pl2 == "player2"){ // only ask to change name if it is not chnaged when game starts , for second time rename should be there 
    cout<<yellow<<" NOW , TYPE IN PLAYER-1 NAME : ";
    cin>>pl1;
    cout<<" NOW , TYPE IN PLAYER-2 NAME : ";
    cin>>pl2;
    cout<<green<<"\n SUCESSFULLY UPDATED NAME OF PLAYERS  \n\n "<<yellow<<" PLAYER 1 : "<<pl1<<"\n  PLAYER 2 : "<<pl2;
    cin.ignore();
    cin.get();
  }
  
    while(1){
      int rp=0;
      clear();
      print_banner();
      cout<<yellow<<"PLAYER INFO : \n [PLAYER 1] : "<<pl1<<"\n [PLAYER 2] : "<<pl2<<reset;
      cout<<green<<"\n\n [1] - START GAME  \n [2] - REPLACE/RE-ORDER SHIPS \n [3] - VIEW MAP \n [4] - RENAME PLAYER \n [5] - BACK TO MAIN MENU \n"<<reset;
      int op2 = 0;
      cout<<green<<"\n >"<<reset;
      cin>>op2;
      switch(op2) {
        case 1:
            cout<<yellow<<"GOING TO START GAME , PRESS ANY KEY TO CONTINUE ......"<<reset;
            cout<<"not implemented";
            cin.ignore();
            cin.get(); 
           
            break;
    
        case 2:
            //get into specific player to reorder their ships -> completely -> partially 
            cout<<yellow<<"STARTING TO REORDER SHIP , PRESS ANY KEY TO CONTINUE ......"<<reset;
            cout<<"not implemented";
            cin.ignore();
            cin.get();
            
            break;
    
        case 3:
            // view player map
            clear();
            print_banner(); 
            cout<<green<<" WHICH MAP TO VIEW ? \n [1] - "<<pl1<<"\n [2] - "<<pl2<<"\n > "<<reset;
            cin>>rp;
            cout<<"TELL OTHER PLAYER TO MOVE ! , PRESS ANY KEY TO CONTINUE ..... ";
            cin.ignore();
            cin.get();
            if(rp==1) print_map(a1);
            if(rp==2) print_map(a2);
            cout<<red<<"MAP WILL BR CLEARED IN ";
            for(int j=5;j>=0;j--) {
              cout<<".."<<j; 
              Sleep(1000);
            }
            cout<<reset;
            clear();
            break;
    
        case 4:
            // rename players .
            clear();
            print_banner();
            cout<<yellow<<"ENTER NAME OF PLAYER 1 : ";
            cin>>pl1;
            cout<<"ENTER NAME OF PLAYER 2 : ";
            cin>>pl2;
            cout<<"\n PLAYER NAME CHANGED SUCSSFULLY \n PLAYER-1 :"<<pl1<<"\n PLAYER-2 :"<<pl2<<"\n press any key to continue"<<reset;
            cin.ignore();
            cin.get();
            break;

        case 5:
            // go back to main menu 
            return 0;
            
        default:
            break;
    }
  }
}


int main(){

  while (1)
  {
    clear();
    print_banner();
    int op = 0;
    cout<<green<<" [1] - START GAME \n [2] - VIEW GAME RULES \n [3] - QUIT GAME \n\n > "<<reset;
    cin>>op;
    switch(op){
      case 1:
        cout<<yellow<<"GOING TO START THE GAME , FOLLOW INSTRUCRIONS , PRESS ANY KEY TO CONTINUE ....."<<reset;
        cin.ignore();
        cin.get();
        // go to substart function
        substart();
        break;
    
      case 2:
        tutorial();
        break;
    
      case 3:
        cout<<red<<"EXITING THE GAME ! \n"<<reset;
        return 0;
    
      default:
        break;
    }
  } 
}
  
