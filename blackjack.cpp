#include"hand.h"
#include<cstdlib>
#include<unistd.h>


using namespace std;
void prepare_gui();
void user_options();


int main(){

int user_input;
int playagain;
int credit = 100;
int bet = 1;
bool double_test;
int double_taken;


deck blackjack_deck(true); //provides a shuffled deck of cards
hand user, dealer; //prepares a vector for the deal and users cards

card a, b, c, d;


do{
a=blackjack_deck.deal();
b=blackjack_deck.deal();
c=blackjack_deck.deal();
d=blackjack_deck.deal();

dealer.build(b, d);
user.build(a, c);

prepare_gui();

double_test=false;

cout << "|---------Place Your Bets-----------------\n";
cout << "|					   \n";
cout << "|  you have "<< credit <<"                       \n";
cout << "|  how much would you like to bet?        \n";
do{
cin >> bet;
	if(bet > credit){
		cout << "Sorry, you can't afford that\nhow much would you like to bet?\n";
	}
}while(bet > credit);

cout << "-----------------------------------------------\n";
cout << "\n";
cout << "Dealer is showing \n";
dealer.get_card(0).print();
//cout << "score = "  << endl;

if (dealer.get_card(0).get_val() <= 11){
	cout << "Score = " << dealer.get_card(0).get_val() << endl;
}
else {
	cout << "Score = 10" << endl; 
}
cout << "-----------------------------------------------\n";


cout << "You Have \n"; 
user.print();
cout << "Score = " << user.score() << endl;
cout << "----------------------------------------------------\n";

if( (user.score() < 12) && (user.score() > 7) ){
cout << "would you like to double?\n";
cin >> double_taken;
if(double_taken==1){
double_test=true;
} 
}

if(double_test == true){
bet=2*bet;
user.add_card(blackjack_deck.deal());
user.print();
cout << "your score is: " << user.score() << "\n";

}



if(!double_test){
user_options();
cin >> user_input;
}


while( (user_input == 1) && (user.score() < 22) && (double_test==false) ){

user.add_card(blackjack_deck.deal());
user.print();
cout << "score = " << user.score() << " \n \n";
	if(user.score() < 22){
	user_options();
	cin >> user_input;
	}
}


if(user.score() > 21){
cout << "user BUST!\t Dealer wins\n";
credit -= bet;
}
else{

while( dealer.score() < 17 ){

dealer.add_card(blackjack_deck.deal());

sleep(1);
dealer.print();

cout << "score = " << dealer.score() << endl;
}

//cout << "out of while loop for dealer\n";


cout << "your score : " << user.score() << endl;
cout << "dealer score : " << dealer.score() << endl;

int play_win=0;
if( ( (user.score() > dealer.score()) && (user.score() < 22) ) || ( (user.score() < 22) && (dealer.score() > 21) ) ) {
cout << "player wins!!!\n";
credit += bet;
play_win = 2;
}
	if(user.score() == dealer.score()){
	cout << "Push!!!\n";
	play_win=1;	
	}
	if((play_win != 2) && (play_win != 1) ){ 
	cout << "Dealer wins!!!\n";
	credit-= bet;	
	}
}
cout << endl;
cout << "CREDIT:\t" << credit << endl;


cout << "play again? (1 = yes, 0 = no)\n";
cin >> playagain;
}
while((playagain == 1) && (credit > 0));
cout << "Thanks for playing!\n";
return 0;
}

void prepare_gui(){

cout << "***********************************************\n";
cout << "*             JK's Blackjack                  *\n";
cout << endl << endl;

}


void user_options(){

cout << "What do you want to do?\n";
cout << "1 - hit, 0 - stand\n";
}
