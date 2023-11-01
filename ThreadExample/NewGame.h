#pragma once
#include <unordered_map>
#include <mutex>

class NewGame
{
private:
	std::unordered_map<int, std::string> GamesListMap;
	unsigned int SelectedGame = 0;
public:
	void DisplayGamesList();
	void SelectGameToPlay();
	void StartWordGuessGame();
	void StartNumberGuessGame();
	void StartMillionaireGame();
};
