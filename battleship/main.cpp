#include  <iostream>
#include <string>
#include <cstdlib>
using namespace std;


std::string red = "\033[31m";              // define red color for ascii
std::string green = "\033[32m";            // define green color for ascii
std::string yellow = "\033[33m";           // define yellow color for ascii
std::string reset = "\033[0m";             // reset back to white colour
void print_banner();                       // print banner function
void clear();                              // clear screen function 
char print_map(char ship[10][10]);         // print input map 
int substart();  
int main();                       // start game menu function 


string pl1 , pl2 ;
char a1[10][10] ={  //player 1 placed map 

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

char a2[10][10]={  // player 1 bombing map 
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

char b1[10][10] ={    // player 2 placed map
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

	char b2[10][10] ={       // player 2 bombing map 
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

void print_banner() {       // print banner function declared 
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
  cout<<yellow<<" NOW , TYPE IN PLAYER-1 NAME : ";
  cin>>pl1;
  cout<<" NOW , TYPE IN PLAYER-2 NAME : ";
  cin>>pl2;
  cout<<green<<"\n SUCESSFULLY UPDATED NAME OF PLAYERS  \n\n "<<yellow<<" PLAYER 1 : "<<pl1<<"\n  PLAYER 2 : "<<pl2;
  cin.ignore();
  cin.get();
  
    while(1){
      int rp=0;
      clear();
      print_banner();
      cout<<green<<" [1] - START GAME  \n [2] - REPLACE/RE-ORDER SHIPS \n [3] - VIEW MAP \n [4] - RENAME PLAYER \n [5] - BACK TO MAIN MENU \n"<<reset;
      int op2 = 0;
      cout<<green<<"\n -> ENTER GAME OPTION : "<<reset;
      cin>>op2;
      switch(op2) {
        case 1:
            cout<<yellow<<"GOING TO START GAME , PRESS ANY KEY TO CONTINUE ......"<<reset;
            cin.ignore();
            cin.get();
            // get into place ship function one by one 
            cout<<"not implemented";
            break;
    
        case 2:
            //get into specific player to reorder their ships -> completely -> partially 
            cout<<yellow<<"STARTING TO REORDER SHIP , PRESS ANY KEY TO CONTINUE ......"<<reset;
            cin.ignore();
            cin.get();
            cout<<"not implemented";
            break;
    
        case 3:
            // view player map
            clear();
            print_banner(); 
            cout<<green<<" WHICH MAP TO VIEW ? \n [1] - "<<pl1<<"\n [2] - "<<pl2<<"\n ENTER OPTION "<<reset;
            cin>>rp;
            cout<<"TELL OTHER PLAYER TO MOVE ! , PRESS ANY KEY TO CONTINUE ..... ";
            cin.ignore();
            cin.get();
            if(rp==1) print_map(a1);
            if(rp==2) print_map(a2);
            cout<<"PRESS ANY KEY TO CLEAR DISPLAYED MAP......";
            cin.ignore();
            cin.get();
            break;
    
        case 4:
            // rename players .
            clear();
            print_banner();
            cout<<yellow<<"ENTER NAME OF PLAYER 1 : ";
            cin>>pl1;
            cout<<"ENTER NAME OF PLAYER 2 : ";
            cin>>pl2;
            cout<<"PLAYER NAME CHANGED SUCSSFULLY \n PLAYER-1 :"<<pl1<<"\n PLAYER-2 :"<<pl2<<"\n press any key to continue"<<reset;
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
    cout<<green<<" [1] - START GAME \n [2] - VIEW GAME RULES \n [3] - QUIT GAME \n\n -> ENTER GAME OPTION :"<<reset;
    cin>>op;
    switch(op){
      case 1:
        cout<<yellow<<"GOING TO START THE GAME , FOLLOW INSTRUCRIONS , PRESS ANY KEY TO CONTINUE ....."<<reset;
        cin.ignore();
        cin.get();
        // go to substart function
        substart();
        cout<<"returned to main funcrujn";
        break;
    
      case 2:
        // go to view rule function 
        cout<<"not implemeted";
        break;
    
      case 3:
        cout<<red<<"EXITING THE GAME ! \n"<<reset;
        return 0;
    
      default:
        cout<<"INVALID INPUT TRY AGAIN from main function  \n";
        break;
    }
  } 
}
  
