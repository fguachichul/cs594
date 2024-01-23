#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 5984
#define BUFF_SIZE 4096

int main(int argc, const char *argv[])
{
	int sock = 0;
	struct sockaddr_in serv_addr;
	char *hello = "Hello from client";
	char buffer[BUFF_SIZE] = {0};
	int ret = 0;

	/* [C1: point 1]
	 * Explain following in here.
	 */
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	/* [C2: point 1]
	 * Explain following in here.
	 */
	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	/* [C3: point 1]
	 * Explain following in here.
	 */
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	/* [C4: point 1]
	 * Explain following in here.
	 */
	if (connect(sock, (struct sockaddr *)&serv_addr,
		    sizeof(serv_addr)) < 0) {
		printf("\nConnection Failed \n");
		return -1;
	}

	printf("Press any key to continue...\n");
	getchar();

	/* [C5: point 1]
	 * Explain following in here.
	 */
	send(sock, hello, strlen(hello), 0);
	printf("Hello message sent\n");

	/* [C6: point 1]
	 * Explain following in here.
	 */
	ret = read(sock, buffer, 1024);
	printf("Read %d bytes of message from a server: %s\n", ret, buffer);

	return 0;
}
