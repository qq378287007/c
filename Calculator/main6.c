#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>

char token;  
int num;

//double exp(void);  
//double term(void);  
//double factor(void);  
//char getPrintableChar(void);  

//void match(char expectedToken);  
//void error(void);  


double exp(char *str) ;


//#define isdigit(token) ( ( (token)>='0' && (token)<='9' ) ||  (token)=='.')
#define isdigit(token) ( (token)>='0' && (token)<='9' )

#define isblank(temp) ( (temp)==' ' || (temp)=='\t' )

#define iszifu(token) ( (token)>='a' && (token)<='z' )

double data[10]={0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
double str2dou(char *str);

char getPrintableChar(char *str)  
{  
	char temp;  
	do 
	{
		temp = str[num];num++;  
	}while (isblank(temp));  

	return temp;  
}

void error(void)  
{  
	fprintf(stderr, "Error!\n");  getchar(); getchar();
	exit(EXIT_FAILURE);  
}  

void match(char expectedToken,char *str)  
{  
	if (expectedToken == token)  
		token = getPrintableChar(str);  
	else  
		error();  
}

double factor(char *str)  
{  
	double temp;  
	int flag=0;
	int j=0;
	if (token == '(')  
	{  
		match('(',str);  
		temp = exp(str);  
		match(')',str);  
	} 
	else if (isdigit(token))  
	{  
		temp=token-'0';
		token = getPrintableChar(str);  
		while(isdigit(token)||token=='.')
		{
			if(token=='.')
			{
				flag=1;
			}
			else
			{
				if(flag)
				{
					j++;
					temp=temp+(token-'0')/pow(10.0,j);
				}
				else
				{
					temp=temp*10+token-'0';
				}
			}
		}
	}
	else  
		error();  

	return temp;  
}  

double term(char *str)  
{  
	double temp2;
	double temp = factor(str); 
	while (token == '*' || token == '/')  
		switch(token)  
	{  
		case '*': match('*',str);  
			temp *= factor(str);  
			break;  
		case '/': match('/',str);  
				  {
					  temp2=factor(str);
					  if(abs(temp2-0.0)<=0.000001)
						  error();
					  temp /= temp2;  
					  break;  
				  }
	}  
	return temp;  
}  

double exp(char *str)  
{  
	double temp = term(str);  
	while (token == '+' || token == '-')  
		switch(token)  
	{  
		case '+': match('+',str);  
			temp += term(str);  
			break;  
		case '-': match('-',str);  
			temp -= term(str);  
			break;  
	}  
	return temp;  
} 

int main(void)  
{  
	double result;  
	char *str="(2+3)*(2+3)*(2.5)";
	extern int num;
	num=0;

	token = getPrintableChar(str);  
	if (token == '\0')  
			result =0;
	else
	{
		result = exp(str);  
		if (token == '\0')  
			printf("Result is: %g\n", result);  
	}
	//printf("52.23=%lf\n",str2dou("52.23"));



	printf("over\n");getchar();
	return 0;  
}  


double CalculateStr(char *str)
{

	double temp;
	char tempstr[100];
	int i,j;

	for(i=0,j=0;str[i];i++)
	{
		if( str[i]!=' ' && str[i]!='\t' )
		{
			tempstr[j]=str[i];
			j++;
		}

	}



return temp;
}




double str2dou(char *str)
{
	double temp=0.0;
	int i=0,j=0;

	while(isdigit(str[i]) || isblank(str[i]))
	{
		if isblank(str[i])
		{
			i++;
			continue;
		}
		else
		{
			temp=temp*10+str[i]-'0';
			i++;
		}
	}

	while(str[i]=='.' || isblank(str[i]))
	{
		i++;
	}

	while(isdigit(str[i]) || isblank(str[i]))
	{
		if isblank(str[i])
		{
			i++;
			continue;
		}
		else
		{
			j++;
			temp=temp+(str[i]-'0')/pow(10.0,j);
			i++;
		}
	}



	return temp;
}