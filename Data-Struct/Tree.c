#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define SIZE 16
#define FOUND_KEY  75

struct node{
    int key;
    struct node* Ptr_left;
    struct node* Ptr_right;
};

typedef struct node* No;

void inserTree(No* TPr_node, int key){
    if(*TPr_node == NULL){
        *TPr_node = malloc(sizeof(No));
        
        if(*TPr_node != NULL){ 
            (*TPr_node)->key = key;
            (*TPr_node)->Ptr_left = NULL;
            (*TPr_node)->Ptr_right = NULL;
        
        }else{
            printf("erro");
        }

    }else{
        if(key < (*TPr_node)->key){
            inserTree(&(*TPr_node)->Ptr_left,key);
        }else{
            inserTree(&(*TPr_node)->Ptr_right,key);
        }
    }
}

void swap(No* TPtr_node){
    if(*TPtr_node == NULL){
        return; 
    }else{
        No Ptr_temp;
        
        Ptr_temp = (*TPtr_node)->Ptr_left;
        (*TPtr_node)->Ptr_left = (*TPtr_node)->Ptr_right;
        (*TPtr_node)->Ptr_right =Ptr_temp;

        swap(&(*TPtr_node)->Ptr_left);
        swap(&(*TPtr_node)->Ptr_right);
    
     }
}



bool found(No* TPtr_node,int key){
    
    if(*TPtr_node != NULL){
        if(key == (*TPtr_node)->key){
            return true;
        }else{
            if(key < (*TPtr_node)->key){
                found(&(*TPtr_node)->Ptr_left,key);
            }else{
                found(&(*TPtr_node)->Ptr_right,key);
            }
        }
    }else {
        return false;
    }
}


No minimun_node(No* TPtr_node){
    No aux = *TPtr_node;

    while(aux && aux->Ptr_left != NULL){
        aux = aux->Ptr_left;
    }
    return aux;
}

void bremove(No* TPtr_node,int key){
    No TPtr_aux = *TPtr_node;

    if(key == (*TPtr_node)->key){
        if((*TPtr_node)->Ptr_left == NULL){
            *TPtr_node = (*TPtr_node)->Ptr_right;
            free(TPtr_aux);

        }else{
            No temp = minimun_node(&(*TPtr_node)->Ptr_right);
            
            (*TPtr_node)->key = temp->key;
            bremove(&(*TPtr_node)->Ptr_right,temp->key);

        }
    }else{
        if(key < (*TPtr_node)->key){
            bremove(&(*TPtr_node)->Ptr_left,key); 
        }else{
            bremove(&(*TPtr_node)->Ptr_right,key); 
        }
    }
}


void inorder(No node){
    if(node != NULL){
        inorder(node->Ptr_left);
        printf(" %d ",node->key);
        inorder(node->Ptr_right);
    }
}

void preorder(No node){
    if(node != NULL){
        printf(" %d ",node->key);
        preorder(node->Ptr_left);
        preorder(node->Ptr_right);
    }
}

void posorder(No node){
    if(node !=NULL){
        posorder(node->Ptr_left);
        posorder(node->Ptr_right);
        printf(" %d ",node->key);
    }

}

int main(int argc , char* argv[]){
    srand(time(NULL));
    
    No tree = NULL;
    
    int time[SIZE]={5,6,35,8,37,38,1,7,4,3,12,14,13,11,10,2};
    for(int i = 0; i < 16; i++){
        inserTree(&tree,time[i]);
    }
    
    //swap(&tree);
    
    bremove(&tree,2);
   
    swap(&tree);
    
    inorder(tree);
    preorder(tree);
    posorder(tree);    


    if(found(&tree,FOUND_KEY) == true){
        printf("\n numero:%d achado na arvore",FOUND_KEY);
    }else{
        printf("\nnumero:%d não encontrado",FOUND_KEY);
    }

    return 0;
}
