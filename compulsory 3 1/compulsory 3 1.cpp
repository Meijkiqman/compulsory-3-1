#include  "Header.h"


int main()
{		
	xpass = 0;
	ypass = 0;
		srand(time(0));
		if (password() == true)
		{
			mainMenu();

		}
		else
		{
			std::cout << "\n\ngoodbye!";
			return 0;
		}
	
}


void passwordBoard()
{
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			if (i ==xpass && k ==ypass)
			{
				std::cout << "*" << "|";
			}
			else
			{
				std::cout << i + k << "|";
			}
		}
		std::cout << std::endl;
	}
}

bool password()
{
	
	std::fstream passwordFile("password.txt", std::ios::in); // a large part of this code is not my own. credit to https://github.com/adamaske
	if (passwordFile)
	{
		std::cout << "found password\n";
		system("pause");
		while (true)
		{
		 system("cls");
				std::cout << "please enter password, use WASD to move on the board." << std::endl;
				passwordBoard();
				auto input = _getch();
				if (input == 119) // the number in the input if statements are just the int values of WASD it gets from getch
				{
					if (xpass - 1 >= 0)
					{
						enteredPassword.push_back(KEY_W);
						xpass--;
						
					}
					
				}
				if (input == 115)
				{	
					if (xpass + 1 <= 4)
					{
						enteredPassword.push_back(KEY_S);
						xpass++;
						
					}
					
				}
				if (input == 100)
				{
					if (ypass + 1 <=4)
					{
						enteredPassword.push_back(KEY_D);
						ypass++;
						
					}
					
				}
				if (input == 97)
				{
					if (ypass - 1 >= 0)
					{
						enteredPassword.push_back(KEY_A);
						ypass--;
						
					}
				}
				else if (input == '\r') //when you press enter it checks wether your password is correct or not.
				{
					while (!passwordFile.eof())
					{
						std::string p;
						std::getline(passwordFile, p);
						std::istringstream q(p);
						int z;
						q >> p;
						correctPassword.push_back(z);
					}
					if (enteredPassword != correctPassword)
					{
						std::cout << "\nWrong Password!";
						return false;
					}
					else
					{
						return true;
					}
				}
		}
		

	}
	else //if no password exists, then it creates one here
	{
		std::cout << "no password detected \n";
		std::vector<int> newPassword;
		while (true)
		{
			system("cls");
			std::cout << "please enter new password, then press ENTER to confirm. use WASD to move." << std::endl;
			passwordBoard();
			auto input = _getch();
			if (input == 119) // the number in the input if statements are just the int values of WASD it gets from getch
			{
				if (xpass - 1 >= 0)
				{
					enteredPassword.push_back(KEY_W);
					xpass--;
					
				}

			}
			if (input == 115)
			{
				if (xpass + 1 <= 4)
				{
					newPassword.push_back(KEY_S);
					xpass++;
					
				}
			}
			if (input == 100)
			{
				if (ypass + 1 <= 4)
				{
					newPassword.push_back(KEY_D);
					ypass++;
					
				}
			}
			if (input == 97)
			{
				if (ypass - 1 >= 0)
				{
					newPassword.push_back(KEY_A);
					ypass--;
					
				}
			}
			else if (input == '\r')
			{
				std::fstream newPasswordFile("password.txt", std::ios::out);
				for (int i = 0; i < newPassword.size()-1; i++)
				{
					newPasswordFile << newPassword[i] << std::endl;
				}
				return true;
			}
		}
	}
	return true;
}


void changepassword()
{
	xpass = 0; // resets board position.
	ypass = 0;

	while (true)
	{
		system("cls");
		std::cout << "please enter new password, press enter to confirm\n";
		passwordBoard();
		auto input = _getch();
		if (input == 119)
		{
			if (xpass - 1 >= 0)
			{
				enteredPassword.push_back(KEY_W);
				xpass--;
				
			}
		}
		if (input == 115)
		{
			if (xpass + 1 <= 4)
			{
				newPassword.push_back(KEY_S);
				xpass++;
				
			}
		}
		if (input == 100)
		{
			if (ypass + 1 <= 4)
			{
				newPassword.push_back(KEY_D);
				ypass++;
				
			}
		}
		if (input == 97)
		{
			if (ypass - 1 >= 0)
			{
				newPassword.push_back(KEY_A);
				ypass--;
				
			}
		}
		else if (input == '\r')
		{
			std::fstream password("password.txt", std::ios::out);
			for (int i = 0; i < newPassword.size() - 1; i++)
			{
				password << newPassword[i] << std::endl;
			}
			std::cout << "\nYou have succesfully changed your password, press any key to return to main menu" << std::endl;
			if (_getch()) {
				mainMenu();
			}
		}
	}
}
int letterToNumber(char letter) // only big letters
{
	return static_cast<int>(letter) - 65;
}


