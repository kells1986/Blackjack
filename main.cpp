//#include"card.h"
#include"deck.h"

using namespace std;

int main(){


deck card_deck(true);
card one;
int v1, v2;
char d;
card two;

int i = 2;
//card_deck.shuffle();

one = card_deck.deal();
two = card_deck.deal();

one.print();
two.print();

while((i <= 52) && (v1 != v2)){

v1 = one.get_val();
v2 = two.get_val();

one = two;
two = card_deck.deal();
two.print();

i += 1;
}



if (i==53){

cout << "we got through the whole deck with getting a match!!!\n";
}
else{
cout << "SNAP!!! \n";
}

return 0;
}
