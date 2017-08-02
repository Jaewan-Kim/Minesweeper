#include "game.h"

void Game::start_game() {
	gameover = false;
	do {
		cout << "Number of rows: ";
		cin >> rows;
		cout << "Number of columns: ";
		cin >> columns;

		cout << "Number of mines: ";
		cin >> mines;

		if (rows*columns < mines)
			cout << "Too many mines!" << endl;
	} while (rows*columns < mines);

	create_board();
	while (!gameover) {
		display();
	}
}

void Game::setCursorPosition(COORD coord)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	SetConsoleCursorPosition(hOut, coord);
}

COORD Game:: findcoord(int index) {
	COORD coord = { (SHORT)(index%columns) * 2, (SHORT)4 + (index / columns) };
	return coord;
}

void Game::display() {
	for (int i = 0; i < rows*columns; i++) {
		if (board[i] == 0) {
			setCursorPosition(findcoord(i));
			cout << unknown;
		}
		else if (board[i] == 1) {
			setCursorPosition(findcoord(i));

			cout << space;
		}
		else if (board[i] == 2) {
			setCursorPosition(findcoord(i));

			cout << flag;
		}
		else {
			setCursorPosition(findcoord(i));
			cout << questionmark;

		}
		if ((i+1) % columns == 0)
			cout << endl;
	}
}


void Game::create_board() {
	for (int i = 0; i < (rows*columns); i++)
		board.push_back(unknownblock);
	for (int i = 0; i < (rows*columns); i++)
		mineboard.push_back(false);
	for (int i = 0; i < (rows*columns); i++)
		numberofmines.push_back(0);
	int currentmines = 0;
	int randn = 0;


	while (currentmines < mines) {
		randn = rand() % (rows*columns);
		if (!mineboard[randn]) {
			mineboard[randn] = true;
			currentmines++;
		}
	}


	int surroundingmines = 0;
	for (int index = 0; index < rows*columns; index++) {
		if (noleft(index) && noup(index)) {
			if (mineboard[index + 1])
				surroundingmines++;
			if (mineboard[index + columns])
				surroundingmines++;
			if (mineboard[index + columns + 1])
				surroundingmines++;
		}
		else if (noleft(index) && nobottom(index)) {
			if (mineboard[index - columns])
				surroundingmines++;
			if (mineboard[index + 1])
				surroundingmines;
			if (mineboard[index - columns + 1])
				surroundingmines;
		}
		else if (noright(index) && nobottom(index)) {
			if (mineboard[index - 1])
				surroundingmines++;
			if (mineboard[index - columns])
				surroundingmines++;
			if (mineboard[index - columns - 1])
				surroundingmines++;
		}
		else if (noright(index) && noup(index)) {
			if (mineboard[index - 1])
				surroundingmines++;
			if (mineboard[index + columns])
				surroundingmines++;
			if (mineboard[index + columns - 1])
				surroundingmines++;
		}
		else if (noleft(index)) {
			if (mineboard[index+1])
				surroundingmines++;
			if (mineboard[index+columns])
				surroundingmines++;
			if (mineboard[index-columns])
				surroundingmines++;
			if (mineboard[index+columns+1])
				surroundingmines++;
			if (mineboard[index-columns+1])
				surroundingmines++;

		}
		else if (noright(index)) {

			if (mineboard[index - 1])
				surroundingmines++;
			if (mineboard[index + columns])
				surroundingmines++;
			if (mineboard[index - columns])
				surroundingmines++;
			if (mineboard[index + columns - 1])
				surroundingmines++;
			if (mineboard[index - columns - 1])
				surroundingmines++;

		}
		else if (noup(index)) {
			if (mineboard[index + 1])
				surroundingmines++;
			if (mineboard[index - 1])
				surroundingmines++;
			if (mineboard[index + columns])
				surroundingmines++;
			if (mineboard[index + columns + 1])
				surroundingmines++;
			if (mineboard[index + columns - 1])
				surroundingmines++;

		}
		else if (nobottom(index)) {

			if (mineboard[index + 1])
				surroundingmines++;
			if (mineboard[index - 1])
				surroundingmines++;
			if (mineboard[index - columns])
				surroundingmines++;
			if (mineboard[index - columns + 1])
				surroundingmines++;
			if (mineboard[index - columns - 1])
				surroundingmines++;

		}
		else {
			if (mineboard[index + 1])
				surroundingmines++;
			if (mineboard[index - 1])
				surroundingmines++;
			if (mineboard[index + columns])
				surroundingmines++;
			if (mineboard[index - columns])
				surroundingmines++;
			if (mineboard[index + columns + 1])
				surroundingmines++;
			if (mineboard[index + columns - 1])
				surroundingmines++;
			if (mineboard[index - columns + 1])
				surroundingmines++;
			if (mineboard[index - columns - 1])
				surroundingmines++;

		}
		numberofmines[index] = surroundingmines;
		surroundingmines = 0;
	}
}
bool Game::noleft(int index) {
	return index%columns == 0;
}
bool Game::noright(int index) {
	return (index + 1) % columns == 0;
}
bool Game::nobottom(int index) {
	return index >= (rows*columns) - columns;
}
bool Game::noup(int index) {
	return index < columns;
}