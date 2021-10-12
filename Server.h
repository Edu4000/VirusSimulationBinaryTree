#include <iostream>
using namespace std;

class Server {
	private:
	string mes, hora, ip, erroLog;
	int dia;
	bool infectado;

	public:
	// Constructor Default
	// No elements are modified
	Server()
	{
	}

	// Constructor
	// Type: Server
	// Param: string mes, int dia, string hora, string ip, string errorLog, bool infectado
	Server(string mes, int dia, string hora, string ip, string errorLog, bool infectado)
	{
		this->mes = mes;
		this->dia = dia;
		this->hora = hora;
		this->ip = ip;
		this->erroLog = erroLog;
		this->infectado = infectado;
	}
};