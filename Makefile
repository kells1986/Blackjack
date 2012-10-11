jk_blackjack: blackjack.o deck.o card.o hand.o
	g++ blackjack.o hand.o deck.o card.o -o jk_blackjack

blackjack.o: blackjack.cpp deck.o card.o hand.o
	g++ -c blackjack.cpp

hand.o: hand.cpp deck.o card.o
	g++ -c hand.cpp

deck.o: deck.cpp card.o
	g++ -c deck.cpp

card.o: card.cpp
	g++ -c card.cpp
