%{
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
Node * rootNode;

void yyerror(const char *s);
int yylex(void);
%}

%union {
    double dval;
    char * sval;
    struct _node * nodeP;
}



%token TPROGRAM TMAIN TPROC TFUNC TRETURNS TVAR TINT TLONG TIF TTHEN TELSE TWHILE TFOR TTO TCALL TRETURN TBEGIN TEND
%token <dval> TNUMBER
%token <sval> TNAME
%token TEQUAL TAND TOR TNOT TLESS TLESSEQ TGREATER TGREATEREQ TNOTEQ TPLUS TMINUS TMULT TDIV TSEMI TCOLON TCOMMA TDOT TLPAREN TRPAREN

%type <nodeP> Program VarDecl DclList Decl VarList Type Var SubPgmList SubPgm ProcDecl FunDecl FormParam Cond Rel Expr Term Fact FuncCall ParamList ExprList Stmt AsgnStmt IfStmt WhileStmt ForStmt CallStmt RtrnStmt CompStmt StmtList

%%

Program: //이상없음
	TPROGRAM TNAME TSEMI SubPgmList TMAIN VarDecl CompStmt TDOT {
		rootNode = makeNode("PROGRAM", $4, $6);
		$6->bro = $7;
	}
	;

VarDecl: //이상없음
	TVAR DclList TSEMI	{
		$$ = makeNode("VARDECL", NULL, $2);
	}
	|	{	$$=NULL;	}
	;

DclList: //이상없음
	DclList TSEMI Decl {
		$$ = $1;
		Node* temp = $1;
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = $3;
	}
	| Decl	{	$$=$1;	}
	;

Decl: //이상없음
	VarList TCOLON Type {
		$$ = makeNode("DECL", NULL, $1);
		Node* temp = $1;
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = $3;
	}
	;

VarList: //이상없음
	VarList TCOMMA Var{
		$$ = $1;
		Node* temp = $1;
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = $3;
	}
	| Var { $$=$1; }
	;

Type: //이상없음
	TINT {
		$$ = makeNode("TINT", NULL, NULL);
	}
	| TLONG {
		$$ = makeNode("TLONG", NULL, NULL);
	}
	;

Var: //이상없음
	TNAME {
		$$=makeNode("NAME", NULL, NULL);
	}
	;

SubPgmList: //이상없음
	SubPgmList SubPgm {
		if($1==NULL){
			$$ = $2;
		} else{
			$$ = $1;
			Node* temp = $1;
			while(temp->bro != NULL) { temp=temp->bro; }
			temp->bro = $2;
		}
	}
	|	{	$$=NULL;	}
	;

SubPgm: //이상없음
	ProcDecl	{	$$=$1;	}
	| FunDecl	{	$$=$1;	}
	;
	
ProcDecl: //이상없음
	TPROC Var TLPAREN FormParam TRPAREN VarDecl CompStmt {
		$$ = makeNode("PROC", NULL, $2);
		$2->bro = $4;
		$4->bro = $6;
		$6->bro = $7;
	}
	;

FunDecl: //이상없음
	TFUNC Var TLPAREN FormParam TRPAREN TRETURN TLPAREN Type TRPAREN {
		$$ = makeNode("FUNC", NULL, $2);
		$2->bro = $4;
		$4->bro = $8;
	}
	;

FormParam: //이상없음
	DclList { $$=$1; }
	| { $$=NULL; }
	;

Cond: //이상없음
	Cond TAND Rel {
		$$ = makeNode("AND", NULL, $1);
		$1->bro = $3;
	}
	| Cond TOR Rel {
		$$ = makeNode("OR", NULL, $1);
		$1->bro = $3;
	}
	| TNOT Rel {
		$$ = makeNode("NOT", NULL, $2);
	}
	| Rel { $$ = $1; }
	;
	
Rel: //이상없음
	Expr TLESS Expr{
		$$ = makeNode("LT", NULL, $1);
		$1->bro = $3;
	}
	| Expr TLESSEQ Expr {
		$$ = makeNode("LE", NULL, $1);
		$1->bro = $3;
	}
	| Expr TGREATER Expr {
		$$ = makeNode("GT", NULL, $1);
		$1->bro = $3;
	}
	| Expr TGREATEREQ Expr {
		$$ = makeNode("GE", NULL, $1);
		$1->bro = $3;
	}
	| Expr TEQUAL Expr {
		$$ = makeNode("EQ", NULL, $1);
		$1->bro = $3;
	}
	| Expr TNOTEQ Expr {
		$$ = makeNode("NE", NULL, $1);
		$1->bro = $3;
	}
	;

