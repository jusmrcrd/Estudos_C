#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int MAX = 10;

// Ptr_arr = array 
// i = indice matrix

//function por make a maxheap
void maxheapify(int* Ptr_arr,int i,int size){
    int Child_heap = 0;
    int maxHeapify; 
    maxHeapify = Ptr_arr[i];
    
    while(i <= (size/2)){
        Child_heap = i*2;
        
        if(Child_heap < size && Ptr_arr[Child_heap] < Ptr_arr[Child_heap+1])
                Child_heap++;
        if(maxHeapify >= Ptr_arr[Child_heap])
            break;
    
        Ptr_arr[i] = Ptr_arr[Child_heap];
        i = Child_heap;
    }
    Ptr_arr[i] = maxHeapify;
}

void makeheap(int* Ptr_arr,int max_heap){
    int trade;
    for(int i = (max_heap/2); i >= 0; i--){
        maxheapify(Ptr_arr,i,max_heap);
    }

    while(max_heap >= 0){
        trade = Ptr_arr[0];
        Ptr_arr[0] = Ptr_arr[max_heap];
        Ptr_arr[max_heap] = trade;
       maxheapify(Ptr_arr,0,--max_heap); 
    }
}

int main(int argc,char* argv[]){
   
    int* Ptr_arr;
    srand(time(NULL));   
    Ptr_arr = malloc(MAX*sizeof(int)); 
    
    for(int i = 0; i < MAX; i++) Ptr_arr[i] = rand()%765;
    
    makeheap(Ptr_arr,MAX);
        
    printf("\n");
    for(int j = 0 ; j <= MAX; j++) printf(" %d ",Ptr_arr[j]);
 
    return 0;
}
