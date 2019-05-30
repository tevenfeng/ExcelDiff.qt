#include "ExcelCell.h"

ExcelCell::ExcelCell()
{
}

ExcelCell::ExcelCell(int row, int col, std::string value)
{
	this->row = row;
	this->col = col;
	this->value = value;
}

ExcelCell::~ExcelCell()
{
}

int ExcelCell::getRow() const
{
	return this->row;
}

int ExcelCell::getCol() const
{
	return this->col;
}

std::string ExcelCell::getValue() const
{
	return this->value;
}
