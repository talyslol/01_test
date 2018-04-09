#include<string.h>
#include<stdio.h>
int hexToDec(char hexChar)
{
	if(hexChar<='9'&& hexChar>='0')
	{
		return hexChar - 48;
	}
	if(hexChar <='f'&&hexChar>='a')
	{
		return hexChar-'a'+ 10;
	}
	if(hexChar <='F'&&hexChar>='A')
	{
		return hexChar-'A' + 10;
	}

	
}
unsigned char hexstrToDec(char* hexstr)
{
	unsigned char c = hexToDec(hexstr[0])*16 + hexToDec(hexstr[1]);
	printf("c = %d\n",c);
	return hexToDec(hexstr[0])*16 + hexToDec(hexstr[1]);
}

void httpToUTF8(char*buf,char*UTF)
{
	int i=0;	
	int len = strlen(buf);
	int s = 0;
	while(i<len)
	{
		if(buf[i]=='%')
		{
			UTF[s] = hexstrToDec(&buf[i+1]);
			i+=3;
			s++;
		}
		else
		{
			UTF[s]=buf[i];
			i++;
			s++;
		}

	}
}


int main()
{
	char bufUTF[1024] = {0};
	char buf[1024]={"%E4%BB%8A%E5%A4%A9%E4%BD%A0haha%E5%90%83%E4%BA%86%E5%90%97"};
	httpToUTF8(buf,bufUTF);
	printf("%s\n",bufUTF);

	return 0;
}
