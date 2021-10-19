#include <iostream>
#include <fstream>	// Leer el archivo
#include <string>
#include <sstream>	// tokenizar el string de cada myTextistro
#include <random>
#include "bst.h"
#include "Server.h"

using namespace std;

BST makeTree()
{
	// Tree is created with BST and LinkedList and Server Class
	BST<LinkedList<Server>*> mainTree = BST<LinkedList<Server>*> ();

	// Create a text string, which is used to output the text file
	string mes, hora, ip, errorLog;
	int dia;
	string myText; // Auxiliar text for each line

	// Read from the text file
	ifstream MyReadFile("bitacora.txt"); //  Oct 9 10:32:24 423.2.230.77:6166 Failed password for illegal user guest

	int randomInfected;
	LinkedList<Server>* auxList = new LinkedList<Server> (NULL);
	Server auxServer;
	int randomSize = (rand() % 200) + 1;

	// Use a while loop together with the getline() function to read the file line by line
	while (getline (MyReadFile, myText))
	{
		int aux = 1, aux3 = 1; // aux determines when a word is completed, aux3 for last str
		string aux2 = ""; // string aux2 is where data will be saved for later
		for (int i = 0; i < myText.length(); i++)
		{
			if (myText[i] == ' ' && aux3 <= 4) // For the first 4 categories
			{
				aux++;
				if (aux == 2 && aux3 == 1)
				{
					aux = 1;
					mes = aux2;
					aux2 = "";
					aux3++;
				}
				else if (aux == 2 && aux3 == 2)
				{
					aux = 1;
					dia = stoi(aux2);
					aux2 = "";
					aux3++;
				}
				else if (aux == 2 && aux3 == 3)
				{
					aux = 1;
					hora = aux2;
					aux2 = "";
					aux3++;
				}
				else
				{
					aux = 1;
					ip = aux2;
					aux2 = "";
					aux3++;
				}
			}
			else if (aux3 > 4)
			{
				aux2 += myText[i];
			}
			else
			{
				aux2 += myText[i];
			}
			errorLog = aux2;
		}

		int randomInfected = (rand() % 1000) + 1;
		if (randomSize > 0)
		{
			auxServer = Server(mes, dia, hora, ip, errorLog, (randomInfected == 499) ? true : false);
			auxList->addLast(auxServer);
			randomSize--;
		}
		else
		{
			mainTree.insert(auxList);
			auxList = new LinkedList<Server> (NULL);
			randomSize = (rand() % 200) + 1;
			auxList->addLast(Server(mes, dia, hora, ip, errorLog, (randomInfected == 499) ? true : false));
			randomSize--;
		}
	}
	mainTree.insert(auxList);
	// Close the file
	MyReadFile.close();

	return mainTree;
}


int main()
{
	while (true)
	{
		int choice; bool fileLoaded = false;
		cout << "| ==================== Menu  ==================== |" << endl;
		cout << "1. Cargar el archivo" << endl;
		cout << "2. Imprimir arbol por nivel" << endl;
		cout << "3. Imprimir arbol por pre-orden" << endl;
		cout << "4. Imprimir arbol por post-orden" << endl;
		cout << "5. Imprimir arbol por in-orden" << endl;
		cout << "6. Buscar si existe servidor por ip" << endl;
		cout << "7. Imprimir porcentaje de servidores infectados / no infectados" << endl;
		cout << "9. Imprimir resultados de los metodos de BST" << endl;

		if (choice != 0 && fileLoaded == false)
		{
			continue;
		}

		switch (choice)
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			default:
				break;
		}
	}


	// Creating Binary Tree
	BST<LinkedList<Server>*> mainTree = makeTree();
}
