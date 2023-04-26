#ifndef huff_head_H
#define huff_head_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Hasil{
	infotype temp[100];
	frequnce freq[100];
};

struct encoding{
	infotype info;
	infotype value[255];
};

/*List of Modul */



#endif
