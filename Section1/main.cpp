#include <iostream>
#include <string>
#include <utility>
#include <array>

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

	return 0;

}