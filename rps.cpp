//============================================================================
// Name        : Rock-Paper-Scissors
// Author      : GloomyGeese
// Version     : 1.0
// Description : A rock paper scissors in c++
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int companswer;
string usrinput;
string compstring;
int usrpnt;
int compnt;
int gamenum;
string restart;

void usrwin(string usr, int comp) {
	if (comp==1){compstring="rock";} else if (comp==2){compstring="paper";}  else if (comp==3){compstring="scissors";} else {cout << "What did you do now? The computer's int can't be changed to a string to display in console. The computer probably chose a number not matching 1,2, or 3.";}
	cout << "You have won! You chose " << usr << " the computer chose " << compstring << "!" << endl;
}
void compwin(string usr, int comp) {
	if (comp==1){compstring="rock";} else if (comp==2){compstring="paper";}  else if (comp==3){compstring="scissors";} else {cout << "What did you do now? The computer's int can't be changed to a string to display in console. The computer probably chose a number not matching 1,2, or 3.";}
	cout << "The computer won. You chose " << usr << " the computer chose " << compstring << "!" << endl;
}
void tie(string usr, int comp) {
	if (comp==1){compstring="rock";} else if (comp==2){compstring="paper";}  else if (comp==3){compstring="scissors";} else {cout << "What did you do now? The computer's int can't be changed to a string to display in console. The computer probably chose a number not matching 1,2, or 3.";}
	cout << "You have tied! You both chose " << usr << "!" << endl;
}
int restartgame(){
	cout << "Would you like to play again? Y for yes N for no.";
	cin >> restart;
	if (restart=="y" || restart=="Y") {cout << "Resetting game." << endl; return 1;}
	else if (restart=="n" || restart=="N") {cout << "Well yeah you also suck too."; return 0;}
	else {cout << "Not a valid character! Closing anyways."; return 0;}
	return -1;
}


int main() {
	usrpnt = 0;
	compnt = 0;
	srand ( time(NULL) );
	while (usrpnt<3 && compnt<3) {
	cout << "Choose rock paper or scissors!" << endl; // prints !!!Hello World!!!
	companswer = rand() % 3 + 1;
	cin >> usrinput;
	transform(usrinput.begin(), usrinput.end(), usrinput.begin(), ::tolower);
	switch (companswer) {
	case 1:
		//comp rock
		if (usrinput=="rock"){tie(usrinput, companswer);}
		else if (usrinput=="paper") {usrwin(usrinput, companswer); usrpnt++; gamenum++;}
		else if (usrinput=="scissors") {compwin(usrinput, companswer); compnt++; gamenum++;}
		break;
	case 2:
		// comp paper
		if (usrinput=="rock") {compwin(usrinput, companswer); compnt++; gamenum++;}
		else if (usrinput=="paper") {tie(usrinput, companswer);}
		else if (usrinput=="scissors") {usrwin(usrinput, companswer); usrpnt++; gamenum++;}
		break;
	case 3:
		// comp scissors
		if (usrinput=="rock") {usrwin(usrinput, companswer); usrpnt++; gamenum++;}
		else if (usrinput=="paper") {compwin(usrinput, companswer); compnt++; gamenum++;}
		else if (usrinput=="scissors") {tie(usrinput, companswer);}
		break;
	}
	if (usrpnt<3 && compnt<3) {
	cout << "You have " << usrpnt << " points, the computer has " << compnt << " points.";
	}
	else if (usrpnt==3) {cout << "YOU HAVE BEATEN THE COMPUTER! SO PROUD!!!" << endl; if(restartgame()==1) {usrpnt=0; compnt=0;}}
	else if (compnt==3) {cout << "You have lost to the computer. I had faith in you." << endl; if(restartgame()==1) {usrpnt=0; compnt=0;}}
	}


	return 0;
}

