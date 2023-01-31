#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <direct.h>
#include <string.h>
#include <stdint.h>


//funcion del cliente 
static inline uint32_t ntohl_ch(char const* a)
{
	uint32_t x; memcpy(&x, a, sizeof(x));
	return ntohl(x);
}

char* recvStrBuffer(SOCKET s)
{
	int totalReceived = 0;
	int received = 0;
	
	// recv buffer size
	char b[sizeof(uint32_t)];
	int r = recv(s, b, sizeof(uint32_t), 0);
	if (r == SOCKET_ERROR)
	{
		printf("error recv\n");
		return NULL;
	}
	uint32_t bufferSize = ntohl_ch(&b[0]);
	//printf("bufferSize: %d\n", bufferSize);
	
	char* buff = (char*)malloc(sizeof(char) * bufferSize);
	
	while (totalReceived < bufferSize)
	{
		received = recv(s, buff + totalReceived, bufferSize - totalReceived, 0);
		if (received == SOCKET_ERROR)
		{
			printf("error receiving buffer %d\n", WSAGetLastError());
			return NULL;
		}
		totalReceived += received;
		//printf("received: %d\n", received);
		//printf("totalReceived: %d\n", totalReceived);
	}
	//printf("%s", buff);
	return buff;
}

int main(int argc, char *argv[]) {
	
	char* buffer;
	buffer = recvStrBuffer(socket);
	if (buffer == NULL) { printf("error %d\n", WSAGetLastError()); }
	printf("%s", buffer);
	free(buffer);
	
	return 0;
}

