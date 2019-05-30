#include "ExcelDiff.h"

void ExcelDiff::file1BtnClicked()
{
	QString filePath = QFileDialog::getOpenFileName(this,
		QString("Choose file"),
		QString("./test"),
		QString("Excel (*.xlsx)"));

	this->file1->setText(filePath);
}

void ExcelDiff::file2BtnClicked()
{
	QString filePath = QFileDialog::getOpenFileName(this,
		QString("Choose file"),
		QString("./test"),
		QString("Excel (*.xlsx)"));

	this->file2->setText(filePath);
}

void ExcelDiff::diffBtnClicked()
{
	if (!QFileInfo(this->file1->text()).exists()
		|| !QFileInfo(this->file2->text()).exists())
	{
		QMessageBox msgBox;
		msgBox.setText("Please select two excel files!");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}
	else
	{
		// Load the two Excel files with QXlsx
		this->excelOne = new QXlsx::Document(this->file1->text());
		this->excelTwo = new QXlsx::Document(this->file2->text());

		// Extract the two files into vector?
		// Todo

		ExcelReader *reader = new ExcelReader(this->excelOne);


		makeBottom();
	}
}

ExcelDiff::ExcelDiff(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Excel Differ");
	this->setBaseSize(960, 700);

	this->mainWidget = new QWidget(this);
	this->setCentralWidget(this->mainWidget);
	this->mainLayout = new QGridLayout(this);

	this->topWidget = new QWidget(this->mainWidget);
	this->topLayout = new QGridLayout(this->topWidget);
	this->topWidget->setLayout(this->topLayout);

	this->bottomWidget = new QWidget(this->mainWidget);
	this->bottomLayout = new QGridLayout(this->bottomWidget);
	this->bottomWidget->setLayout(this->bottomLayout);

	makeTop();

	this->mainLayout->addWidget(this->topWidget, 0, 0, 2, 14);
	this->mainLayout->addWidget(this->bottomWidget, 2, 0, 19, 14);
	this->mainLayout->setSpacing(0);
	this->mainWidget->setLayout(this->mainLayout);
}

void ExcelDiff::makeTop()
{
	this->file1 = new QLineEdit(this->topWidget);
	this->file1Btn = new QPushButton("File 1", this->topWidget);

	this->file2 = new QLineEdit(this->topWidget);
	this->file2Btn = new QPushButton("File 2", this->topWidget);

	this->diffBtn = new QPushButton("Diff", this->topWidget);

	this->topLayout->addWidget(this->file1Btn, 0, 0, 1, 1);
	this->topLayout->addWidget(this->file1, 0, 1, 1, 2);
	this->topLayout->addWidget(this->file2Btn, 0, 4, 1, 1);
	this->topLayout->addWidget(this->file2, 0, 5, 1, 2);
	this->topLayout->addWidget(this->diffBtn, 0, 13, 1, 1);

	this->diffProgressBar = new QProgressBar(this->topWidget);
	this->diffProgressBar->setFixedHeight(16);
	this->diffProgressBar->setValue(0);
	this->topLayout->addWidget(this->diffProgressBar, 1, 0, 1, 7);

	QObject::connect(this->file1Btn, &QPushButton::clicked, this, &ExcelDiff::file1BtnClicked);
	QObject::connect(this->file2Btn, &QPushButton::clicked, this, &ExcelDiff::file2BtnClicked);
	QObject::connect(this->diffBtn, &QPushButton::clicked, this, &ExcelDiff::diffBtnClicked);
}

void ExcelDiff::makeBottom()
{
	this->leftWidget = new QWidget(this->bottomWidget);
	this->leftLayout = new QGridLayout();
	this->leftWidget->setLayout(this->leftLayout);
	this->rightWidget = new QWidget(this->bottomWidget);
	this->rightLayout = new QGridLayout();
	this->rightWidget->setLayout(this->rightLayout);

	this->tableWidget1 = new QTableWidget(this->rightWidget);
	this->tableWidget2 = new QTableWidget(this->rightWidget);
	this->detailTableWidget = new QTableWidget(this->rightWidget);
	this->clearHighlightBtn = new QPushButton("Clear Highlight", this->rightWidget);
	this->rowBtn = new QPushButton("Row Diff", this->rightWidget);
	this->colBtn = new QPushButton("Column Diff", this->rightWidget);
	this->cellBtn = new QPushButton("Cell Diff", this->rightWidget);
	this->rightLayout->addWidget(this->tableWidget1, 0, 0, 15, 6);
	this->rightLayout->addWidget(this->tableWidget2, 0, 6, 15, 6);
	this->rightLayout->addWidget(this->rowBtn, 15, 0, 1, 2);
	this->rightLayout->addWidget(this->colBtn, 15, 2, 1, 2);
	this->rightLayout->addWidget(this->cellBtn, 15, 4, 1, 2);
	this->rightLayout->addWidget(this->clearHighlightBtn, 15, 6, 1, 2);
	this->rightLayout->addWidget(this->detailTableWidget, 16, 0, 3, 12);

	this->bottomLayout->addWidget(this->leftWidget, 0, 0, 19, 1);
	this->bottomLayout->addWidget(this->rightWidget, 0, 1, 19, 13);

	makeLeft();
}

void ExcelDiff::makeLeft()
{

}
