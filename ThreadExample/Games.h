#pragma once
#include <iostream>
#include "NewGame.h"

class Games :public NewGame
{
private:
	int GameLoop = 1;

public:
	void ExitGame(int& GameLoop) { if (GameLoop == 0) std::cout << "EXITING..."; std::exit(0); };
	int GetGameLoop() { return GameLoop; }

	virtual void Instruction() = 0;
	virtual void NewGame() = 0;
	virtual void InputGame() = 0;

	void RestartGame()
	{
		std::cout << "\nDO YOU WANT TO PLAY AGAIN? (1/0)\n\n";

		std::cin >> GameLoop;

		if (GameLoop == 1)
		{
			system("CLS");
			NewGame();
		}
		else
		{
			ExitGame(GameLoop);
		}
	}
};