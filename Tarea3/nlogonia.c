//Juan David Vasquez Pomar punto2 nlogonia
#include<stdio.h>
void nlogonia(){
     int veces;
     scanf("%i",&veces);
     while(veces !=0){
        int num1, num2, i;
        scanf("%i %i", &num1, &num2);
        for(i=0;i<veces;i++){
        int nump1, nump2;
        scanf("%i %i", &nump1, &nump2);
        if (nump1 < num1 && nump2 > num2){
        printf("NO\n");
        }
        if (nump1 < num1 && nump2 < num2){
        printf("SO\n");
        }
         if (nump1 > num1 && nump2 > num2){
        printf("NE\n");  
        }
         if (nump1 > num1 && nump2 < num2){
        printf("SE\n");
        }
         if (nump1 == num1 || nump2 == num2){
        printf("divisa\n");
        }


        }
     scanf("%i",&veces);
     }  
}
int main(){
nlogonia();
return 0;
}