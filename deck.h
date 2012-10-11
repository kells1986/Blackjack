#include"card.h"
#include<cstdlib>

class deck{

	private:
		card array[52];

	public:
		deck(){}
		deck(bool shuffled);		
		void shuffle();
		card deal();
		void print();

};
