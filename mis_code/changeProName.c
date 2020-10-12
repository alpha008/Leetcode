
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char** environ;
int main(int argc, char *argv[])
{
	int i;

    for( i = 0; argv[i]!= NULL; i++)
    {
		printf("%p, argv[%d] = %s\n",&argv[i],i, argv[i]);
        printf("strlen(argv[%d]) = %d\n",i,strlen(argv[i]));
    }
    char *name = "alpha";
    memmove(argv[0],name, sizeof(argv[0]));
	for(i = 0; environ[i]!= NULL;i++)
	{
		printf("%p,environ [%d] = %s\n",&environ[i],i, environ[i]);
	}
    while(1){
        sleep(100);
    }
	return 0;
}
