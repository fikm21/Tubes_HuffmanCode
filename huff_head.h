#ifndef huff_head_H
#define huff_head_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*Struktur Data */
typedef char infotype;
typedef int frequnce;
typedef struct TbTree *Taddres;
typedef struct QueueNode *Qaddres;
typedef struct TbTree{
	frequnce freq;
	infotype info;
	Taddres LSon;
	Taddres RSon;
	Taddres parent;
}TNode;

typedef struct{
	Taddres root;
}Tree;

typedef struct QueueNode {
	Taddres treenode;
	Qaddres next;
	Qaddres prev;
}QNode;

typedef struct 
{
	Qaddres front;
	Qaddres rear;
	int size;
}ListQueue;

typedef struct{
	infotype temp[100];
	frequnce freq[100];
}Hasil;

typedef struct{
	infotype info;
	infotype value[255];
}encoding;

/*List of Modul */

void Proces_Input(char kalimat[100], ListQueue *L);

char* input_tekss();

char* read_file(char *input_file);

Taddres Build_Huffman(ListQueue *L);

void PrintHuffman(Taddres node, char result[], int n, encoding tamp[],int x);

void PrintHuffmanHelper(Taddres root,int max_tree);



#endif
