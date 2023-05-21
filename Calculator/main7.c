#include <stdio.h>
#define NANDATA -32767.0

char token;  
int numnn=0;

double exp(char *);  
double term(char *);  
double factor(char *);  
char getPrintableChar(char *);  

void match(char expectedToken);  
void error(char *);  


#define isdigit(token) ( (token)>='0' && (token)<='9' )
#define isblank(temp) ( (temp)==' ' || (temp)=='\t' )




double CalculateStr(char *str)
{

	double temp=NANDATA;
	char tempstr[100];
	int i,j,k;
	char numk[20];
	int flag=0;

	for(i=0,j=0;str[i];i++)
		if( str[i]!=' ' && str[i]!='\t' )
		{
			tempstr[j]=str[i];
			j++;
		}
	tempstr[j]='\0';

	if(j==0)
		return NANDATA;

	/*
	for(i=0,k=0;i<j;i++)
	{
		if( tempstr[i]=='(' || tempstr[i]==')' )
		{
			numk[k]=tempstr[i];
			k++;
		}
	}

	numk[k]='\0';

	if(k%2)
		return NANDATA;
	*/


	for(i=0,k=0;i<j;i++)
	{
		if( tempstr[i]=='(' || tempstr[i]==')' )
		{
			numk[k]=tempstr[i];
			k++;
		}
	}

return temp;
}




char getPrintableChar(char *str)  
{  
	char temp;  
	do  {
	temp = str[numnn];numnn++;  
	}
	while (isblank(temp));  

	return temp;  
}


double exp(char *str)  
{  
	double temp = term(str);  
	while (token == '+' || token == '-')  
		switch(token)  
	{  
		case '+': match('+');  
			temp += term(str);  
			break;  
		case '-': match('-');  
			temp -= term(str);  
			break;  
	}  
	return temp;  
}  

double term(char *str)  
{  
	
	double temp = factor(str); 
	while (token == '*' || token == '/')  
		switch(token)  
	{  
		case '*': match('*');  
			temp *= factor(str);  
			break;  
		case '/': match('/');  
				  {
					
					  
					  temp /=   factor(str); 
					  break;  
				  }
	}  
	return temp;  
}  


double factor(char *str)  
{  
	double temp;  
	if (token == '(')  
	{  
		match('(');  
		temp = exp(str);  
		match(')');  
	} 
	else if (isdigit(token))  
	{  
		temp=token-'0';
		token = getPrintableChar(str);  
	} 

	return temp;  
}  

int main()
{
	char str[30]="2*(3+5)";

	token = getPrintableChar(str); 
	result = exp(str);  

	printf("token=%c\n",token);

	printf("over\n");getchar();
return 0;
}