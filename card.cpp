#include"card.h"


using namespace std;

card :: card(int v, char s){
	value = v;
	suit = s;
	}
	
void card :: setval(int val){
	value = val;
	}

void card :: setsuit(char s){
	suit = s;
	}

int card :: get_val(){
	return value;
	}

char card :: get_suit(){
	return suit;
	}

void card:: print(){

	string v, s;

	switch(value){
	case 1: v="ace";
	break;

	case 2: v="two";
	break;

	case 3: v="three";
	break;

	case 4: v="four";
	break;

	case 5: v="five";
	break;

	case 6: v="six";
	break;

	case 7: v="seven";
	break;

	case 8: v="eight";
	break;

	case 9: v="nine";
	break;

	case 10: v="ten";
	break;

	case 11: v="ace";
	break;

	case 12: v="jack";
	break;

	case 13: v="queen";
	break;

	case 14: v="king";
	break;
	}

	switch(suit){

	case 'c': s = "clubs";
	break;

	case 'd': s = "diamonds";
	break;

	case 'h': s = "hearts";
	break;

	case 's': s= "spades";
	break;
	}



	cout << v << "\t" << s << endl;



	}







	
