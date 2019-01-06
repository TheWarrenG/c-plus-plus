#include <iostream>
#include <random>
#include <ctime>
#include "Card.h"
#include "Deck.h"

Deck::Deck()
{
	// Initialize each card in M_DECK.
	int card = 0;
	for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
		for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
		{
			m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
			++card;
		}
}

void Deck::printDeck() const
{
	for (const auto &card : m_deck)
	{
		card.printCard();
		std::cout << ' ';
	}

	std::cout << '\n';
}

void Deck::shuffleDeck()
{
	// Initialize our mersenne twister with a random seed based on the clock.
	std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));

	// Create a reusable random number generator that generates uniform numbers between MIN and MAX.
	std::uniform_int_distribution<> die(0, 51);

	// Step through each card in the deck.
	for (int index = 0; index < 52; ++index)
	{
		// Pick a random card.
		int swapIndex = die(mersenne);
		// Swap it with the current card.
		swapCard(m_deck[index], m_deck[swapIndex]);
	}

	m_cardIndex = 0;
}