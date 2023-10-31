#include <iostream>
#include <thread>
#include <memory>
#include "NewGame.h"

int main()
{
	std::shared_ptr<NewGame> GamePtr = std::make_shared<NewGame>();
	std::cout << "PRESS 0 TO EXIT..!!\n\n\n\n\n\n\n" << std::endl;
	std::thread GameThread(&NewGame::DisplayGamesList, GamePtr);

	if (GameThread.joinable())
	{
		GameThread.join();
	}
	return 0;
}