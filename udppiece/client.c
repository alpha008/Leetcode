#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
 
int main()
{
     //创建socket对象
     int sockfd=socket(AF_INET,SOCK_DGRAM,0);
 
     //创建网络通信对象
     struct sockaddr_in addr;
     addr.sin_family =AF_INET;
     addr.sin_port =htons(8896);
     addr.sin_addr.s_addr = inet_addr("182.254.181.144"); //IP根据server所在主机的IP设定，这里是运行在同一PC端 
       #define N 6000
        char szBuf[N] = {0};
        unsigned int i = 0;
        for( i = 0; i < N ; i++) //字符数组最后一个字符不要求是‘\0’
        {
            szBuf[i] = 'a';
        }
         sendto(sockfd,&szBuf, sizeof(szBuf),0,(struct sockaddr*)&addr,sizeof(addr));
 
         socklen_t len=sizeof(addr);
         //recvfrom(sockfd,&buf,sizeof(buf),0,(struct sockaddr*)&addr,&len); 

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
#include <errno.h>

//tcpdump -iany src host 10.100.70.139 -Xnlps0
int main(int argc, char *argv[])
{
    struct sockaddr_in srvAddr;
    bzero(&srvAddr, sizeof(srvAddr));
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_addr.s_addr = inet_addr("172.16.0.17");
    srvAddr.sin_port = htons(8765);
    int iSock = socket(AF_INET, SOCK_DGRAM, 0); // udp
    #define N 8000
    char szBuf[N] = {0};
    unsigned int i = 0;
    for( i = 0; i < N -1; i++) //字符数组最后一个字符不要求是‘\0’
    {

        szBuf[i] = 'a';

    }

        szBuf[i] = 'b';
    int iRet = sendto(iSock, szBuf, sizeof(szBuf), 0, (struct sockaddr *)&srvAddr, sizeof(srvAddr));
    printf("send size is %d, iRet is %d, errmsg[%s]\n", sizeof(szBuf), iRet, strerror(errno));

    close(iSock);

    return 0;

}
#endif
