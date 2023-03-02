//Juan David Vasquez Pomar punto4 jumpers
#include<stdio.h>
int n,a,i;
void jumpers(){
    while (scanf("%i",&n)!=EOF){
        int contador = 0;
        int arreglo[n];
        for(a=0;a<n;a++){
            scanf("%i",&arreglo[a]);
        }
        for(i=1;i<n;i++){
            int formula = arreglo[i-1]-arreglo[i];
            if (formula < 0) {
                formula = -formula;
            }
            if((formula> 0) && (formula < (n))){
                int g = n-1;
                contador +=1;
            }
        }
        if (contador == n-1){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }
    }
    
}
int main() {
jumpers();
return 0;
}