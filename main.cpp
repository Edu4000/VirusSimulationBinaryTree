#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <fstream>	// Leer el archivo
#include <string>
#include <sstream>	// tokenizar el string de cada myTextistro
#include <random>
#include "bst.h"
#include "Server.h"

using namespace std;

void S(int sleepMs)
{
#ifdef LINUX
    sleep(1);   // sleep in seconds
#endif
#ifdef WINDOWS
    Sleep(sleepMs);
#endif
}

void clearTerminal()
{
	S(1);
	cout << "\033[2J\033[1;1H";
}

int main()
{
	bool fileLoaded = false; int choice = 1;
	BST<LinkedList<Server>*> mainTree = BST<LinkedList<Server>*> ();

	while (true)
	{
		try
		{
			cout << "| =================== Menu  ==================== |" << endl;
			cout << "0. Cargar el archivo | Default " << endl;
			cout << "1. Imprimir arbol por nivel" << endl;
			cout << "2. Imprimir arbol por pre-orden" << endl;
			cout << "3. Imprimir arbol por post-orden" << endl;
			cout << "4. Imprimir arbol por in-orden" << endl;
			cout << "5. Buscar si existe servidor por ip" << endl;
			cout << "6. Imprimir porcentaje de servidores infectados / no infectados" << endl;
			cout << "7. Imprimir resultados de los metodos de BST" << endl;
			cout << "8. Exit\n";

			cin >> choice;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw "Error";
			}

			if (choice == 8)
			{
				//clearTerminal();
				cout << "Exiting!" << endl;
				return 0;
			}
			else if (choice != 0 && fileLoaded == false)
			{
				clearTerminal();
				cout << "First you need to upload the file..." << endl;
	 			continue;
			}
			else if (choice == 0 && fileLoaded == true)
			{
				clearTerminal();
				cout << "You already saved the file!" << endl;
			}
			else if (choice == 0 && fileLoaded == false)
			{
				clearTerminal();
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
				fileLoaded = true;
				clearTerminal();
				cout << "File saved!" << endl;
				cout << mainTree.lenght() << endl;
			}
			else if (choice == 1)
			{
				clearTerminal();
				cout << "Choice 1" << endl;
				/* mainTree.levels(); */
				/* cout << "Press any key to continue" << endl; */

			}
			else if (choice == 2)
			{
				clearTerminal();
				cout << "Choice 2" << endl;
				mainTree.preOrden();
				/* cout << "\nPress any key to continue"; */

			}
			else if (choice == 3)
			{
				clearTerminal();
				cout << "Choice #3" << endl;
				mainTree.postOrden();
				/* cout << "Press any key to continue" << endl; */

			}
			else if (choice == 4)
			{
				clearTerminal();
				cout << "Choice #4" << endl;
				mainTree.inOrden();
				/* cout << "Press any key to continue" << endl; */

			}
			else if (choice == 5) // search IP
			{
				clearTerminal();
				cout << "What is the IP?" << endl;
				cin.clear();
				cin.ignore();

				if (mainTree.searchIP("423.2.230.77:6156"))
				{
					cout << "There is a server with that ip" << endl;
				}
				else
				{
					cout << "There is a server with that ip" << endl;
				}

			}
			else if (choice == 6) // print percentage
			{
				clearTerminal();
				cout << "Choice #6" << endl;
				cout << "The " << mainTree.infected_percent() * 100 << "%" << " of the servers are infected" << endl;

			}
			else if (choice == 7)
			{
				clearTerminal();
				cout << "Choice #7" << endl; // BST methods
			}
			else
			{
				throw "Error";
			}
		}
		catch(...)
		{
			cout << "Error. Not possible to execute the operation. Restarting the program." << endl;
		}
	}
}
