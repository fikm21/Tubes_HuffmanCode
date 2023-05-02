#include "huff_head.h"
#include "queue_head.h"
#include "tree_head.h"

void proces_input(char kalimat[100], ListQueue *L){
//	ListQueue list;
//	
//	Create_List(&list);
	
	int freq[26] = {0};
    int i;
    for (i = 0; kalimat[i] != '\0'; i++) {
        char c = tolower(kalimat[i]); //NAH INI TEH BUAT HURUF KECIL DI CEK DARI A SAMPAI Z TERNYATA NANYA KE GPT BISA GUYS DETEKSI GITU BERAPA JUMLAH HURUF A-Z ITU KALO ADA YA MASUKIN
        if (c >= 'a' && c <= 'z') {
            freq[c - 'a']++;
        }else if (kalimat[i] >= 'A' && kalimat[i] <= 'Z') //KALO INI BUAT HURUF BESAR 
		 {
            freq[kalimat[i] - 'A']++;
        }
    }
    
    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            char info = i + 'a';         
            Insrt_Node(&(*L),freq[i],info);
        } 
    }
    
    //Print_Queue(*L);
}

char* input_teks(){
	char* input = (char*) malloc(100 * sizeof(char));
	printf("\t  Masukkan Text	: ");		
	scanf("%[^\n]s",input);fflush(stdin);
	return input;
}

char* read_file(char* input_file) {
    char* text = (char*) malloc(100 * sizeof(char));
    FILE *file;
    file = fopen(input_file, "r");

    if (file == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }
	fscanf(file, "%s", text);
//    printf("\n\tIsi file %s:\n", input_file);
//    printf("\t--------------------\n");
//
//    while ( == 1) {
//        printf("\t%s ", teks);
//    }
//
//    printf("\n\t---------------------\n");
	return text;
    fclose(file);
}

Taddres Build_Huffman(ListQueue *L){
	Taddres root;
	Taddres n1;
	Taddres n2;
	
	while (L->size > 1)
	{
		// Get first smallest node  
		n1 = peek(*L);
		//Remove a front element
		Deque(&(*L));
		// Get second smallest node
		n2 = peek(*L);
		// Remove a front element
		Deque(&(*L));
		// Make new node using two smallest node
		//root =  newTreeNode(n1->freq + n2->freq, ' ');
		// Add new node into priority queue 
		Insrt_Node(&(*L),n1->freq + n2->freq,' ');
		// Set left and right child
		root->LSon = n1;
		root->RSon = n2;
	}
	return root;
}
