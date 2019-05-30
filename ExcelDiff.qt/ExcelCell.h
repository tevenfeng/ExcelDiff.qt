#pragma once
#include <string>

class ExcelCell
{
private:
	int row, col;
	std::string value;
public:
	ExcelCell();
	ExcelCell(int row, int col, std::string value);
	~ExcelCell();
	int getRow() const;
	int getCol() const;
	std::string getValue() const;
};

