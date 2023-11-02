#include "HangmanGame.h"

void HangmanGame::Instruction()
{
	std::cout << "In this hangman game, guess the letters of a fruit, Each wrong guess could kill your player." << std::endl;
}

void HangmanGame::DrawScene(std::string& message)
{
	std::cout << "LIVES: " << this->Lives << std::endl;
	std::cout << "FRUIT TO GUESS IS: " << HiddenFruit << std::endl;
	if (Lives > 0) {
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
	else if (Lives == 0)
	{
		std::cout << "\t\t\t\t____________________" << std::endl;
		std::cout << "\t\t\t\t         |         |" << std::endl;
		std::cout << "\t\t\t\t         |         |" << std::endl;
		std::cout << "\t\t\t\t        O)         |" << std::endl;
		std::cout << "\t\t\t\t        / \\        |" << "           " << message << std::endl;
		std::cout << "\t\t\t\t         |         |" << "          /" << std::endl;
		std::cout << "\t\t\t\t     |  / \\  |      |         O" << std::endl;
		std::cout << "\t\t\t\t     |       |     |         / \\" << std::endl;
		std::cout << "\t\t\t\t     |       |     |     0    |" << std::endl;
		std::cout << "\t\t\t\t     |       |     |      \\  / \\" << std::endl;
		std::cout << "\t\t\t\t#############################################" << std::endl << std::endl;
	}
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
	CorrectGuesses = 0;
	int RandomFruitNumber = 0 + (std::rand() % GetTargetFruit().size());

	HiddenFruit = GetTargetFruit()[RandomFruitNumber];
	GuessFruit = HiddenFruit;
	length = GuessFruit.length();

	HideWord(HiddenFruit);
	DrawScene(GetMessage()[0]);

	Instruction();
}

void HangmanGame::NewGame()
{
	Initializing();
	do
	{
		if (Lives > 0)
		{
			InputGame();
			CheckGuess(DisplayMessageNumber);
			system("CLS");
			DrawScene(GetMessage()[DisplayMessageNumber]);

		}
		else if (Lives == 0)
		{
			system("CLS");
			DrawScene(GetMessage()[4]);
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
		for (int i = 0; i < length; i++)
		{
			fruit[i] = 'X';
		}
		hidden = true;
	}
}

void HangmanGame::UnhideWord(char c, int index, int& length)
{
	HiddenFruit[Index] = c;
	bool characterRevealed = false;

	if (hidden)
	{
		for (int i = 0; i < length; i++) {
			// Check if the guessed character is equal to the character at the current index
			if (GuessFruit[i] == c)
			{
				HiddenFruit[i] = c;
				CorrectGuesses++;
				characterRevealed = true;
			}
		}
	}

	if (characterRevealed) {
		if (CorrectGuesses == HiddenFruit.length())
		{
			system("CLS");
			DrawScene(GetMessage()[5]); // Display a winning message
			std::cout << "THE CORRECT ANSWER IS: " << HiddenFruit << std::endl;
			RestartGame();
		}
	}
}

void HangmanGame::CheckGuess(int& DisplayMessageNumber)
{
	for (int i = 0; i < length; i++)
	{
		if (Guess == GuessFruit[i])
		{
			srand(time(NULL));
			c = GuessFruit[i];
			Index = i;
			UnhideWord(c, i, length);
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
