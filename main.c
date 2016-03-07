#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define PORT 5000

int main(int argc, char** argv){
  /*Variables listen and connect file descriptor,
  server address struct info*/
  int listenFD, connectFD;
  struct sockaddr_in serverAddress;
  char message[15] = "Hello Client";

  /*Socket creation using TCP.*/
  listenFD = socket(AF_INET, SOCK_STREAM, 0);
  if(listenFD < 0){
    printf("Socket creation failed.\n");
    exit(-1);
  }

  /*Initialize struct to 0*/
  memset(&serverAddress, '0', sizeof(struct sockaddr_in));

  /*Set to ipv4, any address, and port PORT*/
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(PORT);

  /*Bind the server address to the newly created socket.*/
  if(bind(listenFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) != 0){
    printf("Can't bind socket to file descriptor.\n");
    exit(-1);
  }

  /*Set this socket to listening, with 5 on listening queue.*/
  if(listen(listenFD, 5) != 0){
    printf("Can't bind socket to file descriptor.\n");
    exit(-1);
  }

  /*If this message prints, then it's safe to say that the server is listening*/
  printf("Server running on port %d\n", PORT);

  while(1){
    /*accept connection.*/
      connectFD = accept(listenFD, (struct sockaddr*)NULL, NULL);

    /*Send message message to client*/
    send(connectFD, message, sizeof(message), 0);

    /*close the file descriptor*/
    close(connectFD);

  }

  return 0;
}
