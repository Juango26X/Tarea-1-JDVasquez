/*Juan David Vasquez Pomar Punto 5 Finish # */
#include <stdio.h>
void finish (){
int ejecuciones;
int n;
scanf("%i",&ejecuciones);
int g;
for(g=0;g<ejecuciones;g++){
    int inicio = 0;
    scanf("%i",&n);
    int gasolinera1[n];
    int i;
    int ans = 0;
    int inicioans;
    for(i=0;i<n;i++){
        scanf("%i", &gasolinera1[i]);
    }
    int x;
    int gasolinera2[n];
    for(x=0;x<n;x++){
        scanf("%i", &gasolinera2[x]);
    }
    while (inicio<n){

        int tanque = 0;
        int contador = 0;
        for(x=inicio;x < n; x++){
            tanque +=gasolinera1[x];
            tanque -=gasolinera2[x];
            if (tanque < 0){
              x = n;  
            }
            else {
                contador+=1;
            }

        }
        for(x=0;x < inicio; x++){
            tanque +=gasolinera1[x];
            tanque -=gasolinera2[x];
            if (tanque < 0){
              x = n;  
            }
            else {
                contador+=1;
            }
       
        }
        if (contador == n){
            inicioans=inicio;
            inicio=n;
            ans = 1;
        }
        else {
            inicio +=1;
        }
        
    }
    if (ans == 1) {
        printf("Case %i: Possible from station %i\n",(g+1),(inicioans+1));
    }
    else {
         printf("Case %i: Not possible\n",(g+1));
    }
}
}
int main() {
    finish();
return 0;
}