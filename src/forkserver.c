/*This the file for server program
* Here we define all the include statements,libraries,structures to declare  the function
*we use macros for define the port number. 
*/



#include "../inc/server.h"


int main(int argc, char const* argv[])  
{
    int server_fd, client_socket, valread;      

    struct sockaddr_in address;

    int sock = 0;

     struct sockaddr_in serv_addr;
    
    int addrlen = sizeof(address);     //For length of the address

    char buffer[MAX_LEN] = { 0 };      //initializing the buffer.

    pid_t childpid;                       //The process ID to hold the childprocessId
    
/*create the socket file.
 *for creating the socket file we are passing three arguments that is internet protocol,stream socket and the TCP protocol.
 *if the arguments are equal to null then it returns fail,or else the socket created successfully.
 */

    if ((server_fd = socket(AF_INET, SOCK_STREAM, IPPRO_TCP))== SOCKET_CREATE) 
    {
        perror("socket failed");      //Printing socket creation is failed

        exit(EXIT_FAILURE);           
    }
    else
        printf("Socket sucessfully created..\n");

    //Socket information

	    address.sin_family = AF_INET;         //AF_INET is belong to IPV4 family.

        address.sin_addr.s_addr = INADDR_ANY;   //INADDR_ANY is used to specify the IP address.

        address.sin_port = htons(PORT_NO);      //Port address creation.
    
    //Bind the socket to our specified IP and PORT.

    if (bind(server_fd, (struct sockaddr*)&address,
                    sizeof(address))< SOCKET_BIND) 

     {
        perror("bind failed");      //for printing the error message.

        exit(EXIT_FAILURE);
     }

     else

		printf("Successfully binding...\n");
		
      //listen the request from the client	

     if (listen(server_fd, BACKLOG) 
                    < SOCKET_LISTEN)
     {
        perror("listen");       //Printing the error message.

        exit(EXIT_FAILURE);
     }
     
     while(TRUE)
     {
       if ((client_socket = accept(server_fd, (struct sockaddr*)&address,
                  (socklen_t*)&addrlen)) < SOCKET_ACCEPT) 
       {
         printf("accept");

         exit(EXIT_FAILURE);
       }
       else

         printf("Connnection accepted from %s : %d\n",
               inet_ntoa(address.sin_addr),ntohs(address.sin_port));
     
     //calling the function fork()


       if((childpid=fork())==CHILD_ID)        //For successfully execution of fork() process
       {
         close(server_fd);             //close the file descriptor

         while(TRUE)
       {
       valread = read(client_socket, buffer, MAX_LEN);                 //Read function to read the message from client

       printf("Client:%s\n", buffer);         //print the received message.


       if(strncmp(buffer,END_MSG,BUFF_SIZE)==SOCKET_READ)       
       { 
          printf("Disconnected from %s : %d\n",inet_ntoa(address.sin_addr),ntohs(address.sin_port));
          break;
       }
       printf("\nAt your service:");

       fgets(buffer,MAX_LEN,stdin);
      
       if((send(client_socket,buffer,MAX_LEN, 0)<SOCKET_SEND))        

       {
         perror("Message not send");       //printing the error message

         exit(TRUE);
        }
       }
      }
     }
      
      // closing the connected socket

     close(client_socket);

     // closing the listening socket

    shutdown(server_fd, SHUT_RDWR);      //To shut down all the reception and transmission of message.

    return 0;
}
		
