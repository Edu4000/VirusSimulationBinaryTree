#include <iostream>
#include <fstream>	// Leer el archivo
#include <string>
#include <sstream>	// tokenizar el string de cada myTextistro
#include <random>

using namespace std;

int main()
{
	// Create a text string, which is used to output the text file
	string mes, hora, ip, errorLog;
	int dia;
	string myText; // Auxiliar text for each line

	// Read from the text file
	ifstream MyReadFile("bitacora.txt"); //  Oct 9 10:32:24 423.2.230.77:6166 Failed password for illegal user guest


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
}
