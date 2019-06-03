# ExcelDiff.qt

ExcelDiff.qt is a gadget based on Qt 5.12.3 and [QXlsx](https://github.com/QtExcel/QXlsx), which aims to show differences between two excel files(*.xlsx).

# Development

Building on other platforms, e.g. Linux or Mac, has not been tested yet.

- Windows 10 x64
- Visual Studio 2015
- Qt 5.12.3
- QXlsx 1.3.23

# Problems and Bugs

1. Load two files and exit, open ExcelDiff.qt and then load the same two files, it will crash.