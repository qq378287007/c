#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>

char token;  

double express(void);  
double term(void);  
double factor(void);  
char getPrintableChar(void);  

void match(char expectedToken);  
void error(void);  

//#define isdigit(token) ( ( (token)>='0' && (token)<='9' ) ||  (token)=='.')
#define isdigit(token) ( (token)>='0' && (token)<='9' )

#define isblank(temp) ( (temp)==' ' || (temp)=='\t' )

#define iszifu(token) ( (token)>='a' && (token)<='z' )

double data[10]={0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
double str2double(char *str);

//去除首尾空格
char * strim(char *str)
{
	char *end, *sp, *ep;
	int len;
	sp = str;
	end = str + strlen(str) - 1;
	ep = end;
 
	while(sp<=end && isspace(*sp))
		sp++;
	while(ep>=sp && isspace(*ep))
		ep--;
	len = (ep < sp) ? 0:(ep-sp)+1;//(ep < sp)判断是否整行都是空格
	sp[len] = '\0';
	return sp;
}

int main(void)  
{  
	double result;  

#if 0

	while(1)
	{  
		token = getPrintableChar();  
		if (token == '\n')  
			return 0;

		result = express();  
		if (token == '\n')  
			printf("Result is: %g\n", result);  
		//else  error();  
	}  
#endif


	printf("52.23=%lf\n", str2double("52.23"));

	printf("over\n");getchar();
	return 0;  
}  

double express(void)  
{  
	double temp = term();  
	while (token == '+' || token == '-')  
		switch(token)  
	{  
		case '+': match('+');  
			temp += term();  
			break;  
		case '-': match('-');  
			temp -= term();  
			break;  
	}  
	return temp;  
}  

double term(void)  
{  
	double temp2;
	double temp = factor(); 
	while (token == '*' || token == '/')  
		switch(token)  
	{  
		case '*': match('*');  
			temp *= factor();  
			break;  
		case '/': match('/');  
				  {
					  temp2=factor();
					  if(abs(temp2-0.0)<=0.000001)
						  error();
					  temp /= temp2;  
					  break;  
				  }
	}  
	return temp;  
}  

double factor(void)  
{  
	double temp;  
	if (token == '(')  
	{  
		match('(');  
		temp = express();  
		match(')');  
	} 
	else if (isdigit(token))  
	{  
		ungetc(token, stdin);  
		scanf("%lf", &temp);  
		token = getPrintableChar();  
	} 

	else if (iszifu(token))  
	{  
		temp=data[token-'a'];
		//printf("token=%d,temp=%f\n",token-'a',temp);getchar();
		token = getPrintableChar();  
	} 
	else  
		error();  

	return temp;  
}  

void error(void)  {  
	fprintf(stderr, "Error!\n");  getchar(); getchar();
	exit(EXIT_FAILURE);  
}  

void match(char expectedToken)  {  
	if (expectedToken == token)  
		token = getPrintableChar();  
	else  
		error();  
}  

char getPrintableChar(void){  
	char temp;  
	do  
	temp = getchar();  
	while (isblank(temp));  

	return temp;  
}

double str2double(char *str){
	double temp=0.0;
	int i=0,j=0;

	while(isdigit(str[i]) || isblank(str[i])){
		if isblank(str[i]){
			i++;
			continue;
		}else{
			temp=temp*10+str[i]-'0';
			i++;
		}
	}

	while(str[i]=='.' || isblank(str[i])){
			i++;
	}

	while(isdigit(str[i]) || isblank(str[i])){
		if isblank(str[i]){
			i++;
			continue;
		}else{
			j++;
			temp=temp+(str[i]-'0')/pow(10.0,j);
			i++;
		}
	}
	return temp;
}