
#include "huff_head.h"
#include "queue_head.h"
#include "tree_head.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int pil;
	do{		
		system("cls");
		printf("\n");
		printf("\t		Huffman Code 		\n");
		printf("\t\n");
		printf("\t 1. Input\n");
		printf("\t 2. Make Queue\n");
		printf("\t 3. Show HuffmanCode\n");
		printf("\t 4. Export\n");
		printf("\t 5. Keluar Program\n");
		printf("\t\n");
		
		printf("\t  Masukkan Pilihan	: ");		
		scanf("%d",&pil);fflush(stdin);
		
		switch(pil){
			case 1:{
				do{
					system("cls");
					printf("\n");
					printf("\t 1. Input\n");
					printf("\t 2. Make Queue\n");
					printf("\t 3. Kembali\n");
					printf("\t  Masukkan Pilihan	: ");
					scanf("%d",&pil);fflush(stdin);	
					switch(pil){
						case 1:{
							char input[100];
							
							printf("\t  Masukkan Text	: ");		
							scanf("%[^\n]s",&input);fflush(stdin);	
							break;
						}
						case 2:{
							char input_file[100];
					
							printf("\t  Masukkan Nama File	: ");		
							scanf("%s",&input_file);fflush(stdin);
							break;
						}case 3:{
							break;
						}default :{
							printf("\tPilihan Salah");
							break;
						}
					}			
				}while(pil != 3)
				
				break;
			}
			case 2:{
			
				break;
			}
			case 3:{
				
				break;
			}
			default:{
				printf("\tPilihan Salah");
				break;
			}
			
		}
	}while(pil != 5);
	return 0;
}
