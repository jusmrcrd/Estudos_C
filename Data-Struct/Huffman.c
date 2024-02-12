#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 256
#define MAXBITS 50
#define MAXSIZE 250000
struct nodetype{
    unsigned char caracter;
    int freq;
    struct nodetype* left,* right,* next;
};


struct queue{
    struct nodetype* head;
    int tam;
};

typedef struct nodetype NT;
typedef struct queue QT;

void insertqueue();
void  startqueue();
void  makequeue();
void printqueue();
void presstable(unsigned int*);
unsigned int* maketable();
unsigned char* encrypter();
unsigned char** allocmatix();
unsigned char* decrypter();
void makecode();
int sizetree();
NT* buildtree();
NT* removequeue();


// para printar a string usando o dicionario de codigos
unsigned char* encrypter(unsigned char* texto, unsigned char** txt){
  unsigned  char* new = malloc(MAXSIZE+sizeof(char));
    for(int a = 0; a < strlen(texto); a++)
        for(int i = 0; i < TAM; i++)
            if( i   == texto[a])
               strcat(new,txt[i]);
 
        return new;
}

//decriptografa o codigo gerado pelo make encrypter;
unsigned char* decrypter(char* code,NT *root){
    NT* aux = root;
   unsigned char* decode = calloc(strlen(code),sizeof(unsigned char));
    int i = 0;
    char temp[2];
    while(code[i] != '\0'){
        
        if(code[i] == '0')
            aux = aux->left;
        else
            aux = aux->right;
    
        if(aux->left == NULL && aux->right == NULL){
            temp[0] = aux->caracter;
            temp[1] = '\0';
            strcat(decode,temp);
            aux = root;
        }
        i++;
    }

    return decode;
}

//gera a tabela com os determinados codigos
void makecode(unsigned char** table, NT *root,unsigned char *way,int col){
    
    char left[col], right[col];    
    if(root->left == NULL && root->right == NULL)
            strcpy(table[root->caracter],way);
    else{
            strcpy(left,way);
            strcpy(right,way);
            
            strcat(left ,"0");
            strcat(right,"1");

            makecode(table,root->left,left,col);
            makecode(table,root->right,right,col);
        }
}



// contabiliza a profundidade da arvore;
int sizetree(NT* node){
    int left,right;
    if(node == NULL){
        return -1;
    }else{
        left   = sizetree(node->left)    + 1;
        right = sizetree(node->right) + 1;
        if(left > right)
            return  left;
        else
            return right;
    }
}

// com a fila de prioridades ele monta a arvore juntando as duas menores frequencias
NT* buildtree(QT* pq){
 NT* newnod;
 NT*fist,*second;
 while(pq->tam >1){
        newnod = malloc(sizeof(NT));
        
        fist     = removequeue(pq);
        second = removequeue(pq);

        newnod->caracter = '+';
        newnod->freq   = fist->freq + second->freq;
        newnod->left   = fist;
        newnod->right = second;
        newnod->next   = NULL;;
        
        insertqueue(pq,newnod);
    }

    return pq->head;
}

// remove o primeiro item da fila de prioridades
NT* removequeue(QT* pq){
    NT* aux = NULL; 
   if(pq->head){
        aux = pq->head;
        pq->head = aux->next;
        aux->next = NULL;
        pq->tam--;
   }
   return aux;
}

// feito para alocar e colocar a frequencia na queue
void  makequeue(QT* pq, unsigned int* tab){
    NT* newnod;
    for(int i = 0; i < TAM; i++)
        if(tab[i] != 0){
           newnod = malloc(sizeof(NT));
           
           newnod->caracter = i;
            newnod->freq   = tab[i];
            newnod->left   = NULL;
            newnod->right = NULL;
            newnod->next   = NULL; 

            insertqueue(pq,newnod);
        }
}
// insere o a estrutura na queue
void insertqueue(QT* pq, NT* node){
    NT* aux;

    //inserção de lista vazia
    if(pq->head == NULL){
        pq->head = node;
    }
    //inserção de frequencia menor que a frequencia do primeiro
    else if(node->freq < pq->head->freq){
        node->next = pq->head;
        pq->head = node;
    }
    //inserir um item na frequencia no meio da lista
    else{
        aux = pq->head;

        while(aux->next && aux->next->freq <= node->freq)
            aux = aux->next;

        node->next = aux->next;
        aux->next = node;
    }
    pq->tam++;
}

// modo diferente de inicializar uma lista
// e um metodo que inicialica a cabeça da lista em NULL e o numero 0
// para a facilidade da fila de prioridades;
void startqueue(QT* pq){
    pq->head = NULL;
    pq->tam = 0;

}
// função para alocação da matrix 
unsigned char** allocmatrix(int con){
        
    unsigned char** dicionario;

    dicionario = malloc(sizeof(char*)*TAM); 

    for(int i = 0; i < TAM; i++){
        dicionario[i] = calloc(con,sizeof(char));
    }

    return dicionario;
}

// nada de muito novo pega o texto de um char e adiciona em uma tabela
// tabela que representara a tabela ASCII;
unsigned int* maketable( char* txt,unsigned int* tab){ 
    while(*txt != '\0'){
        tab[*txt]++; 
        txt++;
    }
    return tab;
}

// função que le o arquivo ARGV[1]  
int  startprog(unsigned char* p,char* fname){
    FILE *fp;
    int i = 0;

    if((fp= fopen(fname,"rb")) == NULL)return 0;

    do{
        *p = getc(fp);
        p++; i++;

    }while(!feof(fp)&& i < MAXSIZE);

    if(*(p-2) == 0xa1) *(p-2)= '\0';
    else *(p-1) = '\0';

    fclose(fp);
    return 1;
}
//// ERRO ALOCANDO POUCA MEMORIA

int main(int argc,char* argv[]){
    QT list;
    NT* tree;
   char* t_buff;
    char* texto =(char*) malloc(MAXSIZE+sizeof(unsigned char));
    unsigned int* tab_freq = (unsigned int*) calloc(TAM,sizeof(unsigned int)); 
    unsigned int size;
    unsigned char** txt;
    unsigned char* decode;
    unsigned  char* code;
    
  
 if((t_buff =(char*) malloc(MAXSIZE+sizeof(unsigned char)))== NULL)
        printf("erro de alocação");
       

 if(argv[1] == NULL){
        printf("EXECUTE O ARQUIVO: huffman + aquivo");
        exit(1);
 }
    startprog(t_buff,argv[1]);
    
   texto = t_buff; 

    //função para preencher a tabela de frequencias
   tab_freq =  maketable(texto,tab_freq);

    //funções para inicializar a lista;
    startqueue(&list);
    makequeue(&list,tab_freq);

    //montar a arvore; 
    tree = buildtree(&list);
    //encontra a profundidade e aloca a matrix do dicionario;
   size = sizetree(tree)+1;  
   txt = allocmatrix(size);
    
    //preenche o dicionario
   makecode(txt,tree,"",size);
    
    //entrega o valor codificado para a string code
   code = encrypter(texto,txt);
    //entrega o o codigio decodificado para a string decode
    decode = decrypter(code,tree);
    
    printf("code = %s\n\ndecode = %s",code,decode);
    return 0;

}
