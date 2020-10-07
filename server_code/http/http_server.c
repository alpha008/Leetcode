#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("socket");
        return -1;
    }
    struct sockaddr_in my_addr;
    bzero(&my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htonl(8000);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int err_log = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr));
    if(err_log != 0){
        perror("bind");
        return -1;
    }
    err_log = listen(sockfd, 10);
    if(err_log !=0){
        perror("listen");
        close(sockfd);
        return -1;
    }
    printf("listen client @ port = %d\n",8000);
    int connfd = accept(sockfd ,NULL, NULL);
    char buffer[8*1024] = {0};
    read(connfd, buffer ,sizeof(buffer));
    printf("%s",buffer);

    return 0;
}