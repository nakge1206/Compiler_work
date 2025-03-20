%{
#include <stdio.h>
%}
%s A
%s B
%%
"{"	BEGIN A; ECHO;
<A>"/*"	BEGIN B;
<B>"*/"	BEGIN A;
<A>"}"	BEGIN 0; ECHO;
<B>.	;
<A>.	ECHO;
.|\n	ECHO;
%%
int main(){
	yylex();
}
