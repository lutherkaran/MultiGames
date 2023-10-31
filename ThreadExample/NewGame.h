#pragma once
#include <unordered_map>
#include <mutex>

class NewGame
{
private:
	std::unordered_map<int, std::string> GamesList;
	int SelectedGame = 0;

public:
	void DisplayGamesList();
	void SelectGame();
};