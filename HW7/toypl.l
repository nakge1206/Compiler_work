%{
#include "toypl.tab.h"
%}
%s COMMENT

%%

program	{ return TPROGRAM; }
main	{ return TMAIN; }
proc	{ return TPROC; }
func	{ return TFUNC; }
returns	{ return TRETURNS; }
var	{ return TVAR; }
int	{ return TINT; }
long	{ return TLONG; }
if	{ return TIF; }
then	{ return TTHEN; }
else	{ return TELSE; }
while	{ return TWHILE; }
for	{ return TFOR; }
to	{ return TTO; }
call	{ return TCALL; }
"return"	{ return TRETURN; }
begin	{ return TBEGIN; }
end	{ return TEND; }

([1-9][0-9]*)|0	{ yylval.dval = atoi(yytext); return TNUMBER; }
[a-zA-Z][a-zA-Z0-9_]*	{ yylval.sval = strdup(yytext); return TNAME; }

"="	{ return TEQUAL; }
"&"	{ return TAND; }
"|"	{ return TOR; }
"!"	{ return TNOT; }
"<"	{ return TLESS; }
"<="	{ return TLESSEQ; }
">"	{ return TGREATER; }
">="	{ return TGREATEREQ; }
"!="	{ return TNOTEQ; }
"+"	{ return TPLUS; }
"-"	{ return TMINUS; }
"*"	{ return TMULT; }
"/"	{ return TDIV; }
";"	{ return TSEMI; }
":"	{ return TCOLON; }
","	{ return TCOMMA; }
"."	{ return TDOT; }
"("	{ return TLPAREN; }
")"	{ return TRPAREN; }

"/*"	{ BEGIN(COMMENT); }
<COMMENT>[^*]*	;
<COMMENT>"*"+[^/]	;           
<COMMENT>"*/"	{ BEGIN(INITIAL); }

[ \t\n\r]+          ;


%%

int yywrap() { return 1; }

