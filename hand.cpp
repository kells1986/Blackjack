#include"hand.h"

using namespace std;


//hand(){
	//a_hand(vector<card>(10));
//	}

/*
hand :: hand(card a, card b){
	a_hand[0] = a;
	a_hand[1] = b;
	}
*/

void hand :: build(card a, card b){
	a_hand.resize(2);
	a_hand[0] = a;
	a_hand[1] = b;
	}


void hand :: add_card(card a){

	a_hand.push_back(a);
	}

int hand :: score(){

	int score = 0;
	
	//-----For loop with ace = 11 -------------------------------	

	for(int i = 0; i < a_hand.size(); i++){

	if( ((a_hand[i].get_val() >= 10)) && (a_hand[i].get_val() != 11)  ){
	a_hand[i].setval(10);
	}	

	if(a_hand[i].get_val() == 1){
	a_hand[i].setval(11);
	}
	

	//cout << "value of card " << a_hand[i].get_val() << endl;

	score += a_hand[i].get_val();
	}
	//-----------------------------------------------------------	


	//-----For loop for if ace = 11 gives score > 21--------------
	int i, j, k;
	vector<int> ace_address;
	i=0;
	j=0;
	k=0;	
	
	if( score > 21 ){
	score = 0;	
	

	//cout << "couting number of aces\n";
	while( j < a_hand.size()){

		if(a_hand[j].get_val() == 11){
		ace_address.push_back(j);
		}
	j++;
	}

	//cout << "aces counted, finding soft total score\n";
	
	if (ace_address.size() > 0){
	do{
		a_hand[ace_address[i]].setval(1);
		score = 0;
		for(k=0; k < a_hand.size(); k++){
		score += a_hand[k].get_val();
		}
	i++;
	
	}
	while( (score > 21) && ( i < ace_address.size() ) );
	}
	else
	{	
	score = 22;
	}

//	cout << "soft score loop completed\n";
	

	
	
	}
	//-------------------------------------------------------------

	return score;

	}

void hand :: print(){

	for(int i=0; i< a_hand.size(); i++){
	a_hand[i].print();
	cout << endl;	

	}
	}

card hand:: get_card(int i){
	return a_hand[i];
	}

