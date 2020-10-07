#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>



int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("sockfd err");
        return -1;
    }
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family =  AF_INET;
    server_addr.sin_port = htons(8000);
    inet_pton(AF_INET, "182.254.181.144", &server_addr.sin_addr);
    int err_log = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(err_log != 0){
        perror("connect ");
        close(sockfd);
        return -1;
    }
   	char send_buf[] = 
		"GET /alpha.html HTTP/1.1\r\n"
		"Accept: image/gif, image/jpeg, image/pjpeg, application/x-ms-application, application/xaml+xml, application/x-ms-xbap, */*\r\n"
		"Accept-Language: zh-Hans-CN,zh-Hans;q=0.8,en-US;q=0.5,en;q=0.3\r\n"
		"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36\r\n"
		"Accept-Encoding: gzip, deflate\r\n"
		"Host: 192.168.52.139:8000\r\n"
		"Connection: Keep-Alive\r\n"
		"\r\n";

    send(sockfd, send_buf, sizeof(send_buf) -1, 0);
    char recv_buf[8*1024] = {0};
    recv(sockfd, recv_buf,sizeof(recv_buf), 0);
    printf("%s",recv_buf);
    return 0;
}