Expr: //이상없음
	Expr TPLUS Term {
		$$=makeNode("PLUS", NULL, $1);
		$1->bro = $3;
	}
	| Expr TMINUS Term{
		$$=makeNode("MINUS", NULL, $1);
		$1->bro = $3;
	}
	| Term	{	$$ = $1;	}
	;

Term: //이상없음
	Term TMULT Fact {
		$$=makeNode("TIMES", NULL, $1);
		$1->bro = $3;
	}
	| Term TDIV Fact {
		$$=makeNode("DIV", NULL, $1);
		$1->bro = $3;
	}
	| Fact	{	$$ = $1;	}
	;

Fact: //이상없음
	Var {	$$=$1;	}
	| TNUMBER {
		$$=makeNode("NUMBER", NULL, NULL);
		$$->value.dv = $1;
	}
	| FuncCall	{	$$=$1;	}
	| TMINUS Fact {
		$$=makeNode("NEG", NULL, $2);
	}
	| TLPAREN Expr TRPAREN {	$$=$2;	}
	;

FuncCall: //이상없음
	Var TLPAREN ParamList TRPAREN {
		$$ = makeNode("FCALL", NULL, $1);
		$1->bro = $3;
	}
	;

ParamList: //이상없음
	ExprList	{ $$=$1; }
	| { $$=NULL; }
	;
	
ExprList: //이상없음
	ExprList TCOMMA Expr {
		$$ = $1;
		Node* temp = $1;
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = $3;
	}
	| Expr	{ $$=$1; }
	;
	
Stmt: //Stmt부분 이상없음
	AsgnStmt	{	$$=$1;	}
	| IfStmt	{	$$=$1;	}
	| WhileStmt	{	$$=$1;	}
	| ForStmt	{	$$=$1;	}
	| CallStmt	{	$$=$1;	}
	| RtrnStmt	{	$$=$1;	}
	| CompStmt	{	$$=$1;	}
	;

AsgnStmt:
	Var TEQUAL Expr {
		$$ = makeNode("ASSIGN", NULL, $1);
		$1->bro = $3;
	}
	;
	
IfStmt:
	TIF TLPAREN Cond TRPAREN TTHEN Stmt {
		$$ = makeNode("IF", NULL, $3);
		$3->bro = $6;
	}
	| TIF TLPAREN Cond TRPAREN TTHEN Stmt TELSE Stmt {
		$$ = makeNode("IF", NULL, $3);
		$3->bro = $6;
		$6->bro = $8;
	}
	;
	
WhileStmt:
	TWHILE TLPAREN Cond TRPAREN Stmt {
		$$ = makeNode("WHILE", NULL, $3);
		$3->bro = $5;
	}
	;
	
ForStmt: 
	TFOR TLPAREN Var TEQUAL Expr TTO Expr TRPAREN Stmt {
		$$ = makeNode("FOR", NULL, $3);
		$3->bro = $5;
		$5->bro = $7;
		$7->bro = $9;
	}
	;

CallStmt: 
	TCALL Var TLPAREN ParamList TRPAREN {
		$$ = makeNode("PCALL", NULL, $2);
		$2->bro = $4;
	}
	;

RtrnStmt:
	TRETURN TLPAREN Expr TRPAREN {
		$$ = makeNode("RETURN", NULL, $3);
	}
	;
	
CompStmt: 
	TBEGIN StmtList TEND {
		$$ = makeNode("COMP", NULL, $2);
	}
	;
	
StmtList:
	StmtList TSEMI Stmt {
		$$ = $1;
		Node* temp = $1;
		while(temp->bro != NULL) { temp=temp->bro; }
		temp->bro = $3;
	}
	| Stmt { $$ = $1; }
	;

%%

void yyerror(const char *s) {
    fprintf(stderr, "syntax error\n");
}

void traverse(Node *nodeP, int depth) {
    if (nodeP == NULL) {
        return;
    }
    
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    
    // 현재 노드 정보 출력
    printf("%s\n", nodeP->kind);
    
    // 자식 노드를 방문
    traverse(nodeP->son, depth + 1);
    
    // 형제 노드를 방문
    traverse(nodeP->bro, depth);
}

// 메인 함수
int main() {
    if (yyparse() != 0) {
        fprintf(stderr, "Parsing failed\n");
        return 1; // 오류 발생 시 종료
    }
    
    if (rootNode == NULL) {
        fprintf(stderr, "Error: rootNode is NULL\n");
        return 1; // rootNode가 NULL인 경우 오류 처리
    }
    
    traverse(rootNode, 0);
    return 0;
}

