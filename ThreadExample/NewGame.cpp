#include "NewGame.h"
#include "NumberGuessGame.h"
#include "WordGuessGame.h"
#include <iostream>

void NewGame::DisplayGamesList()
{
	std::cout << "\t\t\tWELCOME TO THE RANDOM GAMES PLEASE ENTER A NUMBER TO CHOOSE ANY GAME TO PLAY\n\n" << std::endl;

	GamesList[1] = "GUESS NUMBER";
	GamesList[2] = "WHO WANTS TO BE A MILLIONAIR?";
	GamesList[3] = "GUESS WORD";

	for (auto i : GamesList) {
		std::cout << "\t" << i.first << ".\t" << i.second << std::endl;
	}
	SelectGame();
}

void NewGame::SelectGame()
{
	std::cin >> SelectedGame;
	std::cout << "SelectedGame: " << SelectedGame << "\n\n\n" << std::endl;

	if (SelectedGame == 1)
	{
		system("CLS");
		std::shared_ptr<NumberGuessGame> NumberGuessptr = std::make_shared<NumberGuessGame>();
		std::thread StartGame(&NumberGuessGame::NewGame, NumberGuessptr);

		if (StartGame.joinable())
		{
			StartGame.join();
		}
	}

	if (SelectedGame == 3)
	{
		system("CLS");
		std::shared_ptr<WordGuessGame> WordGuessptr = std::make_shared<WordGuessGame>();
		std::thread StartGame1(&WordGuessGame::NewGame, WordGuessptr);

		if (StartGame1.joinable())
		{
			StartGame1.join();
		}
	}
}