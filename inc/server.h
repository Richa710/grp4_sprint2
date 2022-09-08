/*header file for the Server program
here we define all include statements, libraries, one constant for max line length (not used), structures and declaring functions
this file is used for pre-processing for the entire program.
*/

#ifndef _SERVER_H_
#define _SERVER_H_
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/types.h>


#define PORT_NO 5555      //for the port number
#define IPPRO_TCP 0       //for internet protocol TCP
#define MAX_LEN 1024      //the size of the buffer
#define BACKLOG 10        // The number of client waiting for response.
#define TRUE 1
#define IP_ADDRESS "127.0.0.1"   // for the local host 
#define MAX_USER_LEN 30         // for the length of the user name
#define MAX_PSWRD 20            //for the maximum length of the passward
#define BUFF_SIZE 8
#define END_MSG "Annyeong"      //The message to disconnect from the server.
#define SOCKET_CREATE 0         
#define SOCKET_BIND 0
#define SOCKET_LISTEN 0
#define SOCKET_ACCEPT 0
#define SOCKET_SEND 0
#define SOCKET_READ 0
#define SOCKET_CONNECT 0
#define SOCKET_CONVERT 0
#define CHILD_ID 0

#endif


