#include <stdio.h>
#include <stdlib.h>
#include "huff_head.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
		int pil;
		do{		
		system("cls");
		printf("\n");
		printf("\t		Huffman Code 		\n");
		printf("\t\n");
		printf("\t 1. Input Teks\n");
		printf("\t 2. Input File\n");
		printf("\t 3. Keluar Program\n");
		printf("\t\n");
		
		printf("\t  Masukkan Pilihan	: ");		
		scanf("%d",&pil);fflush(stdin);
		
		switch(pil){
			case 1:{
				char input[100];
				
				printf("\t  Masukkan Text	: ");		
				scanf("%s",&input);fflush(stdin);
				break;
			}
			case 2:{
				char input_file[100];
				
				printf("\t  Masukkan Nama File	: ");		
				scanf("%s",&input_file);fflush(stdin);
				break;
			}
			case 3:{
				
				break;
			}
			default:{
				printf("\tPilihan Salah");
				getch();
				break;
			}
			
		}
	}while(pil != 3);
	return 0;
}
