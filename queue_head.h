#ifndef queue_head_H
#define queue_head_H

#include "huff_head.h"

/*List of Modul */

/**** Konstruktor/Kreator List Kosong ****/
void Create_List(ListQueue *L);

Qaddres Create_Node(TNode *dummy);

void Insrt_Node(ListQueue *L, TNode *dummy);

#endif
