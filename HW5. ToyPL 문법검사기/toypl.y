%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%union {
    int num;
    char *name;
}

%token TPROGRAM TMAIN TPROC TFUNC TRETURNS TVAR TINT TLONG TIF TTHEN TELSE TWHILE TFOR TTO TCALL TRETURN TBEGIN TEND
%token <num> TNUMBER
%token <name> TNAME
%token TEQUAL TAND TOR TNOT TLESS TLESSEQ TGREATER TGREATEREQ TNOTEQ TPLUS TMINUS TMULT TDIV TSEMI TCOLON TCOMMA TDOT TLPAREN TRPAREN

%type <num> Expr Term Fact
%type <name> Var

%%

Program:
	TPROGRAM TNAME TSEMI SubPgmList TMAIN VarDecl CompStmt TDOT
	;

VarDecl:
	TVAR DclList TSEMI
	|
	;

DclList:
	DclList TSEMI Decl
	| Decl
	;

Decl:
	VarList TCOLON Type
	;

VarList:
	VarList TCOMMA Var
	| Var
	;

Type:
	TINT
	| TLONG
	;

Var:
	TNAME
	;

SubPgmList:
	SubPgmList SubPgm
	|
	;
	
SubPgm:
	ProcDecl
	| FunDecl
	;
	
ProcDecl:
	TPROC ProcName TLPAREN FormParam TRPAREN VarDecl CompStmt
	;
	
ProcName:
	TNAME
	;

FunDecl:
	TFUNC FuncName TLPAREN FormParam TRPAREN TRETURN TLPAREN Type TRPAREN
	;
	
FuncName:
	TNAME
	;

FormParam:
	DclList
	|
	;

Cond:
	Cond TAND Rel
	| Cond TOR Rel
	| TNOT Rel
	| Rel
	;
	
Rel:
	Expr TLESS Expr
	| Expr TLESSEQ Expr
	| Expr TGREATER Expr
	| Expr TGREATEREQ Expr
	| Expr TEQUAL Expr
	| Expr TNOTEQ Expr
	;

Expr:
	Expr TPLUS Term
	| Expr TMINUS Term
	| Term
	;

Term:
	Term TMULT Fact
	| Term TDIV Fact
	| Fact
	;

Fact:
	Var
	| TNUMBER
	| FuncCall
	| TMINUS Fact
	| TLPAREN Expr TRPAREN
	;

FuncCall:
	FuncName TLPAREN ParamList TRPAREN
	;

ParamList:
	ExprList
	|
	;
	
ExprList:
	ExprList TCOMMA Expr
	| Expr
	;
	
Stmt:
	AsgnStmt
	| IfStmt
	| WhileStmt
	| ForStmt
	| CallStmt
	| RtrnStmt
	| CompStmt
	;

AsgnStmt:
	Var TEQUAL Expr
	;
	
IfStmt:
	TIF TLPAREN Cond TRPAREN TTHEN Stmt
	| TIF TLPAREN Cond TRPAREN TTHEN Stmt TELSE Stmt
	;
	
WhileStmt:
	TWHILE TLPAREN Cond TRPAREN Stmt
	;
	
ForStmt:
	TFOR TLPAREN Var TEQUAL Expr TTO Expr TRPAREN Stmt
	;

CallStmt:
	TCALL ProcName TLPAREN ParamList TRPAREN
	;

RtrnStmt:
	TRETURN TLPAREN Expr TRPAREN
	;
	
CompStmt:
	TBEGIN StmtList TEND
	;
	
StmtList:
	StmtList TSEMI Stmt
	| Stmt
	;

%%

void yyerror(const char *s) {
    fprintf(stderr, "syntax error\n");
}

int main(void) {
    return yyparse();
}

