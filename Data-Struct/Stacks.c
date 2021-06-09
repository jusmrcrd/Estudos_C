#include<stdio.h> 
#include<stdlib.h> 
   
struct stack{ 
      int value; 
      struct stack* node; 
  }; 
   
typedef struct stack* No; 
 
void push(No* SP, int num){ 
    No newnod = malloc(sizeof(No)); 

    newnod->value = num; 
    newnod->node = NULL; 
     
    if(*SP == NULL){ 
      *SP = newnod; 
      newnod = *SP; 
    }else{ 
        newnod->node = *SP; 
        *SP = newnod; 
    } 
   
  } 
   
  void pop(No* SP){ 
    No aux = *SP; 
     
    if(*SP == NULL){ 
      printf("      lista vazia..\n"); 
    }else{ 
      *SP = (*SP)->node; 
      free(aux);  
    } 
  } 
   
  void print(No* SP){ 
    No aux = *SP; 
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

