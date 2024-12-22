#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

//toypl.y에서 추상구문 트리를 만들기 위해 사용되는 추가 파일
Node* makeNode(char * kind, Node* bro, Node* son) {
	Node * temp;

	temp = (Node*)malloc(sizeof(Node));
	strcpy(temp->kind, kind);
	temp->bro = bro;
	temp->son = son;

	return temp;
}