void makeEmptyBoard()
{
	


	
	for (int i = 0; i < M; i++) //2d vector makes empty board
	{
		
		for (int k = 0; k < N; k++)
		{ 
			
			board[i][k] = BLANK;
		}
		
	}

}


void mainMenu()
{	
	system("cls");
	std::cout << "Welcome to the main menu. please choose an action" << std::endl;
	std::cout << "1: Change the password. \n";
	std::cout << "2: Play Battleship. \n";
	std::cout << "3: Quit. \n";
	


	while (true)
	{
		
	
			char answer;
			std::cin >> answer;
			if (answer == '1')
			{
				std::cout << "changing password...\n";
				system("pause");
				changepassword();
				break;
			}

			else if (answer == '2')
			{
				
				play();
				break;
			}

			else if (answer == '3')
			{
				std::cout << "Goodbye";
				Quit();
				break;
			}

			else if (answer != '1' && '2' && '3')
			{
				std::cout << "please choose a valid answer! \n";
			}

		
	}
	

}
void Quit()
{
	std::exit;
}
int randomRow()
{
	int x;
	x = rand() % M;
	return x;
	
}
int randomColumn()
{
	int y;
	y = rand() % N;
	return y;
	
}
void writeLetters()
{
	for (int i = 0; i < M*2.2; i++)
	{
		std::cout << "-";
	}
	
	std::cout << std::endl;
	std::cout << "  ";
	for (int a = 0; a < M; a++)
	{
		std::cout << row[a] << "|";
	}
}
void makeBoard()
{
	system("pause");
	int s = 0;
	while(s < numberOfShips)
	{	
			int x = randomRow();
			int y = randomColumn();
			if (board[x][y] != SHIP)
			{ 
			s++;
			board[x][y] = SHIP;
			}
	}

}

void printBoard()
{
	for (int i = 0; i < M; i++)
	{
		std::cout << i << "|";
		for (int k = 0; k < N; k++)
		{
			std::cout << board[i][k] << "|";
		}
		std::cout << std::endl;
	}
	writeLetters();
}

void printPlayerBoard()
{
	std::cout << std::endl;
	for (int i = 0; i < M; i++)
	{
		std::cout << i + 1 << "|"; //i+1 so that the array goes from 1 to 6, instead of 0 to 5.
		for (int k = 0; k < N; k++)
		{
			if (board[i][k] != SHIP) //if theres a ship it wont print
			{
				std::cout << board[i][k] << "|";
			}
			else
			{
				std::cout << " " << "|";
			}
		}
		std::cout << std::endl;
	}
	writeLetters();
}

void shoot()
{
	
	while (0 < numberOfShots)
	{
		system("cls");

		std::cout << "please pick a cell to shoot at. First pick a letter [letter] then a number [number]";
		std::cout << std::endl;
		printPlayerBoard();
		std::cout << "\nplease pick a cell:  ";
		char letter = _getch();
		letter = toupper(letter);
		std::cout << letter; // writes the letter so you know what you wrote since getch() doesnt.
		int letterNum = letterToNumber(letter);
		char charnumber = _getch();
		int intnumber = charnumber - '0'; //since the input is not initially a number but a char this converts the number to an actuall number, takes away 
		intnumber = intnumber - 1;
		std::cout << intnumber + 1;
		if (board[letterNum][intnumber] == SHIP)
		{
			board[letterNum][intnumber] = HIT;
			numberOfHits++;
			numberOfShips--;
			numberOfShots--;
			
		}
		else if (board[letterNum][intnumber] == BLANK)
		{
			board[letterNum][intnumber] = MISS;
			numberOfShots--;

		}
	}
		if (numberOfShips == 0)
		{
			std::cout << "\nCongrats, you win! with " << numberOfShots << "shots left!" << std::endl;;
				printBoard();
				std::cout << "\ngoodebye!";
				system("pause");
				std::exit;
		}
		if(numberOfShots == 0 || numberOfShips !=0)
		{
			std::cout << "\n oh no:( youre out of ammo. you loose. there was: " << numberOfShips << " ships left" << std::endl;
			printBoard();
			std::cout << "\ngoodebye!";
			system("pause");
			std::exit;
		}
	

}
void play()
{
	numberOfShots = 10;
	numberOfHits = 0;
	numberOfShips = 6;
	randomRow();
	randomColumn();
	makeEmptyBoard();
	makeBoard();
	printBoard();
	printPlayerBoard();
	shoot();
}



