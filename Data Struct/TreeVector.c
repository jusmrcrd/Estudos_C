#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#define NUMNODES 500

struct treetype{
    int info;
    int dad;
    int left;
    int right;
    int used;
}node[NUMNODES];


//Start Tree;
void maketree(int value){
    
    node[0].info = value;
    node[0].dad = -1;
    node[0].used = true;
    for(int p = 1 ; p < NUMNODES ; p++){
        node[p].dad = -1;
        node[p].left = -1;
        node[p].right = -1;
        node[p].info = -1;
        node[p].used = false;
    }
}

//Setting left side
void setleft(int p ,int value){

    int q;
    q = 2*p+1;

    if(q >= NUMNODES){
            printf("estouro de vetor");
    }else{
        node[q].info = value;
        node[q].used = true;
        node[p].left = q;
        node[q].dad = p;
    }
        
}

//Setting right side
void setright(int p, int value){

    int q;

    q = 2*p+2;
    
    if(q >= NUMNODES){
        printf("estouro de vetor");
    }else{
        node[q].info = value;
        node[q].used = true;
        node[p].right = q;
        node[q].dad = p;

    }
}


int main(int agc,char* argv[]){
    int p ,q;

    //chose a yours randomic numbers modify here
    int ar[] = {15,6,2,3,45,69,21,36,14,65,1,12,80,70};


    maketree(ar[0]);

    for(int cont = 1; cont < 15-1; cont++){ 
        p = q= 0;
        
        // parte para percorrer a arvore igual a função recursiva;
        while(q < NUMNODES && node[q].used){    
            p = q;

            if(ar[cont] < node[p].info){
                  q = 2 * p + 1;
            }else{
                 q = 2 * p + 2;
            }
        }
    
        if(ar[cont] == node[p].info){
            printf("numero repetido");
        }else if(ar[cont] < node[p].info)
            setleft(p,ar[cont]);
        else
            setright(p,ar[cont]);
    } 
    
    for(int i = 0 ; i < sizeof(ar)/sizeof(int); i++)
        printf(" %d ",ar[i]);
    
    printf("\n");

    for(int i = 0 ; i < 50 ;i++){
     if(node[i].info == -1)
            printf(" - ");
     else
            printf(" %d ",node[i].info);
    }
}