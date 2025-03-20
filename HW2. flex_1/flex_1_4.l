%{
#include <stdio.h>
%}

%%
([1-9][0-9]*)|0	printf("number=>%s\n", yytext);
[0-9]+\.[0-9]*[1-9]	printf("number=>%s\n", yytext);
.	;
%%
