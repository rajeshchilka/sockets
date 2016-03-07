#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define PORT 5000

int main(int argc, char** argv){
<<<<<<< HEAD
  int listenFD, connectFD;
  struct sockaddr_in serverAddress;

  listenFD = socket(AF_INET, SOCK_STREAM, 0);
  if(listenFD < 0){
    printf("Socket creation failed.\n");
    exit(-1);
  }

  memset(&serverAddress, '0', sizeof(struct sockaddr_in));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(PORT);

  if(bind(listenFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) != 0){
    printf("Can't bind socket to file descriptor.\n");
    exit(-1);
  }

  if(listen(listenFD, 5) != 0){
    printf("Can't bind socket to file descriptor.\n");
    exit(-1);
  }

  printf("Server running on port %d\n", PORT);

  while(1){

  }

  return 0;
}
