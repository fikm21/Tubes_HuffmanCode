#include "tree_head.h"

void Create_Tree(Tree *T){
	T->root = NULL;
}

Taddres Create_TNode(frequnce freq, infotype item){
	Taddres newNode = (Taddres) malloc(sizeof(TNode));
    if (newNode == NULL) {
        printf("Error: Alokasi memori gagal");
        return NULL;
    }
    newNode->LSon = NULL;
    newNode->RSon = NULL;
    newNode->freq = freq;
    newNode->info = item;
    return (newNode);

}
