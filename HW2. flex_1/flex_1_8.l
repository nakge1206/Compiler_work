%{
#include <stdio.h>
int count=0;
%}
word	[a-zA-Z]([a-zA-Z0-9]|\_|\$)*
%%
if	count++;
{word}	;
.|\n	;
%%
int main(){
	yylex();
	printf("number of IF statements => %d \n", count);
}
