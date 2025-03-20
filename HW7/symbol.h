#ifndef SYMBOL_H
#define SYMBOL_H

#define MAXNAMELEN 200
#define NSYMS 100 //최대 심볼 개수 정의

typedef enum {UNKOWN, INT, LONG, PNAME, FNAME, MNAME, ETC} typeKind;

typedef struct symbolTable {
    char name[MAXNAMELEN];
    typeKind type;
    int addr;
} symtab;

symtab *mkSymbolTable();

symtab *symlook(char *s){
    symtab *sp;
    for(sp=symtab; sp < &symtab[NSYMS]; sp++){
        /*is it already here ? */
        if(sp->name && !strcmp(sp->name, s)) return sp;
        /*is it free ? */
        if (!sp->name) {
            sp->name=strdup(s);
            return sp;
        }
        /* otherwise continue to next */
    }
    yyerror("Too many symbols");
    exit(1);
};



#endif