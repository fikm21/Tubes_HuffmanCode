
#include "huff_head.h"
#include "queue_head.h"
#include "tree_head.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int pil;
	ListQueue list;
	
	Create_List(&list);
	
	do{		
		system("cls");
		printf("\n");
		printf("\t		Huffman Code 		\n");
		printf("\t\n");
		printf("\t 1. Input\n");
		printf("\t 2. Show Queue\n");
		printf("\t 3. Show HuffmanCode\n");
		printf("\t 4. Export\n");
		printf("\t 5. Keluar Program\n");
		printf("\t\n");
		
		printf("\t  Masukkan Pilihan	: ");		
		scanf("%d",&pil);fflush(stdin);
		
		switch(pil){
			case 1:{
				int pil_menu;
				do{
					system("cls");
					printf("\n");
					printf("\t 1. Input Text\n");
					printf("\t 2. Input File\n");
					printf("\t 3. Kembali\n");
					printf("\t  Masukkan Pilihan	: ");
					scanf("%d",&pil_menu);fflush(stdin);	
					switch(pil_menu){
						case 1:{
							char* input = input_teks() ;
//							
//							printf("\t  Masukkan Text	: ");		
//							scanf("%[^\n]s",&input);fflush(stdin);	
							
							proces_input(input,&list);
							
							free(input);
							pil_menu = 3;
							break;
						}
						case 2:{
							char input_file[100];
							char* text;
							
							printf("\t  Masukkan Nama File	: ");		
							scanf("%s",&input_file);fflush(stdin);
							
							text = read_file(input_file);
							
							printf("Press any key to continue...");
							getchar();
							
							proces_input(text,&list);
							free(text);
							
							pil_menu = 3;
							break;
						}case 3:{
							break;
						}default :{
							printf("\tPilihan Salah");
							break;
						}
					}			
				}while(pil_menu != 3);
				
				break;
			}
			case 2:{
				
				Print_Queue(list);
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				
				break;
			}
			case 5:{
				
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
