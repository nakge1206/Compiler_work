a%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
Node *rootNode; // 구문 트리의 루트 노드
%}

%start Program

%union {
    double dval; // 숫자 값
    char *sval;  // 이름 값
    struct _node * nodeP;
}

%token <dval> NUMBER
%token <sval> NAME
%token TASS TAND TOR TNOT TLT TLE TGT TGE TNE TPLUS TMINUS TMUL TDIV
%token TPROGRAM TPROC TRETURNS TINT TIF TELSE TFOR TCALL TBEGIN TMAIN
%token TFUNC TVAR TLONG TTHEN TWHILE TTO TRETURN TEND
%token TWORD TNUMBER
%token ERROR

%type <nodeP> Program
%type <nodeP> VarDecl
%type <nodeP> DclList
%type <nodeP> Decl
%type <nodeP> VarList
%type <nodeP> Type
%type <nodeP> Stmt
%type <nodeP> AsgnStmt
%type <nodeP> IfStmt
%type <nodeP> WhileStmt
%type <nodeP> ForStmt
%type <nodeP> CallStmt
%type <nodeP> RtrnStmt
%type <nodeP> CompStmt
%type <nodeP> StmtList
%type <nodeP> Cond 
%type <nodeP> Rel
%type <nodeP> Expr
%type <nodeP> Term
%type <nodeP> Fact
%type <nodeP> FuncCall
%type <nodeP> ParamList
%type <nodeP> ExprList
%type <nodeP> Var
%type <nodeP> SubPgmList
%type <nodeP> SubPgm
%type <nodeP> ProcDecl
%type <nodeP> FuncDecl
%type <nodeP> FormParam


%%

Program : TPROGRAM NAME ';' SubPgmList TMAIN VarDecl CompStmt '.' {
    rootNode = makeNode("PROGRAM", NULL, $4);
    $4 -> bro = $6;
    $6 -> bro = $7;
}
;

VarDecl : TVAR DclList ';' {
    $$ = makeNode("VARDECL", NULL, $2);
}
| 
{
    $$ = NULL;
}
;

DclList : DclList ';' Decl {
    $$ = makeNode("DCLLIST", NULL, $1);
    $1 -> bro = $3;
}
| Decl {
    $$ = $1;
}
;

Decl : VarList ':' Type {
    $$ = makeNode("DECL", NULL, $1);
    $1 -> bro = $3;
}
;

VarList : VarList ',' Var {
    $$ = makeNode("VARLIST", NULL, $1);
    $1 -> bro = $3;
}
| Var {
    $$ = $1;
}
;

Type : TINT {
    $$ = makeNode("TINT", NULL, NULL);
}
| TLONG {
    $$ = makeNode("TLONG", NULL, NULL);
}
;

Stmt : AsgnStmt 
     | IfStmt
     | WhileStmt 
     | ForStmt
     | CallStmt 
     | RtrnStmt
     | CompStmt 
     ;

AsgnStmt : Var TASS Expr {
    $$ = makeNode("ASSIGN", NULL, $1);
    $1 -> bro = $3;
}
;

IfStmt : TIF '(' Cond ')' TTHEN Stmt {
    $$ = makeNode("IF", NULL, $3);
    $3 -> bro = $6;
}
| TIF '(' Cond ')' TTHEN Stmt TELSE Stmt {
    $$ = makeNode("IF_ELSE", NULL, $3);
    $3 -> bro = $6;
    $6 -> bro = $8; 
}
;

WhileStmt : TWHILE '(' Cond ')' Stmt {
    $$ = makeNode("WHILE", NULL, $3);
    $3 -> bro = $5;
}
;

ForStmt : TFOR '(' Var TASS Expr TTO Expr ')' Stmt {
    $$ = makeNode("FOR", NULL, $3);
    $3 -> bro = $5;
    $5 -> bro = $7;
    $7 -> bro = $9;
}
;

CallStmt : TCALL Var '(' ParamList ')' {
    $$ = makeNode("CALL", NULL, $2);
    $2 -> bro = $4;
}
;

RtrnStmt : TRETURN '(' Expr ')' {
    $$ = makeNode("RETURN", NULL, $3);
}
;

