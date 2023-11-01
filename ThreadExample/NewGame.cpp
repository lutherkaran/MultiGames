#include "NewGame.h"
#include "NumberGuessGame.h"
#include "WordGuessGame.h"
#include "MillionaireGame.h"
#include <iostream>

void NewGame::DisplayGamesList()
{
	std::cout << "\t\t\tWELCOME TO THE RANDOM GAMES PLEASE ENTER A NUMBER TO CHOOSE ANY GAME TO PLAY\n\n" << std::endl;

	GamesListMap[1] = "GUESS NUMBER";
	GamesListMap[2] = "WHO WANTS TO BE A MILLIONAIR?";
	GamesListMap[3] = "GUESS WORD";

	for (auto i : GamesListMap) {
		std::cout << "\t" << i.first << ".\t" << i.second << std::endl;
	}
	SelectGameToPlay();
}

void NewGame::SelectGameToPlay()
{
	std::cin >> SelectedGame;
	std::cout << "SelectedGame: " << GamesListMap[SelectedGame] << "\n\n\n" << std::endl;

	switch (SelectedGame)
	{
	case 1: StartNumberGuessGame(); break;
	case 2: StartMillionaireGame(); break;
	case 3: StartWordGuessGame(); break;

	default:
		break;
	}
}

void NewGame::StartMillionaireGame()
{
	system("CLS");
	std::shared_ptr<MillionaireGame> MillionairePtr = std::make_shared<MillionaireGame>();
	std::thread StartGame3(&MillionaireGame::NewGame, MillionairePtr);

	if (StartGame3.joinable())
	{
		StartGame3.join();
	}
}

void NewGame::StartWordGuessGame()
{
	system("CLS");
	std::shared_ptr<WordGuessGame> WordGuessptr = std::make_shared<WordGuessGame>();
	std::thread StartGame1(&WordGuessGame::NewGame, WordGuessptr);

	if (StartGame1.joinable())
	{
		StartGame1.join();
	}
}

void NewGame::StartNumberGuessGame()
{
	system("CLS");
	std::shared_ptr<NumberGuessGame> NumberGuessptr = std::make_shared<NumberGuessGame>();
	std::thread StartGame(&NumberGuessGame::NewGame, NumberGuessptr);

	if (StartGame.joinable())
	{
		StartGame.join();
	}
}
