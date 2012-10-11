#include"deck.h"
#include<vector>


class hand{

	private:
		std::vector<card> a_hand;

	public:
		hand(): a_hand(std::vector<card>(10) ){};
		//hand(card a, card b);	//don't use this
		void build(card a, card b);		
		void add_card(card a);
		int score();
		void print();
		card get_card(int i);
};
