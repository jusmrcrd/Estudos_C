#include<stdio.h>
#define SIZE 12

int full(int arr[],int i){
    static int cont = 0;

    if(cont < i){
        arr[cont]= cont;
        cont++;
        full(arr,i);
    }
    return 0;
}


int Bfound(int ar[],int r,int init, int end){
   static int cont;
   cont++;

   if(end >= init){
        int mid = init +(end - init)/2;
    
        if(ar[mid] == r)
            return mid;
        

        if(ar[mid] < r){
            printf("%d",mid);
            Bfound(ar,r,mid+1,end);
        }
        else{
            printf(" %d ",mid);
            Bfound(ar,r,init,mid-1);
        }
   }
   return -1;
}


int main(int argc,char *argv[]){
    int ar[SIZE],busca,r;
   
    full(ar,SIZE); 
    printf("digite o numero para localizar o numero na busca binaria: ");
    scanf("%d",&r);

    busca = Bfound(ar,r,0,SIZE-1);
    if(busca == -1){   
        printf("numero nao dispinivel no indice");
    }else{ 
          printf("achado o numero %d",busca);
    } 

    return 0;
}
