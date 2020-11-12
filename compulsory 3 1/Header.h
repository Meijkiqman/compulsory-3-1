#pragma once
#include <iostream>
#include<vector>
#include<conio.h>
#include<ctime>
#include <fstream>
#include<string>
#include <sstream>
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100

std::vector<int> enteredPassword;
std::vector<int> correctPassword;
std::vector<int> newPassword;

const int height = 4;
const int width = 4;
int xpass = 0;
int ypass = 0;

std::vector<char> row{ 'A','B','C','D','F','G'};
const int M = 6, N = 6;
const char BLANK = ' ';
const char SHIP = 'S';
const char MISS = 'M';
const char HIT = 'H';
char board[M][N];
int numberOfShips;
int numberOfHits;
int numberOfShots;
int letterToNumber();


/*std::vector<std::vector<char>> board{
{		{' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' '}
		}
};*/





bool password();

void changepassword();

void mainMenu();

void makeEmptyBoard();

int randomRow();

int randomColumn();

void writeLetters();

void makeBoard();

void printBoard();

void printPlayerBoard();

void shoot();

void play();

void Quit();

void passwordBoard();

