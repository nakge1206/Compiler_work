%{
#include <stdio.h>
int count=0;
%}
%%
\"([^"]|\\.)*\"	count++;
.|\n	;
%%
int main(){
	yylex();
	printf("따옴표 사이 스트링 => %d \n", count);
}
