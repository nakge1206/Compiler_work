%{
#include <stdio.h>
int count=0;
%}
letter	[a-zA-Z]
digit	[0-9]
word	letter(letter|digit|_)*
%%
{word}	count++;
.|\n	;
%%
int main(){
	yylex();
	printf("word count = %d \n", count);
}
