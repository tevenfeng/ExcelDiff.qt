#pragma once
#include <string>

class ExcelCell
{
private:
	int row, col;
	std::u16string value;
public:
	ExcelCell();
	ExcelCell(int row, int col, std::u16string value);
	~ExcelCell();
	int getRow() const;
	int getCol() const;
	std::u16string getValue() const;
};

