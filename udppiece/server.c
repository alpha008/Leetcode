#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
 
int main()
{
     //创建socket对象
     int sockfd=socket(AF_INET,SOCK_DGRAM,0);
 
     //创建网络通信对象
     struct sockaddr_in addr;
     addr.sin_family =AF_INET;
     addr.sin_port = htons(8896);
     //addr.sin_addr.s_addr = inet_addr("182.254.181.144");
      addr.sin_addr.s_addr = htonl(INADDR_ANY);
     //绑定socket对象与通信链接
     int ret = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
     if(0 > ret)
     {
         printf("bind\n");
         return -1;
 
     }
     struct sockaddr_in cli;
     socklen_t len=sizeof(cli);
 
     while(1)
     {
         char buf[8000]={0};
         recvfrom(sockfd,&buf,sizeof(buf),0,(struct sockaddr*)&cli,&len);
         printf("recv buf =%s\n",buf);
 
         //sendto(sockfd,&buf,sizeof(buf),0,(struct sockaddr*)&cli,len);
 
     }
     close(sockfd);
 
}

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
    struct sockaddr_in srvAddr;
    bzero(&srvAddr,sizeof(srvAddr));
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    srvAddr.sin_port = htons(8766);
    int srvAddrLen = sizeof(srvAddr);
    int iSock = socket(AF_INET, SOCK_DGRAM, 0);  // udp
    bind(iSock, (struct sockaddr *)&srvAddr, sizeof(srvAddr));
    while(1)
    {

        char szBuf[3000] = {0};
        recvfrom(iSock, szBuf, sizeof(szBuf) - 1, 0, (struct sockaddr *)&srvAddr, (socklen_t*)&srvAddrLen);
        printf("msg from client [%s]\n", szBuf);

    }
    close(iSock);

    return 0;

}
#endif
