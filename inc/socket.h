/*header file for the program
here we define all include statements, libraries, one constant for max line length (not used), structures and declaring functions
this file is used for pre-processing for the entire program
*/
#ifndef __SOCKET_H__
#define __SOCKET_H__
#include <netinet/in.h>          //include the structure for the socket
#include <stdio.h>               //include standard input output
#include <stdlib.h>              //include standard library
#include <string.h>              //include for string.
#include <sys/socket.h>          //includes a number of defination of structures needed for the socket
#include <unistd.h>              //includes posix operation system API
#include <arpa/inet.h>           //includes defination for internet operations
#include <stdbool.h>             //includes standard bool.
#include <pthread.h>             //include function declaration for threading
#include <sys/types.h>           //defines a collection of typedef symbols and structure.

//For macros , use ALL_CAPS separated by underscore.

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
#define SOCKET_CREATE 0         //Return value for socket creation         
#define SOCKET_BIND 0           //Return value for bind function
#define SOCKET_LISTEN 0         //Return value for listen function
#define SOCKET_ACCEPT 0         //Return value for accept function
#define SOCKET_SEND 0           //Return value for send function
#define SOCKET_READ 0           //Return value for read function
#define SOCKET_CONNECT 0        //Return value for connect function
#define SOCKET_CONVERT 0        //Return value for  convert function
#define CHILD_ID 0              //Return value for   fork system call

struct login
{
	char username[MAX_USER_LEN];
	char password[MAX_PSWRD];
};

extern  void login ();
extern  void registration ();
extern  void *loginController ();

#endif

