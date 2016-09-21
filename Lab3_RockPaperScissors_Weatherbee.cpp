#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string PlayStr;  //string for user input
string PCStr;  //string for PC choice
string gamestr;  //string for game result
string winstr = "";
enum Weapon {ROCK, PAPER, SCISSORS};  //weapon list

int randInt (int max ){ //random number generator

    srand (time (NULL));
    return (rand () % max);
    
}
 
Weapon PCChoice(int val) //function to get PC choice
{      
    Weapon PCstr;
	switch (val){
		case 0 : 
			PCstr = ROCK; cout << "Computer chooses a rock.." <<endl; break;
		case 1 : 
			PCstr = PAPER; cout << "Computer chooses a paper.." <<endl; break;
		case 2 : 
			PCstr = SCISSORS; cout << "Computer chooses a scissor.." <<endl; break;
	}
      return PCstr;	

}	
void Instruct(){//game instructions ----Need to add the rest of the assignment

cout << "WELCOME TO PAPER-ROCK-SCISSORS!" <<endl;

    cout << "This is a game for two players, which you will be playing against the computer. " <<endl;
            
	cout << "With each game, both players will select one of the following weapons: PAPER, ROCK, or SCISSORS." <<endl;
	cout << endl;
	cout <<  " * If both players select the same weapon, the game is a tie." <<endl;
    cout <<  "* ROCK blunts SCISSORS, so the player who selects ROCK wins." <<endl;
    cout <<  "* PAPER wraps ROCK, so the player who selects PAPER wins." <<endl;
    cout <<  "* SCISSORS cuts PAPER, so the player who selects SCISSORS wins." <<endl;
    cout << endl;
cout <<  "With each turn, select 'R' for ROCK, 'P' for PAPER, or 'S' for SCISSORS, and then press ENTER. You may quit at any time. " <<endl;
cout << endl;
cout <<"Enter an R for ROCK, P for PAPER and S for SCISSORS: " <<endl ; 
	}

Weapon PlayItem (char PlayerChoice){//function to convert user's choice to WEAPON
    Weapon PlayStr;
	switch (PlayerChoice){
		case 'R' :
		case 'r' : 
			PlayStr = ROCK; break;
		case 'P' : 
		case 'p' :
			PlayStr = PAPER; break;
		case 'S' : 
		case 's' :
			PlayStr = SCISSORS; break;
	}
		return PlayStr;

	}


int gameresult(Weapon PlayerWeapon, Weapon PCWeapon) {//function to determine winner and output results
    //  Return 1 for Player win, 2 for PC win, and 0 for tie

	if ((PlayerWeapon==PAPER) &&  (PCWeapon == ROCK))
        return 1;
    else if ((PlayerWeapon == PAPER) && (PCWeapon == SCISSORS))
        return 2; 
    else if ((PlayerWeapon == ROCK) &&  (PCWeapon == PAPER))
        return 2;
    else if ((PCWeapon == ROCK) && (PlayerWeapon == SCISSORS))
        return 2;  
    else if ((PCWeapon == PAPER) && (PlayerWeapon == SCISSORS))
         return 1;  
    else if ((PCWeapon == SCISSORS) &&  (PlayerWeapon == ROCK))
         return 1;  
	else  return 0; 	  
  
}
    	
    	
void winner (int game){
	
	
	//winstr = "";
	
	
	switch(game){
		
		case 0 :  cout << "IT IS A TIE ! You and the computer chose the same weapon." << endl; break;
		case 1:   cout << "YOU WIN!  " << endl; break;
		case 2:   cout << "COMPUTER WINS!" << endl; break;
	}
		
		/***
		
		winstr + "YOU WIN! ROCK CRUSHES SCISSORS!" ; break;
		case 2 :  winstr +"YOU WIN! SCISSORS CUT PAPER!" ; break;
		case 3 :  winstr +"YOU WIN! PAPER WRAPS ROCK!" ; break;
		case 4 :  winstr +"COMPUTER WINS! ROCK CRUSHES SCISSORS!" ; break;
		case 5 :  winstr +"COMPUTER WINS! SCISSORS CUT PAPER!" ; break;
		case 6 :  winstr +"COMPUTER WIN! PAPER WRAPS ROCK!" ; break;
		case 9 :  winstr +"THE GAME IS A TIE! YOU AND THE COMPUTER CHOSE THE SAME WEAPON!" ; break;
		
			}
		cout << winstr;
		
		***/
}
   

    
	  




	
int main(int argc, char** argv) {
	char PlayerChoice; //declare user input
    Weapon PlayerWeapon, PCWeapon;
    int result;
    int playerCount=0, compCount=0, tieCount=0;
    int val; // function for PC choice
    char reply;
    
   cout << "Would you like to play a game?" <<endl;
	cin >> reply;
	
    while (reply == 'y')
    {
    
	  Instruct(); //function to display instructions

	  cin >> PlayerChoice; //user input
	 PlayerWeapon = PlayItem(PlayerChoice);  //get the user chosen weapon

	 
	 val = randInt(3); //randomization of PC choice of 0, 1, or 2
	 PCWeapon = PCChoice (val);  //get PC chosen weapon

	 result = gameresult (PlayerWeapon, PCWeapon);  //function to determine winner
	 
	
	 
	 winner (result);
	 
	 
	 if (result==1) playerCount++;
	 else if (result==2) compCount++;
	 else tieCount++;
	
	cout << "Do you want to continue (y/n)? ";
	cin >> reply;
	}
	//cout << winstr;
	cout << "Player has won "<< playerCount << " times."<<endl;
	cout << "Computer has won  "<< compCount << " times."<<endl;
	cout << "The game was tied "<< tieCount << " times."<<endl;
	
	return 0;
}
