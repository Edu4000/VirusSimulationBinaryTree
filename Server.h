/**
 * @file Server.h
 * @author TheDevs
 * @brief Server class used in VirusSimulation
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief Server class that stores the information of each server in bitacora.
 * 
 */
class Server {
	private:
	string mes, hora, ip, erroLog;
	int dia;
	bool infectado;

	public:
	/**
	 * @brief Construct a new Server object with default valeus.
	 * 
	 */
	Server()
	{
	}

	/**
	 * @brief Construct a new Server object
	 * 
	 * @param mes The month of access attempt
	 * @param dia The day of access attempt
	 * @param hora The time of access attempt
	 * @param ip The IP adress and Port of the of access attempt
	 * @param errorLog The error of the access attempt
	 * @param infectado Status of infected of IP
	 */
	Server(string mes, int dia, string hora, string ip, string errorLog, bool infectado)
	{
		this->mes = mes;
		this->dia = dia;
		this->hora = hora;
		this->ip = ip;
		this->erroLog = erroLog;
		this->infectado = infectado;
	}

	/**
	 * @brief Operator overload of ==, checks if server is infected
	 * 
	 * @param true_statement Default true
	 * @return TRUE if server is infected, else return FALSE
	 */
	bool operator == (bool true_statement){
		return true_statement == this->infectado;
	}

	/**
	 * @brief Operator overload of ==, compares string of parameter to IP of server
	 * 
	 * @param ip String to compare with server IP
	 * @return TRUE if string is the same as server IP, else return FALSE
	 */
	bool operator == (string ip)
	{
		return this->ip == ip;
	}

	/**
	 * @brief Overload operator of <<, used to print server IP
	 * 
	 * @param salida Out stream variable
	 * @param server The server object
	 * @return ostream& 
	 */
	friend ostream& operator <<(ostream & salida, const Server & server)
	{
		salida << server.ip;
		return salida;
	}
};
