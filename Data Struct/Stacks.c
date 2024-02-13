#include<stdio.h> 
#include<stdlib.h> 
   
struct stack{ 
      int value; 
      struct stack* Ptr_node; 
  }; 
   
typedef struct stack* No; 
 
void push(No* SPtr_node, int num){ 
    No SPtr_newnod = malloc(sizeof(No)); 

    SPtr_newnod->value = num; 
    SPtr_newnod->Ptr_node = NULL; 
     
    if(*SPtr_node == NULL){ 
      *SPtr_node = SPtr_newnod; 
      SPtr_newnod = *SPtr_node; 
    }else{ 
        SPtr_newnod->Ptr_node = *SPtr_node; 
        *SPtr_node = SPtr_newnod; 
    }  
  } 
   
  void pop(No* SPtr_node){ 
    No aux = *SPtr_node; 
     
    if(*SPtr_node == NULL){ 
      printf("      Lista vazia..\n"); 
    }else{ 
      *SPtr_node = (*SPtr_node)->Ptr_node; 
      free(aux);  
    } 
  } 
   
  void printStack(No* SPtr_node){ 
    No SPtr_aux = *SPtr_node; 
    while(SPtr_aux != NULL){ 
      printf("           %d\n",SPtr_aux->value);  
      SPtr_aux = SPtr_aux->Ptr_node; 
    } 
    printf("\n"); 
  } 
   
  void show(){ 
    printf("Selecione sua opção \n(1) Inserir item na pilha \n(2) Remover item na pilha \n(3) Sair\n\nDigite:"); 
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
            printf("\n Inserindo item na pilha\n"); 
            printStack(&stack); 
        break; 
           
        case 2: 
            printf("\n Removendo item na pilha \n"); 
            pop(&stack); 
            printStack(&stack); 
        break; 
          
        default: 
            printf("\nEscolha invalida\n"); 
            show(); 
        break;  
      } 
      show(); 
      scanf("%d",&chose); 
    }
    printf("\nfim do programa...");
    return 0; 
  } 

