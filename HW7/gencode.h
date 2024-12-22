#ifndef GENCODE_H
#define GENCODE_H

#include "node.h" // Node 구조체 사용
#include <stdio.h> // printf 함수 사용

// 함수 선언
void code(Node* rootNode);
void codeL(Node* nodeP);
void codeR(Node* nodeP);

#endif