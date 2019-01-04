#include <iostream>
#include <string>
#include <utility>
#include <array>
#include <random>
#include <ctime>

enum CardRank
{
	RANK_2, RANK_3, RANK_4,
	RANK_5, RANK_6, RANK_7,
	RANK_8, RANK_9, RANK_10,
	RANK_JACK, RANK_QUEEN,
	RANK_KING, RANK_ACE,
	MAX_RANKS
};

enum CardSuit
{
	SUIT_CLUBS,
	SUIT_DIAMONDS,
	SUIT_HEARTS,
	SUIT_SPADES,
	MAX_SUITS
};

struct Card
{
	CardRank rank;
	CardSuit suit;
};

void printCard(const Card &card)
{
	char rank;
	switch (card.rank)
	{
	case(RANK_2):		rank = '2'; break;
	case(RANK_3):		rank = '3'; break;
	case(RANK_4):		rank = '4'; break;
	case(RANK_5):		rank = '5'; break;
	case(RANK_6):		rank = '6'; break;
	case(RANK_7):		rank = '7'; break;
	case(RANK_8):		rank = '8'; break;
	case(RANK_9):		rank = '9'; break;
	case(RANK_10):		rank = 'T'; break;
	case(RANK_JACK):	rank = 'J'; break;
	case(RANK_QUEEN):	rank = 'Q'; break;
	case(RANK_KING):	rank = 'K'; break;
	case(RANK_ACE):		rank = 'A'; break;
	}

	char suit;
	switch (card.suit)
	{
	case(SUIT_CLUBS):		suit = 'C';	break;
	case(SUIT_DIAMONDS):	suit = 'D';	break;
	case(SUIT_HEARTS):		suit = 'H';	break;
	case(SUIT_SPADES):		suit = 'S';	break;
	}
	std::cout << rank << suit;
}

void printDeck(const std::array<Card, 52> &deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}

void swapCard(Card &x, Card &y)
{
	Card temp = x;
	x = y;
	y = temp;
}

void shuffleDeck(std::array<Card, 52> &deck)
{
	using index_t = std::array<Card, 52>::size_type;
	std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
	std::uniform_int_distribution<> die(0, 51);

	for (index_t deckIndex = 0; deckIndex < 52; ++deckIndex)
	{
		int swapIndex = die(mersenne);
		swapCard(deck[deckIndex], deck[swapIndex]);
	}
}

int getCardValue(const Card &card)
{
	switch (card.rank)
	{
	case(RANK_2):		return 2;
	case(RANK_3):		return 3;
	case(RANK_4):		return 4;
	case(RANK_5):		return 5;
	case(RANK_6):		return 6;
	case(RANK_7):		return 7;
	case(RANK_8):		return 8;
	case(RANK_9):		return 9;
	case(RANK_10):		return 10;
	case(RANK_JACK):	return 10;
	case(RANK_QUEEN):	return 10;
	case(RANK_KING):	return 10;
	case(RANK_ACE):		return 11;
	}

	return 0;
}

void addScore(int &score, Card* &cardPtr, int &numAces)
{
	int scoreChange = getCardValue(*cardPtr++);
	if (scoreChange == 11)
		numAces += 1;
	score += scoreChange;
	while (score > 21 && numAces > 0)
	{
		score -= 10;
		numAces -= 1;
	}
}

void playBlackjack(std::array<Card, 52> &deck)
{
	Card *cardPtr = &(deck[0]);

	int dealerScore{ 0 };
	int playerScore{ 0 };
	int playerAces{ 0 };
	int dealerAces{ 0 };

	addScore(dealerScore, cardPtr, dealerAces);
	addScore(playerScore, cardPtr, playerAces);
	addScore(playerScore, cardPtr, playerAces);
	
	std::cout << "Let's play one round of Blackjack!\n";
	std::cout << "Your current score is: " << playerScore << '\n';
	std::cout << "The dealer's current score is: " << dealerScore << '\n';
	while (playerScore < 21)
	{
		std::string playerAction;
		do
		{
			std::cout << "Would you like to hit or stand? ";
			std::cin >> playerAction;
		} while (playerAction != "hit" && playerAction != "stand");

		if (playerAction == "hit")
		{
			addScore(playerScore, cardPtr, playerAces);
			std::cout << "Your current score is: " << playerScore << '\n';
		}
		else
			break;
	}

	if (playerScore > 21)
	{
		std::cout << "You bust! Dealer wins.\n";
		return;
	}

	while (dealerScore < 17)
	{
		addScore(dealerScore, cardPtr, dealerAces);
		std::cout << "The dealer's current score is: " << dealerScore << '\n';
	}

	if (dealerScore > 21)
	{
		std::cout << "Dealer busts! You win.\n";
		return;
	}
	else if (playerScore > dealerScore)
	{
		std::cout << "You win!\n";
		return;
	}
	else if (playerScore == dealerScore)
	{
		std::cout << "You tie!\n";
		return;
	}
	else {
		std::cout << "Dealer wins! You lose.\n";
		return;
	}
}

int main()
{
	std::array<Card, 52> deck;
	using index_t = std::array<Card, 52>::size_type;
	index_t deckIndex{ 0 };
	for (int rankIndex = 0; rankIndex < MAX_RANKS; ++rankIndex)
	{
		for (int suitIndex = 0; suitIndex < MAX_SUITS; ++suitIndex)
		{
			deck[deckIndex] = { static_cast<CardRank>(rankIndex), static_cast<CardSuit>(suitIndex) };
			++deckIndex;
		}
	}

	shuffleDeck(deck);
	playBlackjack(deck);

	return 0;
}