#include<stdio.h> 
#include<stdlib.h> 
   
struct stack{ 
      int value; 
      struct stack* node; 
  }; 
   
typedef struct stack* No; 
 
void push(No* st, int num){ 
    No newnod = malloc(sizeof(No)); 
    No aux = *st; 
   
    newnod->value = num; 
    newnod->node = NULL; 
     
    if(*st == NULL){ 
      *st = newnod; 
      newnod = *st; 
    }else{ 
        newnod->node = *st; 
        *st = newnod; 
    } 
   
  } 
   
  void pop(No* st){ 
    No aux = *st; 
     
    if(*st == NULL){ 
      printf("      lista vazia..\n"); 
    }else{ 
      *st = (*st)->node; 
      free(aux);  
    } 
  } 
   
  void print(No* st){ 
    No aux = *st; 
    while(aux != NULL){ 
      printf("           %d\n",aux->value);  
      aux = aux->node; 
    } 
    printf("\n"); 
  } 
   
  void show(){ 
    printf("Selecione sua opção \n(1) inserir intem da pilha \n(2) remover intem da pilha \n(3) sair\n\nDigite:"); 
  } 
   
   
  int main(int argc , char* argv[]){ 
    No stack = NULL; 
    int chose,num; 
     
   
    show(); 
    scanf("%d",&chose); 
     
    while(chose != 3){ 
       
      switch(chose){ 
          case 1:  
            printf("\nDigite um numero para colocar na pilha.."); 
            scanf("%d",&num); 
            push(&stack,num); 
            printf("\n Inserindo intem da pilha\n"); 
            print(&stack); 
          break; 
           
          case 2: 
            printf("\n Removendo item da pilha \n"); 
            pop(&stack); 
            print(&stack); 
          break; 
          default: 
            printf("\nEscolha invalida\n"); 
            show(); 
          break;  
      } 
      show(); 
      scanf("%d",&chose); 
    } 
    return 0; 
  } 

