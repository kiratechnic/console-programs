#pragma comment(lib, "ws2_32.lib")
#include<winsock2.h>
#include<iostream>
#include <stdio.h> // переименование удаление файлов
#include <io.h> // поик файлов
#include <fstream>

#pragma warning(disable: 4996)
using namespace std;

int main(int argc, char* argv[])
{

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 2);
	WSAStartup(DLLVersion, &wsaData);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		cout << "error" << endl;
		exit(1);
	}



	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("192.168.1.15");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;



	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);


	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	SOCKET newConnection_2;
	newConnection_2 = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);


	if (newConnection == 0)
	{
		cout << "Error #2\n";
	}
	if (newConnection_2 == 0)
	{
		cout << "Error #2\n";
	}
	else
	{
		cout << "Clients connected!";

		while (true)
		{
			
			char msg_catch[256];
			while (true)
			{

				recv(newConnection, msg_catch, sizeof(msg_catch), NULL);

				send(newConnection_2, msg_catch, sizeof(msg_catch), NULL);

				recv(newConnection_2, msg_catch, sizeof(msg_catch), NULL);

				send(newConnection, msg_catch, sizeof(msg_catch), NULL);

			}
		}
		if (newConnection == 0)
		{
			cout << "Client has disconected\n";
		}
		else if (newConnection_2 == 0)
		{
			cout << "Client has disconnectedn\n";
		}
	}


	system("pause");
	return 0;
}
