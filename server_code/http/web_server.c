#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0){
        perror("socket");
        return -1;
    }
    struct sockaddr_in my_addr;
    bzero(&my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(8000);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int err_log = bind(sockfd ,(struct sockaddr*) &my_addr, sizeof(my_addr));
    if(err_log !=0){
        perror("binding");
        close(sockfd);
        return -1;
    }
    err_log = listen(sockfd , 10);
    if(err_log !=0){
        perror("listen");
        close(sockfd);
        return -1;
    }
    printf("listen client @ port = %d\n", 8000);
    int connfd;
    connfd = accept(sockfd, NULL, NULL);
    char recv_buf[8*1024] = {0};
    read(connfd, recv_buf, sizeof(recv_buf));
    printf("%s",recv_buf);
    char filename[200] = {0};
    sscanf(recv_buf, "GET /%[^ ]",filename);
    printf("filename = %s\n",filename);
    int fd;
    fd = open(filename, O_RDONLY);
    if(fd < 0)
    {
        char err[] = "HTTP/1.1 404 Not Found\r\n"	//状态行
					"Content-Type: text/html\r\n"	//响应头部
					"\r\n"							//空行
					"<HTML><BODY>File not found</BODY></HTML>";  //响应包体  
        perror("open");
        send(connfd, err, strlen(err), 0); 
        close(connfd);
        return -1;        
    }
	//HTTP 响应报文由状态行、响应头部、空行、响应包体4个部分组成
	char head[] = "HTTP/1.1 200 OK\r\n" 	//状态行
			  "Content-Type: text/html\r\n"	//响应头部
			  "\r\n";						//空行
    send(connfd, head, strlen(head), 0);
    int len =0;
    char file_buf[4*1024] = {};
    while ((len = read(fd, file_buf, sizeof(file_buf))) > 0)
    {
        send(connfd, file_buf,len ,0);
    }
    close(fd);
    close(connfd);
 
    return 0;
}   

