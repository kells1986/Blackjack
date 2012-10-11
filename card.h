#include<iostream>
#include<string>


class card{

	private:
		int value;
		char suit;

	public:
		card() {}
		card(int v, char s);
		void setval(int val);
		void setsuit(char s);
		int get_val();
		char get_suit();
		void print();



	};	

