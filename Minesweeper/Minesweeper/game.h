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
const char flag = 197;
const char questionmark = '?';

const int unknownblock = 0;
const int spaceblock = 1;
const int flagblock = 2;
const int questionblock = 3;

class Game {
private:
	bool gameover;
	int rows;
	int columns;
	int mines;
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
public:
	void start_game();

};
#endif