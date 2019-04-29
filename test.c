#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	char s[100];
	printf("Enter a string : \n");
	gets(s);
	int fp,i=0;
	fp=open("/dev/myDev",O_RDWR);
	write(fp,s,strlen(s));
	while(read(fp, &s[i++], 1));
	printf("Reversed string = %s \n",s);
	close(fp);
	return 0;
}
