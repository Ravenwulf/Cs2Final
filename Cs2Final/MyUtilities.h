#pragma once
#include <string>
class InvalidFileException {};
class UserQuit {};
class MyUtilities {
private:
	int num;
	std::string inputFile;
	std::string bin;
	int* numArr;

public:
	void displayMenu();
	void readData(int mode = 0);
	void writeData(std::string file);
	int getNum() { return this->num; };
	int* getNumArr() { return this->numArr; };
};

//class InvalidFileException {};
//class UserQuit {};