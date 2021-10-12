#include <iostream>
#include <fstream>	// Leer el archivo
#include <sstream>	// tokenizar el string de cada registro
#include <random>

#include "bst.h"
#include "Server.h"

using namespace std;

int main()
{
	// Creating Binary Tree
	BST<LinkedList<Server>*> mainTree = BST<LinkedList<Server>*> ();

	// Create a text string, which is used to output the text file
	string mes, hora, ip, errorLog;
	int dia;
	string myText;

	// Read from the text file
	ifstream MyReadFile("bitacora.txt");
	int llSize = 16807;
	int randomSize, randomInfected;
	LinkedList<Server>* auxList = new LinkedList<Server> (NULL);
	Server auxServer;

	randomSize = (rand() % 200) + 1;

	// Use a while loop together with the getline() function to read the file line by line
	while (getline (MyReadFile, myText))
	{
		istringstream tokens(myText);
		tokens >> mes;
		tokens >> dia;
		tokens >> hora;
		tokens >> ip;
		tokens >> errorLog;

		int randomInfected = (rand() % 1000) + 1;

		if (randomSize > 0)
		{
			auxServer = Server(mes, dia, hora, ip, errorLog, (randomInfected = 499) ? true : false);
			auxList->addLast(auxServer);
			randomSize--;
		}
		else
		{
			mainTree.insert(auxList);
			auxList = new LinkedList<Server> (NULL);
			randomSize = (rand() % 200) + 1;
			auxList->addLast(Server(mes, dia, hora, ip, errorLog, (randomInfected = 499) ? true : false));
			randomSize--;
		}
	}

	mainTree.insert(auxList);

	cout << "Listo!!" << endl;
	cout << mainTree.lenght() << endl;

	cout << mainTree.first()->size() << endl;

	// Close the file
	MyReadFile.close();
};