%{
#include <stdio.h>
%}

%%
([1-9][0-9]*)|0	printf("number \n");
[0-9]+\.[0-9]*[1-9]	printf("number \n");
%%
