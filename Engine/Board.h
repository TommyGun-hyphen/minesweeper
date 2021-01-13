#pragma once
#include "Colors.h"
#include "Graphics.h"
class Board
{
public:
	Board(int x, int y);
	void Draw(Graphics& gfx);
	void Center(int screenW, int screenH);
private:
	class Cell
	{
	public:
		Cell() = default;
		Cell(int x, int y, int size, Color color, bool hasBomb);
		void Draw(Graphics& gfx);
		int x;
		int y;
		int size;
		Color color;
		bool hasBomb = false;
	};
	int x;
	int y;
	static constexpr int hCells = 20;
	static constexpr int vCells = 15;
	static constexpr int cellSize = 20;
	static constexpr int maxCells = hCells * vCells;
	static constexpr int bombAmount = (maxCells) / 4;
	Cell cells[maxCells];
	Color cellColor = Colors::Gray;

};

