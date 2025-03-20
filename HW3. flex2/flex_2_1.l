%{
#include <stdio.h>
int count=0;
%}
%s A
%%
"("	BEGIN A;
<A>")"	BEGIN 0;
<A>a	count++;
<A>.	;
.	;
%%
int main(){
	yylex();
	printf(" %d \n", count);
}
