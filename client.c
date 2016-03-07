#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include <arpa/inet.h>


#define PORT 5000

int main(int argc, char** argv){
  /*Variables listen and connect file descriptor,
  server address struct info*/
  int clientFD, n;
  struct sockaddr_in serverAddress;
  char message[15];

  /*Socket creation using TCP.*/
  clientFD = socket(AF_INET, SOCK_STREAM, 0);
  if(clientFD < 0){
    printf("Socket creation failed.\n");
    exit(-1);
  }

  /*Initialize struct to 0*/
  memset(&serverAddress, '0', sizeof(struct sockaddr_in));

  /*Set to ipv4, any address, and port PORT*/
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(PORT);

  if(inet_pton(AF_INET, argv[1], &serverAddress.sin_addr)<=0){
      printf("\n inet_pton error occured\n");
      return 1;
  }

  /*Fails here needs to be fixed*/
  if(connect(clientFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0){
      printf("\n Error : Connect Failed \n");
      return 1;
  }

   while ( (n = read(clientFD, message, sizeof(message)-1)) > 0){
       message[n] = 0;
       if(fputs(message, stdout) == EOF)
       {
           printf("\n Error : Fputs error\n");
       }
   }

   if(n < 0){
       printf("\n Read error \n");
   }

  return 0;
}
