#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gencode.h"

//proc/func 레이블을 저장하기위한 설정
// 구조체 정의
typedef struct {
    char* label;  // 레이블 이름
    Node* node;   // 해당 레이블의 노드
} LabelNode;
LabelNode* labelNode;
int label_count = 0;

//레이블 생성
void create_labels(Node* nodeP) {
    //총 proc/func 개수 확인
    Node* temp = nodeP;
    while (temp != NULL) {
        label_count++;
        temp = temp->bro;
    }

    labelNode = malloc(label_count * sizeof(labelNode));
    if (labelNode == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }

    // 각 레이블 이름 생성
    temp = nodeP;
    for (int i = 0; i < label_count; i++) {
        labelNode[i].label = malloc(20 * sizeof(char)); //proc/func의 최대길이는 20
        if (labelNode[i].label == NULL) {
            fprintf(stderr, "메모리 할당 실패\n");
            exit(1);
        }
        sprintf(labelNode[i].label, "%s", temp->son->value.sv); // Proc/Func 이름으로 레이블 생성
        labelNode[i].node = temp;

        temp = temp->bro;
    }
}

//레이블에 대한 동적메모리 반환
void free_labels() {
    for (int i = 0; i < label_count; i++) {
        free(labelNode[i].node);
    }
    free(labelNode);
    label_count = 0;
}

//이름에 맞는 node 반환
Node* find_node_by_label(const char* label) {
    for (int i = 0; i < label_count; i++) {
        if (strcmp(labelNode[i].label, label) == 0) {
            return labelNode[i].node;
        }
    }
    return NULL;
}

//func&proc의 파리미터 개수 확인
int count_param_fp(Node* nodeP){
    int count = 0;
    //proc일때
    if(strcmp(nodeP->kind, "PROC") == 0){
        Node* paramNode = nodeP->son->bro;
        Node* nameNode;
        if(paramNode == NULL) return count;
        while(paramNode != NULL && strcmp(paramNode->kind, "DECL")==0){
            nameNode = paramNode->son;
            while(nameNode != NULL && strcmp(nameNode->kind, "NAME") == 0){
                count++;
                nameNode = nameNode->bro;
            }
            paramNode = paramNode->bro;
        }
    }
    //func일때
    else if(strcmp(nodeP->kind, "FUNC") == 0){
        Node* paramNode = nodeP->son->bro->bro;
        Node* nameNode;
        if(paramNode == NULL) return count;
        while(paramNode != NULL && strcmp(paramNode->kind, "DECL")==0){
            nameNode = paramNode->son;
            while(nameNode != NULL && strcmp(nameNode->kind, "NAME") == 0){
                count++;
                nameNode = nameNode->bro;
            }
            paramNode = paramNode->bro;
        }
    }
    return count;
}

//func&proc의 지역변수 개수 확인
int count_vardecl_fp(Node* nodeP){
    int count = 0;
    //proc일때
    if(strcmp(nodeP->kind, "PROC") == 0){
        Node* varNode = nodeP->son;
        Node* nameNode;
        while(strcmp(varNode->kind, "VARDECL")!=0) varNode = varNode->bro;
        varNode = varNode->son;
        if(varNode == NULL) return count;
        while(varNode != NULL){
            nameNode = varNode->son;
            while(nameNode != NULL && strcmp(nameNode->kind, "NAME") == 0){
                count++;
                nameNode = nameNode->bro;
            }
            varNode = varNode->bro;
        }
    }
    //func일때
    else if(strcmp(nodeP->kind, "FUNC") == 0){
        Node* varNode = nodeP->son;
        Node* nameNode;
        while(strcmp(varNode->kind, "VARDECL")!=0) varNode = varNode->bro;
        varNode = varNode->son;
        if(varNode == NULL) return count;
        while(varNode != NULL){
            nameNode = varNode->son;
            while(nameNode != NULL && strcmp(nameNode->kind, "NAME") == 0){
                count++;
                nameNode = nameNode->bro;
            }
            varNode = varNode->bro;
        }
    }
    return count;
}

