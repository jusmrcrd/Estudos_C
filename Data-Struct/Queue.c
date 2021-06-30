#include<stdio.h>
#include<stdlib.h>


struct queue{

    int value;
    struct queue* node;
};

typedef struct queue* No;

void push(No *SP, int num){
    No newnod = malloc(sizeof(No));
    No aux = *SP;

    newnod->value = num;
    newnod->node = NULL;

    if(*SP == NULL){
        *SP = newnod;
        newnod = *SP;
    }else{
        while(aux->node != NULL){
            aux = aux->node;
        }
        aux->node = newnod;
    }
}

void pop(No* SP){
    if(*SP == NULL){
        printf("fila vazia...");
    }else{
        No temp;
        temp = *SP;
        *SP = (*SP)->node;
        free(temp);
    }
}

void printQueue(No *SP){
    No aux = *SP;
    printf("\n");
    while(aux != NULL){
            printf(" %d ",aux->value);
            aux = aux->node;
    }
    printf("\n\n");
}

void show(){ 
        printf("\nSelecione sua opção \n(1) Inserir item na fila \n(2) Remover item na fila \n(3) Sair\n\nDigite:"); 
} 

int main(int argc, char* argv[]){
    No queue = NULL;
    int chose,num;
    show();
    scanf("%d",&chose);

    while(chose != 3){
        switch(chose){
            case 1:
                    printf("\nDigite um numero para colocar na fila.."); 
                    scanf("%d",&num);
                    push(&queue,num);
                    printf("\n Inserindo item na fila\n");
                    printQueue(&queue);
                    break;

            case 2:
                    
                    printf("\n Removendo item na fila \n");
                    pop(&queue); 
                    printQueue(&queue);
                    break;
            default:
                    printf("\nnumero invalido. tente novamente\n");
                    break;
        }
        show();
        scanf("%d",&chose);
    }
    printf("\nfinalizando programa...\n");
    return 0;
}
