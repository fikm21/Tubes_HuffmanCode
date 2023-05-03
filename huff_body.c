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
	fscanf(file, "%[^\n]s", text);
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
        // Remove a front element
        Deque(&(*L));
        // Get second smallest node
        n2 = peek(*L);
        // Remove a front element
        Deque(&(*L));
        // Make new node using two smallest node
        root = Create_TNode(n1->freq + n2->freq, ' ');
        // Set left and right child
        root->LSon = n1;
        root->RSon = n2;
        // Add new node into priority queue 
        enque(&(*L),root); 
		//Insrt_Node(&(*L), root->freq, root->info);
    }
    return root;
}



// Display Huffman code

void PrintHuffman(Taddres node, char result[], int n, encoding tamp[],int x)
{
    if (node == NULL)
    {
        return;
    }
    if (node->LSon == NULL && node->RSon == NULL)
    {
        result[n] = '\0';
        tamp[x].info = node->info;
        strcpy(tamp[x].value,result);
        printf("\n\t %c = %s", node->info, result);
        x += 1;
        return;
    }
    result[n] = '0';
    PrintHuffman(node->LSon, result, n + 1, tamp, x);
    result[n] = '1';
    PrintHuffman(node->RSon, result, n + 1, tamp, x);
}


void PrintHuffmanHelper(Taddres root,int max_tree){
	
	
    char result[max_tree]; // inisialisasi array result
    encoding tamp[max_tree]; // inisialisasi array tamp
    int n = 0, x = 0; // inisialisasi variabel n dan x

    PrintHuffman(root, result, n, tamp, x); // panggil fungsi rekursif helper

}

void PrintTree(Taddres root, int level) {
    if (root == NULL) {
        return;
    }
    PrintTree(root->RSon, level + 1);
    int i;
    for ( i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%c:%d\n", root->info, root->freq);
    PrintTree(root->LSon, level + 1);
}


