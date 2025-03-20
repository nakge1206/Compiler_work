%{
#include <stdio.h>
%}
%s CMT
%%
"/*"	{ BEGIN(CMT); }
<CMT>"*/"	{ BEGIN(INITIAL); }
<CMT>.	{ }
<CMT>\n	{ }

<INITIAL>"program"	{ printf("TPROGRAM"); }
<INITIAL>"main"	{ printf("TMAIN"); }
<INITIAL>"proc"	{ printf("TPROC"); }
<INITIAL>"func"	{ printf("TFUNC"); }
<INITIAL>"returns"	{ printf("TRETURNS"); }
<INITIAL>"var"	{ printf("TVAR"); }
<INITIAL>"int"	{ printf("TINT"); }
<INITIAL>"long"	{ printf("TLONG"); }
<INITIAL>"if"	{ printf("TIF"); }
<INITIAL>"then"	{ printf("TTHEN"); }
<INITIAL>"else"	{ printf("TELSE"); }
<INITIAL>"while"	{ printf("TWHILE"); }
<INITIAL>"for"	{ printf("TFOR"); }
<INITIAL>"to"	{ printf("TTO"); }
<INITIAL>"call"	{ printf("TCALL"); }
<INITIAL>"return"	{ printf("TRETURN"); }
<INITIAL>"begin"	{ printf("TBEGIN"); }
<INITIAL>"end"	{ printf("TEND"); }

<INITIAL>"="	{ printf("TASS"); }
<INITIAL>"&"	{ printf("TAND"); }
<INITIAL>"|"	{ printf("TOR"); }
<INITIAL>"!"	{ printf("TNOT"); }
<INITIAL>"<"	{ printf("TLT"); }
<INITIAL>"<="	{ printf("TLE"); }
<INITIAL>">"	{ printf("TGT"); }
<INITIAL>">="	{ printf("TGE"); }
<INITIAL>"!="	{ printf("TNE"); }
<INITIAL>"+"	{ printf("TPLUS"); }
<INITIAL>"-"	{ printf("TMINUS"); }
<INITIAL>"*"	{ printf("TMUL"); }
<INITIAL>"/"	{ printf("TDIV"); }

<INITIAL>";"	{ printf(";"); }
<INITIAL>":"	{ printf(":"); }
<INITIAL>"("	{ printf("("); }
<INITIAL>")"	{ printf(")"); }
<INITIAL>","	{ printf(","); }
<INITIAL>"."	{ printf("."); }

<INITIAL>[a-zA-Z]+[a-zA-Z0-9]*	{ printf("TWORD"); }
<INITIAL>([1-9][0-9]*)|0	{ printf("TNUMBER="); ECHO; }

%%

int main(void) {
    yylex();
    return 0;
}

