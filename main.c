
#include "huff_head.h"
#include "queue_head.h"
#include "tree_head.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int pil;
	int max_tree,max_char;
	int n = 0, x = 0;
	ListQueue list,listTemp;
	//encoding encode[255];
	Create_List(&list);
	Create_List(&listTemp);
	Taddres root;
	char* input_text;
	char* hasil_encode = NULL;
	
	do{		
		system("cls");
		printf("\n");
		printf("\t		Huffman Code 		\n");
		printf("\t\n");
		printf("\t 1. Input\n");
		printf("\t 2. Show Queue\n");
		printf("\t 3. Show Tree & Huffman\n");
		printf("\t 4. Encode & Decode\n");
		printf("\t 5. Export to File\n");
		printf("\t 6. Exit Program\n");
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
							input_text = input_teks() ;
							max_char = strlen(input_text);

							printf("Press any key to continue...");
							getchar();
							proces_input(input_text,&list);
							
							pil_menu = 3;
							break;
						}
						case 2:{
							char input_file[100];
							
							printf("\t  Masukkan Nama File	: ");		
							scanf("%s",&input_file);fflush(stdin);
							
							input_text = read_file(input_file);

							printf("Press any key to continue...");
							getchar();
							max_char = strlen(input_text);
							proces_input(input_text,&list);
							
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
				root = Build_Huffman(&list);
				max_tree = ceil(log2(max_char));
				break;
			}
			case 2:{
				proces_input(input_text,&listTemp);
				Print_Queue(listTemp);
				Create_List(&listTemp);
				break;
			}
			case 3:{
	
				printf("\n\n\t Tree Huffman Code\n");
				
				// Contoh tree Huffman sederhana dengan 3 node

			    if(root == NULL){
			    	printf("root kosong");
				}else{
					PrintTree(root, 0);
				}
				
				printf("\n\n\t Huffman Code\n");
				char result[max_tree]; // inisialisasi array result
			    encoding tamp[max_tree]; // inisialisasi array tamp
			    
			
			    PrintHuffman(root, result, n, tamp, x); // panggil fungsi rekursif helper
				printf("\nPress any key to continue...");
				getchar();
				break;
			}
			case 4:{
				char result[max_tree]; // inisialisasi array result
			    encoding code[max_tree]; // inisialisasi array tamp
				char temp[max_tree];
				int i;
				printf("\n\n\t Huffman Code\n");
			
			    PrintHuffman(root, result, n, code, x); // panggil fungsi rekursif helper
				//printf("text : %s",input_text);
				printf("\n\n\t Encode String \n\t ");
				
				for( i=0;i<max_char;i++){
					encode(root,result,0,input_text, i, temp,&hasil_encode);
					printf("%s" ,hasil_encode);
				}
				
				
				
				printf("\n\n\t Decode to String \n\t ");	
				decode(root,0,temp, input_text);
				printf("\nPress any key to continue...");
				getchar();
				break;
			}
			case 5:{
				compress_file(root,input_text, max_char, max_tree);
				printf("\nSuccses to Export \nPress any key to continue...");
				getchar();


				break;
			}
			case 6:{
				break;
			}
			default:{
				printf("\tPilihan Salah");
				break;
			}
			
		}
	}while(pil != 6);
	return 0;
}
