#include <iostream>
#include "MillionaireGame.h"

void MillionaireGame::Initializing()
{
	QAMap.insert(std::make_pair('a', QuestionStruct{
	   "Grand Central Terminal, Park Avenue, New York is the world's?",
		{ "largest railway station", "highest railway station", "longest railway station", "None of the above" },
	   1000 }));

	QAMap.insert(std::make_pair('b', QuestionStruct{
			"Entomology is the science that studies",
			{ "Behavior of human beings", "Insects", "The origin and history of technical and scientific terms", "The formation of rocks" },
			2000 }));

	QAMap.insert(std::make_pair('b', QuestionStruct{
		"Eritrea, which became the 182nd member of the UN in 1993, is in the continent of",
		{ "Asia", "Africa", "Europe", "Australia" },
		5000 }));

	QAMap.insert(std::make_pair('b', QuestionStruct{
		"Garampani sanctuary is located at",
		{ "Junagarh, Gujarat", "Diphu, Assam", "Kohima, Nagaland", "Gangtok, Sikkim" },
		10000 }));

	QAMap.insert(std::make_pair('d', QuestionStruct{
		"For which of the following disciplines is Nobel Prize awarded?",
		{ "Physics And Chemistry", "Psychology and Medicine", "Literature, Peace and Economics", "All of the above" },
		50000 }));

	QAMap.insert(std::make_pair('c', QuestionStruct{
		"The latitudinal differences in pressure delineate a number of major pressure zones, which correspond with",
		{ "zones of cyclonic depressions", "Zones of land", "Zones of climate", "zones of ocean" },
		120000 }));

	QAMap.insert(std::make_pair('d', QuestionStruct{
		"The great Victoria Desert is located in?",
		{ "Canada", "India", "Europe", "Australia" },
		360000 }));

	QAMap.insert(std::make_pair('a', QuestionStruct{
		".MOV' extension refers usually to what kind of file?",
		{ "Animation or Movie file", "Image File", "Audio File", "MS Office Document" },
		640000 }));

	QAMap.insert(std::make_pair('a', QuestionStruct{
		"In which decade was the American Institute of Electrical Engineers (AIEE) founded?",
		{ "1880s", "1990s", "1780s", "2000s"},
		1250000 }));

	QAMap.insert(std::make_pair('c', QuestionStruct{
		"What is part of a database that holds only one type of information?",
		{ "Report", "Record", "Field" ,"File" },
		5000000 }));
}

void MillionaireGame::Instruction()
{
	std::cout << "\t\t\t\tWELCOME TO THE ## WHO WANTS TO BE A MILLIONAIRE ## GAME\n\n\n\n" << std::endl;
}

void MillionaireGame::NewGame()
{
	Instruction();
	Initializing();

	do
	{
		int i = 0;

		for (const auto& a : QAMap)
		{
			char j = 96;
			std::cout << ++i << ") " << a.second.Question << "\n";

			for (const auto& b : a.second.Answers)
			{
				std::cout << "\t" << ++j << ") " << b << std::endl;
			}

			InputGame();
			if (Ans != a.first)
			{
				std::cout << "SORRY, YOU'VE LOST THE GAME :(" << std::endl;
				RestartGame();
			}
			else
			{
				std::cout << "CORRECT ANSWER: YOU WON: " << a.second.PrizeMoney << std::endl;
			}
		}
		RestartGame();

	} while (GetGameLoop() != 0);
}

void MillionaireGame::InputGame()
{
	std::cin >> Ans;
}
