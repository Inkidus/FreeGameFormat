#include <iostream>
#include <string>
using namespace std;


class Game
{
public:
	Game();
	//Constructor sets theURL and theName to a user input
	string getURL();
	//Returns the URL stored in theURL
	string getName();
	//Returns the name stored in theName
private:
	string theURL;
	string theName;
};

class storedGames
{
public:
	storedGames();
	//Prompts the user to add games to the class
	void getFinalOutput();
	//Outputs the stored games in the final format to be pasted elsewhere
	void printList(Game *storeType, int size, string storeName);
	//Outputs a list of the free games from a single store
	Game* addGame(int &size, string storeName);
	//Sets the size of an array storing the free games from a single store and returns a pointer to that array
private:
	Game *SteamGames = nullptr;
	Game *EpicGames = nullptr;
	Game *gogGames = nullptr;
	Game *HumbleBundleGames = nullptr;
	Game *itchioGames = nullptr;
	Game *IndiegalaGames = nullptr;
	int steamGameCount = 0;
	int epicGameCount = 0;
	int gogGameCount = 0;
	int humbleGameCount = 0;
	int itchGameCount = 0;
	int IndiegalaGameCount = 0;
};


bool ContinueCheck();
//Returns true or false depending on the user's response to a prompt asking if games from another store will be added


int main()
{
	char endprogram;
	storedGames gameList;
	gameList.getFinalOutput();

	cout << "Enter any character to end the program ";
	cin >> endprogram;

	return 0;
}


bool ContinueCheck()
{
	char userChoice;
	cout << "Would you like to add games from another store? (y/n) ";
	cin >> userChoice;

	cout << endl << endl;

	do
	{
		switch (userChoice)
		{
		case 'y':
			return true;
		case 'n':
			return false;
		}
	} while (true);
}

Game::Game()
{
	cout << "Enter the game's URL: ";
	getline(cin, theURL);

	cout << "Enter the game's title: ";
	getline(cin, theName);
}

string Game::getURL()
{
	return theURL;
}

string Game::getName()
{
	return theName;
}

storedGames::storedGames()
{
	char userChoice;
	cout << "Welcome to the Free Game Formatter v1.0\n";

	do
	{
		cout << "The following options are available:\nSteam: s\nEpic: e\ngog: g\nHumble Bundle: h\nitch.io: i\nIndiegala: I\n\nEnter Character: ";
		cin >> userChoice;

		switch (userChoice)
		{
		case 's':
			SteamGames = addGame(steamGameCount, "Steam");
			break;
		case 'e':
			EpicGames = addGame(epicGameCount, "Epic");
			break;
		case 'g':
			gogGames = addGame(gogGameCount, "gog");
			break;
		case 'h':
			HumbleBundleGames = addGame(humbleGameCount, "Humble Bundle");
			break;
		case 'i':
			itchioGames = addGame(itchGameCount, "itch.io");
			break;
		case 'I':
			IndiegalaGames = addGame(IndiegalaGameCount, "Indiegala");
			break;
		}

	} while (ContinueCheck());
}

Game* storedGames::addGame(int &size, string storeName)
{
	cout << "How many " << storeName << " games would you like to store? ";
	cin >> size;
	cin.ignore(5, '\n');

	return new Game[size];
}

void storedGames::getFinalOutput()
{
	cout << "Here are your free games:\n";
	printList(SteamGames, steamGameCount, "Steam");
	printList(EpicGames, epicGameCount, "Epic");
	printList(gogGames, gogGameCount, "gog");
	printList(HumbleBundleGames, humbleGameCount, "Humble Bundle");
	printList(itchioGames, itchGameCount, "itch.io");
	printList(IndiegalaGames, IndiegalaGameCount, "Indiegala");
}

void storedGames::printList(Game *storeType, int size, string StoreName)
{
	if (size > 2)
	{
		for (int i = 0; i < (size - 1); i++)
		{
			cout << storeType[i].getName() << ", ";
		}
		cout << "and " << storeType[size - 1].getName() << " are free on " << StoreName << endl;
	}
	else if (size == 2)
	{
		cout << storeType[0].getName() << " and " << storeType[1].getName() << " are free on " << StoreName << endl;
	}
	else if (size == 1)
	{
		cout << storeType[0].getName() << " is free on " << StoreName << endl;
	}

	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			cout << storeType[i].getURL() << endl;
		}

		cout << endl;
	}
}
