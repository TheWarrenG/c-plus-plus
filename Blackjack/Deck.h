#pragma once
#ifndef DECK_H
#define DECK_H
#include <array>
#include <cassert>
#include "Card.h"

// A standard deck of 52 cards.
class Deck
{
private:
	std::array<Card, 52> m_deck;
	int m_cardIndex{ 0 };

	// Swap the value of two cards.
	static void swapCard(Card &a, Card &b)
	{
		Card temp = a;
		a = b;
		b = temp;
	}

public:
	Deck();

	// Prints M_DECK in two letter codes.
	void printDeck() const;

	// Permutes M_DECK.
	void shuffleDeck();

	// Deals card at M_CARDINDEX in DECK.
	const Card& dealCard()
	{
		assert(m_cardIndex < 52);
		return m_deck[m_cardIndex++];
	}
};

#endif