//code함수
void code(Node* nodeP){
    if(nodeP == NULL) return;

    //COMP는 son으로 이동해주기.
    if(strcmp(nodeP->kind, "COMP") == 0){
        code(nodeP->son);
    }
    //ASSIGN
    else if(strcmp(nodeP->kind, "ASSIGN") == 0){
        codeL(nodeP->son);
        printf("; ");
        codeR(nodeP->son->bro);
        printf("; ");
        printf("sto\n");
    }
    //IF
    else if(strcmp(nodeP->kind, "IF") == 0){
        static int if_count = 0;
        int label1 = if_count++;

        //if-then
        if(nodeP->son->bro->bro == NULL){
            codeR(nodeP->son);
            printf("; fjp l%d; ", label1);
            code(nodeP->son->bro);
            printf("; l%d:\n", label1);
        }
        //if-then-else
        else{
            int label2 = if_count++;
            //st1과 st2를 구분하기 위해, st1을 복사, bro만 제거하여 code 실행
            Node temp = *nodeP->son->bro;
            temp.bro = NULL;

            codeR(nodeP->son);
            printf("; fjp l%d; ", label1);
            code(&temp);
            printf("; ujp l%d; l%d:", label2, label1);
            code(nodeP->son->bro->bro);
            printf("; l%d:\n", label1);
        }

    }
    //WHILE
    else if(strcmp(nodeP->kind, "WHILE") == 0){
        printf("l1: ");
        codeR(nodeP->son);
        printf("; fjp l2; ");
        code(nodeP->son->bro);
        printf("; ujp l1; l2:\n"); 

    }
    //FOR
    else if(strcmp(nodeP->kind, "FOR") == 0){
        //x=e1
        Node* Assign = makeNode("ASSIGN", NULL, nodeP->son);
        Assign->son->bro = nodeP->son->bro;
        //x<=e2
        Node* Le = makeNode("LE", NULL, nodeP->son);
        Le->son->bro = nodeP->son->bro->bro;
        //x=x+1
        Node* Plus = makeNode("ASSIGN", NULL, makeNode("NAME", NULL, NULL));
        Plus->son->value.sv = strdup(nodeP->son->value.sv);
        Plus->son->bro = makeNode("PLUS", NULL, makeNode("NAME", NULL, NULL));
        Plus->son->bro->son->value.sv = strdup(nodeP->son->value.sv);
        Plus->son->bro->son->bro = makeNode("NUMBER", NULL, NULL);
        Plus->son->bro->son->bro->value.dv = 1;

        code(Assign);
        printf("; l1: ");
        codeR(Le);
        printf("; fjp l2; ");
        code(nodeP->son->bro->bro);
        printf("; ");
        code(Plus);
        printf("; ujp ;1; l2:\n");

        // 메모리 해제
        free(Plus->son->bro->son->bro);
        free(Plus->son->bro->son->value.sv);
        free(Plus->son->bro->son);
        free(Plus->son->bro);
        free(Plus->son->value.sv);
        free(Plus);
        free(Le);
        free(Assign);
    }
    //FCALL
    else if(strcmp(nodeP->kind, "FCALL") == 0){
        printf("mst; ");
        int count = 0;
        Node* paramNode = nodeP->son->bro;
        while(paramNode != NULL){
            count++;
            codeR(paramNode);
            printf("; ");
            paramNode = paramNode->bro;
        }
        Node* temp = find_node_by_label(nodeP->son->value.sv);
        if(temp == NULL) printf("cup %d Lerror", count);
        else printf("cup %d L%s \n", count,nodeP->son->value.sv);

        int p = count_param_fp(temp);
        int v = count_vardecl_fp(temp);
        printf("L%s : ssp %d + %d + 2; ", nodeP->son->value.sv, p, v);
        Node* body = temp->son;
        while(strcmp(body->kind, "COMP")!=0) body = body->bro;
        code(body);        
        printf("; retf\n");
    }
    //PCALL
    else if(strcmp(nodeP->kind, "PCALL") == 0){
        printf("mst; ");
        int count = 0;
        Node* paramNode = nodeP->son->bro;
        while(paramNode != NULL){
            count++;
            codeR(paramNode);
            printf("; ");
            paramNode = paramNode->bro;
        }
        Node* temp = find_node_by_label(nodeP->son->value.sv);
        if(temp == NULL) printf("cup %d Lerror", count);
        else printf("cup %d L%s \n", count,nodeP->son->value.sv);
        int p = count_param_fp(temp);
        int v = count_vardecl_fp(temp);
        printf("L%s : ssp %d + %d + 2; ", nodeP->son->value.sv, p, v);
        Node* body = temp->son;
        while(strcmp(body->kind, "COMP")!=0) body = body->bro;
        code(body);
        printf("; retp\n");
    }
    //RETURN
    else if(strcmp(nodeP->kind, "RETURN") == 0){
        codeR(nodeP->son);
        printf("; str0; retf");
    }
    //MAIN(여기서는 노드명이 PROGRAM임)
    else if(strcmp(nodeP->kind, "PROGRAM") == 0){
        //맨처음 받으면, proc/func에 대한 레이블부터 생성함
        if(nodeP->bro != NULL){
            create_labels(nodeP->bro);
        }

        Node* varNode = nodeP->son;
        Node* nameNode;
        int count = 0;
        varNode = varNode->son;
        while(varNode != NULL){
            nameNode = varNode->son;
            while(nameNode != NULL && strcmp(nameNode->kind, "NAME") == 0){
                count++;
                nameNode = nameNode->bro;
            }
            varNode = varNode->bro;
        }
        printf("ssp %d+2; ", count);
        code(nodeP->son->bro);
        printf("; stp\n");

        free_labels();
    }

    code(nodeP->bro);
}

