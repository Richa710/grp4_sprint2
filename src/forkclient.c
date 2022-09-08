/*This the file for client program
* Here we define all the include statements,libraries,structures to declare the function
*we use macros for define the port number. 
*/


#include "../inc/socket.h"

int main(int argc, char const* argv[])

{
    int sock = 0, valread, client_fd;

    struct sockaddr_in serv_addr;
    
    char buffer[MAX_LEN] = { 0 };   // Initializing the buffer 

    loginController ();     //to control the login credentials that is registration and login
    
    /*create the socket file.
 *for creating the socket file we are passing three arguements that is internet protocol,stream socket and the TCP protocol.
 *if the arguements are equal to null then it returns fail,or else the socket created successfully.
 */
     if ((sock = socket(AF_INET, SOCK_STREAM, IPPRO_TCP)) < SOCKET_CREATE) 
     {
        perror("Socket Failed..\n");              //for displaying the descriptive error message
        
	     exit(EXIT_FAILURE);

     }
     else

		printf("Socket sucessfully created..\n");

 
/*configure the setting of the server address.
 *the address of the server family is internet and setting the port number by using the function htons to proper byte order
 */
 
    serv_addr.sin_family = AF_INET;       //AF_INET fot IPV4.

    serv_addr.sin_port = htons(PORT_NO);   //port address creation
    
    // Convert IPv4 and IPv6 addresses from text to binary form

    if (inet_pton(AF_INET, IP_ADDRESS, 
        &serv_addr.sin_addr)<= SOCKET_CONVERT)

    {
        perror("\nInvalid address\n");     //for displaying the descriptive error message
        exit(EXIT_FAILURE);
      
    }
    else
		printf("Valid address\n");
		
    
    //for connection of the socket to the server using the address structure

     if ((client_fd = connect(sock, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))< SOCKET_CONNECT) 
     {
        perror("\nConnection Failed \n");
        return -1;
     }
     else
		printf("Connected");
		
    while(TRUE)
    {

     printf("\nclient:");      

     fgets(buffer,MAX_LEN,stdin);

     if((send(sock,buffer ,MAX_LEN, 0)<SOCKET_SEND))        //for sending message to the server

     {
       perror("Message not send");       //Printing error message

       exit(EXIT_FAILURE);
     }
     else
     {
        if(strncmp(buffer,END_MSG,BUFF_SIZE)==SOCKET_SEND)

        { 
          printf("Disconnected from server\n");

          break;
        }
     }
     
     
     valread = read(sock, buffer, MAX_LEN);   //read function to read the message from server

     if(valread<SOCKET_READ)
     {
       perror("Message not received");

       exit(EXIT_FAILURE);
     }
     else
     {
       if(strncmp(buffer,END_MSG,BUFF_SIZE)==SOCKET_READ)      //For disconnecting from server

       {
          printf("Disconnected from server.\n");     

          break;
       }
       printf("\nAt your service:%s\n", buffer);
     }
    }
    
     // closing the connected socket

     close(client_fd);              //closing the file descriptor

     return 0;
}
 