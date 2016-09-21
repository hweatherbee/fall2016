#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;


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
			PCstr = ROCK; cout << "Computer chooses a ROCK.." <<endl; break;
		case 1 : 
			PCstr = PAPER; cout << "Computer chooses PAPER.." <<endl; break;
		case 2 : 
			PCstr = SCISSORS; cout << "Computer chooses SCISSORS.." <<endl; break;
	}
      return PCstr;	

}	
void Instruct(){//Game instructions

cout << "WELCOME TO PAPER-ROCK-SCISSORS!" <<endl;

    cout << "This is a game for two players.  You will be playing against the computer. " <<endl;
            
	cout << "With each game, both players will select one of the following weapons: PAPER, ROCK, or SCISSORS." <<endl;
	cout << endl;
	cout <<  "* If both players select the same weapon, the game is a tie." <<endl;
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
			PlayStr = ROCK; cout << "You chose a ROCK..";break;
		case 'P' : 
		case 'p' :
			PlayStr = PAPER; cout << "You chose PAPER..";break;
		case 'S' : 
		case 's' :
			PlayStr = SCISSORS; cout << "You chose SCISSORS..";break;
	}
		return PlayStr;

	}


int gameresult(Weapon PlayerWeapon, Weapon PCWeapon) {//function to determine winner and output results
    

	if ((PlayerWeapon == ROCK) && (PCWeapon == PAPER))
        return 1;
    else if ((PlayerWeapon == ROCK) &&  (PCWeapon == SCISSORS))
        return 2;
    else if ((PlayerWeapon == PAPER) && (PCWeapon == ROCK))
        return 3; 
    else if ((PlayerWeapon == PAPER) &&  (PCWeapon == SCISSORS))
        return 4;
    else if ((PlayerWeapon == SCISSORS) &&  (PCWeapon == ROCK))
        return 5; 
	else if ((PlayerWeapon == SCISSORS) &&  (PCWeapon == PAPER))
        return 6;    
   
	else  return 0; 	  
  
}
    	
    	
void winner (int game){
	
		switch(game){
		
		case 0 :  cout << "IT IS A TIE ! You and the computer chose the same weapon." << endl; break;
		case 1:   cout << "YOU LOSE! Paper wraps rock! " << endl; break;
		case 2:   cout << "YOU WIN Rock blunts scissors!" << endl; break;
		case 3 :  cout << "YOU WIN! Paper wraps rock! " << endl; break;
		case 4:   cout << "YOU LOSE! Scissors cut paper!" << endl; break;
		case 5:  cout << "YOU LOSE! Rock blunts scissors!" << endl; break;
		case 6:   cout << "YOU WIN! Scissors cut paper!" << endl; break;
		
	}
		
}
   
	
int main(int argc, char** argv) {
	char PlayerChoice; // user input
    Weapon PlayerWeapon, PCWeapon;
    int result;
    int playerCount=0, compCount=0, tieCount=0;
    int val; // function for PC choice
    char reply;
    
   cout << "Would you like to play a game of ROCK/PAPER/SCISSORS?" <<endl; 
   cout <<  "Please enter y for yes and n for no: " <<endl;
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
	
	  cout << "Would you like to play another game? (y/n)? ";
	  cin >> reply;
	}
	
	cout << "_____________________________________" << endl;
	cout << "Player has won "<< playerCount << " times."<<endl;
	cout << "Computer has won  "<< compCount << " times."<<endl;
	cout << "The game was tied "<< tieCount << " times."<<endl;
	
	return 0;
}
