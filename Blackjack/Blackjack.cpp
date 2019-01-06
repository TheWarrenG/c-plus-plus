#include <iostream>
#include "Card.h"
#include "Deck.h"

// The possible results of a game of Blackjack.
enum class gameResults
{
	LOSS,
	TIE,
	WIN
};

// Reads player's decision to hit or stand for one turn.
char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

// Deals card from DECK and adds card value to SCORE.
void dealCard(Deck &deck, int &score, int &numAces)
{
	score += deck.dealCard().getCardValue();
	while (score > 21 && numAces > 0)
	{
		score -= 10;
		numAces -= 1;
	}
}

// Plays one round of Blackjack with DECK. Returns result of game.
gameResults playBlackjack(Deck &deck)
{
	// Set up the initial game state.
	int playerTotal{ 0 };
	int dealerTotal{ 0 };
	int playerAces{ 0 };
	int dealerAces{ 0 };

	// Deal the dealer one card.
	dealCard(deck, dealerTotal, dealerAces);
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Deal the player two cards.
	dealCard(deck, playerTotal, playerAces);
	dealCard(deck, playerTotal, playerAces);

	// Player goes first.
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		dealCard(deck, playerTotal, playerAces);

		// See if the player busted.
		if (playerTotal > 21)
		{
			std::cout << "You have: " << playerTotal << '\n';
			return gameResults::LOSS;
		}
	}

	// If player hasn't busted, dealer goes until he has at least 17 points.
	while (dealerTotal < 17)
	{
		dealCard(deck, dealerTotal, dealerAces);
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// If dealer busted, player wins.
	if (dealerTotal > 21)
		return gameResults::WIN;
	else if (playerTotal > dealerTotal)
		return gameResults::WIN;
	else if (playerTotal < dealerTotal)
		return gameResults::LOSS;
	else
		return gameResults::TIE;
}

int main()
{
	Deck deck{};

	do
	{
		deck.shuffleDeck();
		gameResults result{ playBlackjack(deck) };

		switch (result)
		{
		case(gameResults::WIN):		std::cout << "You win!\n"; break;
		case(gameResults::LOSS):	std::cout << "You lose!\n"; break;
		case(gameResults::TIE):		std::cout << "Push!\n"; break;
		}

		char ans;
		do
		{
			std::cout << "Would you like to play again? (y/n) ";
			std::cin >> ans;
			std::cin.ignore(32767, '\n');
		} while (ans != 'y' && ans != 'n');

		if (ans == 'n')
			break;
	} while (true);

	std::cout << "Thank you for playing!\n";

	return 0;
}