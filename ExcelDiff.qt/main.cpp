#include "ExcelDiff.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ExcelDiff w;
	w.show();
	return a.exec();
}
