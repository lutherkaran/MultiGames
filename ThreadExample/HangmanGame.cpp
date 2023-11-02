#include "HangmanGame.h"

void HangmanGame::Instruction()
{
	std::cout << "In this hangman game, guess the letters of a fruit, Each wrong guess could kill your player." << std::endl;
}

void HangmanGame::DrawMan(std::string& message)
{
	std::cout << "LIVES: " << this->Lives;

	std::cout << "\t\t\t\t____________________" << std::endl;
	std::cout << "\t\t\t\t         |         |" << std::endl;
	std::cout << "\t\t\t\t         O         |" << std::endl;
	std::cout << "\t\t\t\t        / \\        |" << "           " << message << std::endl;
	std::cout << "\t\t\t\t         |         |" << "          /" << std::endl;
	std::cout << "\t\t\t\t        / \\        |         O" << std::endl;
	std::cout << "\t\t\t\t     =========     |         / \\" << std::endl;
	std::cout << "\t\t\t\t     |       |     |     0    |" << std::endl;
	std::cout << "\t\t\t\t     |       |     |    /    / \\" << std::endl;
	std::cout << "\t\t\t\t#############################################" << std::endl << std::endl;
}

void HangmanGame::Initializing()
{
	srand(time(NULL));
	Lives = 3;
	hidden = false;
	c = '\0';
	Index = 0;
	hidden = false;
	DisplayMessageNumber = 0;
	int RandomFruitNumber = 0 + (std::rand() % GetTargetFruit().size());

	DrawMan(GetMessage()[0]);
	Instruction();

	HiddenFruit = GetTargetFruit()[RandomFruitNumber];
	GuessFruit = HiddenFruit;
}

void HangmanGame::NewGame()
{
	Initializing();
	do
	{
		if (Lives > 0)
		{
			HideWord(HiddenFruit);
			InputGame();
			CheckGuess(DisplayMessageNumber);
			system("CLS");
			DrawMan(GetMessage()[DisplayMessageNumber]);

		}
		else if (Lives == 0)
		{
			system("CLS");
			DrawMan(GetMessage()[4]);
			std::cout << "CORRECT ANSWER IS: " << GuessFruit << std::endl;
			RestartGame();
		}

	} while (GetGameLoop() != 0);
}

void HangmanGame::InputGame()
{
	std::cin >> Guess;
	Guess = toupper(Guess);
}

void HangmanGame::HideWord(std::string& fruit)
{
	if (!hidden)
	{
		for (int i = 0; i < fruit.length(); i++)
		{
			fruit[i] = 'X';
		}
		hidden = true;
	}
	std::cout << "FRUIT TO GUESS: " << fruit << std::endl;
}

void HangmanGame::UnhideWord(char C, char Guess, int Index)
{
	if (hidden)
	{
		if (Guess == c)
		{
			HiddenFruit[Index] = c;
		}
	}
}

void HangmanGame::CheckGuess(int& DisplayMessageNumber)
{
	for (int i = 0; i < GuessFruit.length(); i++)
	{
		if (Guess == GuessFruit[i])
		{
			srand(time(NULL));
			c = GuessFruit[i];
			Index = i;
			UnhideWord(c, Guess, i);
			DisplayMessageNumber = 1 + (std::rand() % 2);
			break;
		}
	}
	if (Guess != c)
	{
		Lives--;
		DisplayMessageNumber = 3;
	}
}