CompStmt : TBEGIN StmtList TEND {
    $$ = makeNode("COMP_STMT", NULL, $2);
}
;

StmtList : StmtList ';' Stmt {
    $$ = makeNode("STMTLIST", NULL, $1);
    $1 -> bro = $3;
}
| Stmt {
    $$ = $1;
}
;

Cond : Cond TAND Rel {
    $$ = makeNode("AND", NULL, $1);
    $1 -> bro = $3;
}
| Cond TOR Rel {
    $$ = makeNode("OR", NULL, $1);
    $1 -> bro = $3;
}
| TNOT Rel {
    $$ = makeNode("NOT", NULL, $2);
}
| Rel {
    $$ = $1;
}
;

Rel : Expr TLT Expr {
    $$ = makeNode("LT", NULL, $1);
    $1 -> bro = $3;
}
| Expr TLE Expr {
    $$ = makeNode("LE", NULL, $1);
    $1 -> bro = $3;
}
| Expr TGT Expr {
    $$ = makeNode("GT", NULL, $1);
    $1 -> bro = $3;
}
| Expr TGE Expr {
    $$ = makeNode("GE", NULL, $1);
    $1 -> bro = $3;
}
| Expr TASS Expr {
    $$ = makeNode("ASSIGN", NULL, $1);
    $1 -> bro = $3;
}
| Expr TNE Expr {
    $$ = makeNode("NE", NULL, $1);
    $1 -> bro = $3;
}
;

Expr : Expr TPLUS Term {
    $$ = makeNode("PLUS", NULL, $1);
    $1 -> bro = $3;
}
| Expr TMINUS Term {
    $$ = makeNode("MINUS", NULL, $1);
    $1 -> bro = $3;
}
| Term {
    $$ = $1;
}
;

Term : Term TMUL Fact {
    $$ = makeNode("MUL", NULL, $1);
    $1 -> bro = $3;
}
| Term TDIV Fact {
    $$ = makeNode("DIV", NULL, $1);
    $1 -> bro = $3;
}
| Fact {
    $$ = $1;
}
;

Fact : Var {
    $$ = makeNode("VAR", NULL, NULL);
}
| NUMBER {
    $$ = makeNode("NUMBER", NULL, NULL);
}
| FuncCall {
    $$ = $1;
}
| TMINUS Fact {
    $$ = makeNode("NEG", NULL, $2);
}
| '(' Expr ')' {
    $$ = $2;
}
;

FuncCall : Var '(' ParamList ')' {
    $$ = makeNode("FUNC_CALL", NULL, $1);
    $1 -> bro = $3;
}
;

ParamList : ExprList {
    $$ = $1;
}
| {
    $$ = NULL;
}
;

ExprList : ExprList ',' Expr {
    $$ = makeNode("EXPRLIST", NULL, $1);
    $1 -> bro = $3;
}
| Expr {
    $$ = $1;
}
;

Var : NAME { $$ = makeNode("NAME", NULL, NULL);}
    ;

// 서브 프로그램 리스트
SubPgmList : SubPgmList SubPgm {
    $$ = makeNode("SUBPGLIST", $1, $2);
}
| {
    $$ = NULL;
}
;

// 서브 프로그램
SubPgm : ProcDecl {
    $$ = $1;
}
| FuncDecl {
    $$ = $1;
}
;

// 프로시저 선언
ProcDecl : TPROC Var '(' FormParam ')' VarDecl CompStmt {
    $$ = makeNode("PROCDECL", NULL, $2);
    $2 -> bro = $4;
    $4 -> bro = $6;
    $6 -> bro = $7;
}
;

// 함수 선언
FuncDecl : TFUNC Var '(' FormParam ')' TRETURNS '(' Type ')' {
    $$ = makeNode("PROCDECL", NULL, $2);
    $2 -> bro = $4;
    $4 -> bro = $8;
}
;

// 형식 매개변수
FormParam : DclList {
    $$ = $1;
}
| {
    $$ = NULL;
}
;
%%

void yyerror() {
   printf("Syntax error\n");
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