//codeL 함수
void codeL(Node* nodeP){
    if(nodeP == NULL) return;

    //아직은 codeL에는 변수만 옴-> NAME만 고려
    if(strcmp(nodeP->kind, "NAME") == 0){
        printf("ldc p(%s)", nodeP->value.sv);
    }
}

//codeR 함수
void codeR(Node* nodeP){
    if(nodeP == NULL) return;

    //상수
    if(strcmp(nodeP->kind, "NUMBER") == 0){
        printf("ldc %d", (int)nodeP->value.dv);
    }
    //변수
    else if(strcmp(nodeP->kind, "NAME") == 0){
        codeL(nodeP);
        printf("; ind");
    }
    //PLUS
    else if(strcmp(nodeP->kind, "PLUS") == 0){
        codeR(nodeP->son);        //왼쪽(e1)
        printf("; ");
        codeR(nodeP->son->bro);  //오른쪽(e2)
        printf("; add");
    }
    //MINUS
    else if(strcmp(nodeP->kind, "MINUS") == 0){
        codeR(nodeP->son);        //왼쪽(e1)
        printf("; ");
        codeR(nodeP->son->bro);  //오른쪽(e2)
        printf("; sub");
    }
    //TIMES
    else if(strcmp(nodeP->kind, "TIMES") == 0){
        codeR(nodeP->son);        //왼쪽(e1)
        printf("; ");
        codeR(nodeP->son->bro);  //오른쪽(e2)
        printf("; mul");
    }
    //DIVIDE
    else if(strcmp(nodeP->kind, "DIVIDE") == 0){
        codeR(nodeP->son);        //왼쪽(e1)
        printf("; ");
        codeR(nodeP->son->bro);  //오른쪽(e2)
        printf("; div");
    }
    //NEG
    else if(strcmp(nodeP->kind, "NEG") == 0){
        codeR(nodeP->son);
        printf("; neg");
    }
    //비교연산 부분
    else if(strcmp(nodeP->kind, "EQ") == 0){
        codeR(nodeP->son);
        printf("; ");
        codeR(nodeP->son->bro);
        printf("; equ");
    } else if(strcmp(nodeP->kind, "NE") == 0){
        codeR(nodeP->son);
        printf("; ");
        codeR(nodeP->son->bro);
        printf("; neq");
    } else if(strcmp(nodeP->kind, "GT") == 0){
        codeR(nodeP->son);
        printf("; ");
        codeR(nodeP->son->bro);
        printf("; grt");
    } else if(strcmp(nodeP->kind, "GE") == 0){
        codeR(nodeP->son);
        printf("; geq");
        codeR(nodeP->son->bro);
        printf("; ");
    } else if(strcmp(nodeP->kind, "LT") == 0){
        codeR(nodeP->son);
        printf("; ");
        codeR(nodeP->son->bro);
        printf("; les");
    } else if(strcmp(nodeP->kind, "LE") == 0){
        codeR(nodeP->son);
        printf("; ");
        codeR(nodeP->son->bro);
        printf("; leq");
    }
    //그게 아니면 code함수로 실행
    else{
        code(nodeP);
    }
}