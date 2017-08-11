#ifndef GAME
#define GAME

#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

const char unknown = 254;
const char space = 'O';
const char flag = 'X';
const char questionmark = '?';

const int unknownblock = 0;
const int spaceblock = 1;
const int flagblock = 2;
const int questionblock = 3;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Game {
private:
	bool victory = false;
	int current = 0;
	bool gameover;
	int rows;
	int input;
	int columns;
	int mines;
	int flags = 0;
	void create_board();
	vector<int> board;
	vector<bool>mineboard;
	vector<int> numberofmines;
	bool noleft(int index);
	bool noright(int index);
	bool nobottom(int index);
	void display();
	bool noup(int index);
	void setCursorPosition(COORD coord);
	COORD findcoord(int index);
	void moveright();
	void moveleft();
	void moveup();
	void movedown();
	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(out, &cursorInfo);
	}
public:
	void start_game();

};
#endif