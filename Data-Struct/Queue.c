#include<stdio.h>
#include<stdlib.h>

struct queue{
    int value;
    struct queue* node;
};

typedef struct queue* No;


//insert item in Queue
void push(No *QPtr_node, int number){
    No Ptr_newnod = malloc(sizeof(No));
    No QPtr_aux = *QPtr_node;

    Ptr_newnod->value = number;
    Ptr_newnod->node = NULL;

    if(*QPtr_node == NULL){
        *QPtr_node = Ptr_newnod;
        Ptr_newnod = *QPtr_node;
    }else{
        while(QPtr_aux->node != NULL){
            QPtr_aux = QPtr_aux->node;
        }
        QPtr_aux->node = Ptr_newnod;
    }
}

//remove item in Queue
void pop(No* QPtr_node){
    if(*QPtr_node == NULL){
        printf("\nfila vazia...\n");
    }else{
        No QPtr_temp;
        QPtr_temp = *QPtr_node;
        *QPtr_node = (*QPtr_node)->node;
        free(QPtr_temp);
    }
}
// print queue in terminal
void printQueue(No *SP_node){
    No SP_aux = *SP_node;
    printf("\n");
    while(SP_aux != NULL){
            printf(" %d ",SP_aux->value);
            SP_aux = SP_aux->node;
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
                    printf("\nRemovendo item na fila \n");
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
