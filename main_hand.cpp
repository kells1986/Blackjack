//#include"card.h"
#include"hand.h"



using namespace std;

int main(){


deck card_deck(true);
cout << "deck declared \n";

card one;
int v1, v2;

card two;
//card_deck.shuffle();


card_deck.print();
one = card_deck.deal();

two = card_deck.deal();



cout <<"------------------Dealing a hand--------------\n";

hand players_hand;
players_hand.build(one, two);



while(players_hand.score() < 17){
players_hand.add_card(card_deck.deal());
}

cout << "printing hand \n";
players_hand.print();



cout << "score = " << players_hand.score() << endl;
cout << "-----------------------------------------------\n";

cout << "----------Making an artifical hand to test my scoring with ace--------\n";

hand artificial;
card a, b, c, d, e, f, g, h, i, j;
a.setval(1);
a.setsuit('c');

b.setval(1);
b.setsuit('c');

c.setval(1);
c.setsuit('c');

d.setval(1);
d.setsuit('c');

e.setval(1);
e.setsuit('c');

f.setval(1);
f.setsuit('c');

g.setval(1);
g.setsuit('c');

h.setval(1);
h.setsuit('c');

i.setval(1);
i.setsuit('c');

j.setval(1);
j.setsuit('c');



artificial.build(a, b);
artificial.add_card(c);
artificial.add_card(d);
artificial.add_card(e);
artificial.add_card(f);
artificial.add_card(g);
artificial.add_card(h);
artificial.add_card(i);
artificial.add_card(j);
artificial.print();

cout << "artificial score: " << artificial.score() << endl;

cout << "-----------------------------End------------------------------\n";


return 0;
}
