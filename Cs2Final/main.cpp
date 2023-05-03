#include "MyUtilities.h"
#include "BST.h"
#include <iostream>

int main() {
	//declare utility object
	MyUtilities m;
	try {
		//run utility commands
		m.displayMenu();
		m.readData();
		m.writeData("numbers.dat");
		m.readData(1);

		//catch errors
	} catch (UserQuit e) {
		std::cout << "Quitting Process...\n";
		return 0;
	} catch (InvalidFileException e) {
		std::cout << "ERROR: Invalid File, Quitting Process...\n";
		return 0;
	}

	//declare binary tree
	BST tree;

	for (int i = 0; i < m.getNum(); i++) {
		tree.insert(m.getNumArr()[i]);
	}
	tree.printInOrder();
	std::cout << "\n";
	tree.printPreOrder();
	std::cout << "\n";
	tree.printPostOrder();


	return 0;
}