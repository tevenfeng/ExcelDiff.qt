#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QListview>
#include <QLineEdit>
#include <QProgressBar>
#include <QTimer>
#include <QFileDialog>
#include <QString>
#include <QTableWidget>
#include <QFileInfo>
#include <QMessageBox>
#include "xlsxdocument.h"

#include "ui_ExcelDiff.h"

#include "ExcelCell.h"
#include "ExcelReader.h"

class ExcelDiff : public QMainWindow
{
	Q_OBJECT

		signals :

	public slots :

		void file1BtnClicked();

	void file2BtnClicked();

	void diffBtnClicked();

public:
	ExcelDiff(QWidget *parent = Q_NULLPTR);

private:
	Ui::ExcelDiffClass ui;
	QWidget *mainWidget;
	QGridLayout *mainLayout;

	QWidget *topWidget, *bottomWidget;
	QGridLayout *topLayout, *bottomLayout;

	QLineEdit *file1, *file2;
	QPushButton *file1Btn, *file2Btn, *diffBtn;
	QProgressBar *diffProgressBar;
	QBasicTimer *diffTimer;

	QWidget *leftWidget, *rightWidget;
	QGridLayout *leftLayout, *rightLayout;

	QTableWidget *tableWidget1, *tableWidget2, *detailTableWidget;
	QPushButton *rowBtn, *colBtn, *cellBtn, *clearHighlightBtn;

	QVector<QVector<QVector<ExcelCell>>> excelOneData, excelTwoData;

	void makeTop();
	void makeBottom();
	void makeLeft();
};
