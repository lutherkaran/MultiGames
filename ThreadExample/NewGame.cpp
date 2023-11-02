#include "NewGame.h"
#include "NumberGuessGame.h"
#include "WordGuessGame.h"
#include "MillionaireGame.h"
#include "HangmanGame.h"
#include <iostream>

void NewGame::DisplayGamesList()
{
	std::cout << "\t\t\tWELCOME TO THE RANDOM GAMES PLEASE ENTER A NUMBER TO CHOOSE ANY GAME TO PLAY\n\n" << std::endl;

	GamesListMap[1] = "GUESS NUMBER";
	GamesListMap[2] = "WHO WANTS TO BE A MILLIONAIR?";
	GamesListMap[3] = "GUESS WORD";
	GamesListMap[4] = "HANGMAN";

	for (auto i : GamesListMap) {
		std::cout << "\t" << i.first << ".\t" << i.second << std::endl;
	}
	SelectGameToPlay();
}

void NewGame::SelectGameToPlay()
{
	try
	{
		std::cin >> SelectedGame;
		if (SelectedGame < 0 || SelectedGame>4)
		{
			throw(SelectedGame);
		}
		std::cout << "SelectedGame: " << GamesListMap[SelectedGame] << "\n\n\n" << std::endl;
		//std::this_thread::sleep_for(std::chrono::seconds(2));
	}
	catch (unsigned int SelectedNum)
	{
		std::cout << "You Must Enter a Positive Number and less than 5";
	}


	switch (SelectedGame)
	{
	case 1: StartNumberGuessGame(); break;
	case 2: StartMillionaireGame(); break;
	case 3: StartWordGuessGame(); break;
	case 4: StartHangmanGame(); break;

	default:
		break;
	}
}
void NewGame::StartHangmanGame()
{
	system("CLS");
	std::shared_ptr<HangmanGame> HangmanPtr = std::make_shared<HangmanGame>();
	std::thread HangmanThread(&HangmanGame::NewGame, HangmanPtr);

	if (HangmanThread.joinable())
	{
		HangmanThread.join();
	}
}

void NewGame::StartMillionaireGame()
{
	system("CLS");
	std::shared_ptr<MillionaireGame> MillionairePtr = std::make_shared<MillionaireGame>();
	std::thread MillionaireGameThead(&MillionaireGame::NewGame, MillionairePtr);

	if (MillionaireGameThead.joinable())
	{
		MillionaireGameThead.join();
	}
}

void NewGame::StartWordGuessGame()
{
	system("CLS");
	std::shared_ptr<WordGuessGame> WordGuessptr = std::make_shared<WordGuessGame>();
	std::thread WordGuessGameThread(&WordGuessGame::NewGame, WordGuessptr);

	if (WordGuessGameThread.joinable())
	{
		WordGuessGameThread.join();
	}
}

void NewGame::StartNumberGuessGame()
{
	system("CLS");
	std::shared_ptr<NumberGuessGame> NumberGuessptr = std::make_shared<NumberGuessGame>();
	std::thread NumberGuessGameThread(&NumberGuessGame::NewGame, NumberGuessptr);

	if (NumberGuessGameThread.joinable())
	{
		NumberGuessGameThread.join();
	}
}
