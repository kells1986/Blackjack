#include"deck.h"

using namespace std;

deck :: deck(bool shuffled){
	char suites[4] = {'s', 'c', 'h', 'd'};
	int count=0;

	for(int i=2; i <= 14; i++){

		for(int j=0; j < 4; j++){
		
		card a(i, suites[j]);
		array[count] = a;
		count += 1;

		}
	}


	if(shuffled){

		int position1, position2;
	card holding_card;
	int shuffle_max;
	shuffle_max = 593;


	for(int i = 0; i < shuffle_max; i++ )
	{	
	position1 = rand() % 52;
	position2 = rand() % 52;
	
	holding_card = array[position1];
	array[position1] = array[position2];
	array[position2] = holding_card;
	}

	}




	}

void deck :: shuffle(){

	int position1, position2;
	card holding_card;
	int shuffle_max;
	shuffle_max = 100;


	for(int i = 0; i < shuffle_max; i++ )
	{	
	position1 = rand() % 52;
	position2 = rand() % 52;
	
	holding_card = array[position1];
	array[position1] = array[position2];
	array[position2] = holding_card;
	}

}

card deck :: deal(){

	static int position = 0;
	position++;

	if(position == 52){
	position = 0;
	}

	return array[position - 1];
	}

void deck :: print(){
	
	for(int i=0; i < 52; i++){
	array[i].print();
	}

	} 



