#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stddef.h>
#include<assert.h>
#include<hiredis/hiredis.h>

void dotest()
{
    redisContext *c = redisConnect("127.0.0.1", 6379);
    if(c->err){
        redisFree(c);
        printf("connect to redisServer failed\n");
        return ;
    }
    printf("connetc to redisServer sucess\n");
    const char * command1 = "set key1 alpha";
    redisReply *r = (redisReply*) redisCommand(c, command1);
    if(r == NULL){
        printf("Eexcut Command failed\n");
        redisFree(c);
        return ;
    }
    if(!(r->type == REDIS_REPLY_STATUS && strcasecmp(r->str, "OK") == 0))
    {
        printf("failed to execute command %s\n" , command1);
        freeReplyObject(r);
        redisFree(c);
        return NULL;
    }
    freeReplyObject(r);
    printf("suuceed to execute command %s",command1);

    const char *command2 =  "strlen key1";
    r = (redisReply *) redisCommand(c, command2);
    if(r->type != REDIS_REPLY_INTEGER){
        printf("failed to execute command %s", command2);
        freeReplyObject(r);
        redisFree(c);
        return ;
    }
    int length = r->integer;
    freeReplyObject(r);
    printf("the length of key1 is %d",length);
    printf("suceed to execute command %s\n",command2);
}

int main()
{
    dotest();
    return 0;
}