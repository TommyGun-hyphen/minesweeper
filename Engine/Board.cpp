#include "Board.h"

Board::Cell::Cell(int x, int y, int size, Color color, bool hasBomb):
	x(x),
	y(y),
	size(size),
	color(color),
	hasBomb(hasBomb)

{
	
}

void Board::Cell::Draw(Graphics & gfx)
{
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			gfx.Draw3DRect(x, y, size, size, size / 5, color);
		}
	}
}

Board::Board(int x, int y):
	x(x),
	y(y)
{
	for (int i = 0; i < hCells; i++) {
		for (int j = 0; j < vCells; j++) {
			cells[(j * hCells) + i] = Cell(x + i * cellSize, y + j * cellSize, cellSize, cellColor, false);
		}
	}
}

void Board::Draw(Graphics & gfx)
{

	for (int i = 0; i < maxCells; i++) {
		cells[i].Draw(gfx);
	}
}

void Board::Center(int screenW, int screenH)
{
	x = (hCells * cellSize) / 2;
	y = (vCells * cellSize) / 2;
	for (int i = 0; i < hCells; i++) {
		for (int j = 0; j < vCells; j++) {
			cells[(j * hCells) + i] = Cell(x + i * cellSize, y + j * cellSize, cellSize, cellColor, false);
		}
	}
}
