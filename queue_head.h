#ifndef queue_head_H
#define queue_head_H

#include "huff_head.h"

/*List of Modul */

/**** Konstruktor/Kreator List Kosong ****/
void Create_List(ListQueue *L);

Qaddres Create_Node(Taddres dummy);

void Insrt_Node(ListQueue *L, frequnce freq, infotype info);

void Print_Queue(ListQueue L);

#endif
