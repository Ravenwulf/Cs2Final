#include "MyUtilities.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void MyUtilities::displayMenu() {
	cout << "Enter name of data file and how many numbers to read: (name num)" << endl;
	cin >> this->inputFile;
	if (this->inputFile == "q") throw UserQuit();
	cin >> this->num;
	//cout << fileName << " Number:" << num ;
}

void MyUtilities::readData(int mode) {
	ifstream iFile;
	switch (mode) {
		case 0:
			this->numArr = new int[this->num];
			iFile.open(this->inputFile);
			if (!iFile) throw InvalidFileException();
			for (int i = 0; i < this->num; i++) {
				iFile >> (*(this->numArr+i));
			}
		break;
		case 1:
			iFile.open(this->bin, ios::binary);
			if (!iFile) throw InvalidFileException();
			iFile.read(reinterpret_cast<char*>(this->numArr), sizeof(this->numArr)*this->num);
			//iFile.read(reinterpret_cast<char*>(buffer), sizeof(this->numArr));
			for (int i = 0; i < this->num; i++) {
				numArr[i]*=2;
				cout << *(this->numArr + i) << " ";
			}
			cout << endl;

	}
	
}

void MyUtilities::writeData(string file) {
	this->bin = file;
	ofstream oFile(this->bin, ios::binary);
	if (!oFile) throw InvalidFileException();
	//int* arr = new int[]{ 123, 234, 435 };
	//oFile.write(reinterpret_cast<char*>(this->numArr), sizeof(this->numArr));
	oFile.write(reinterpret_cast<char*>(this->numArr), sizeof(this->numArr) * this->num);
}
