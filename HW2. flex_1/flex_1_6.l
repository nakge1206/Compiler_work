%{
#include <stdio.h>
%}

%%
([1-9][0-9]*)|0	printf("number => %s(%d)\n", yytext, yyleng);
[0-9]+\.[0-9]*[1-9]	printf("number => %s(%d)\n", yytext, yyleng-1);
.	;
%%
int main(){
	yylex();
	printf("end\n");
}
