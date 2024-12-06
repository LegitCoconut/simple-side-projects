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
void start_game();  
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
}

void start_game(){
  int op = 0;
  clear();
  print_banner();
  cout<<green<<" [1] - PLACE SHIPS \n [2] - REPLACE/RE-ORDER SHIPS \n [3] - START GAME \n [4] - RENAME PLAYER \n [5] - BACK TO MAIN MENU \n\n -> ENTER GAME OPTION :"<<reset;
  cin>>op;
  if(op==1){
    // get into place ship function one by one 
  }
  if(op==2){
    //get into specific player to reorder their ships -> completely -> partially 
  }
  if(op==3){
    // continue to further start game 
  }
  if(op==4){
    // rename players .
  }
  if(op==5){
    // go back to main menu 
    main();
  }
  else{
    cout<<"INVALID OPTION START AGANIN ";
  }

}


int main(){
  int op = 0;
  clear();
  print_banner();
  while (true)
  {
    cout<<green<<" [1] - START GAME \n [2] - VIEW GAME RULES \n [3] - QUIT GAME \n\n -> ENTER GAME OPTION :"<<reset;
    cin>>op;
    if(op==1){
      // get into start game function 
      start_game();
    }
    if(op==2){
      //get into view rules function 
    }
    if(op==3){
      cout<<red<<"EXITING THE GAME ! \n"<<reset;
      break;
      break;
    }
    else{
      cout<<"INVALID INPUT \n";
    }
  }
    
}