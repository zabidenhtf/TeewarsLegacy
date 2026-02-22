/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */
#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Windows net libs
#ifdef _WIN32
    #include <winsock2.h>
#else
	// Linux net livs
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
#endif

#define MAX_PACKET_SIZE 1024

// Net address structure
typedef struct
{
    unsigned int ip;
    unsigned short port;
} NetAddr;

int net_init(); // Initialization of socket
int net_udp_open(unsigned short port); // Open socket
int net_udp_send(int sock, NetAddr *addr, void *data, int size); // Sending data
int net_udp_recv(int sock, NetAddr *addr, void *buffer, int maxsize); // Getting data
void net_close(int sock); // Closing socket

#endif