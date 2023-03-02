/*Juan David Vasquez Pomar Punto 1 Parking # */
#include <limits.h>
#include <stdio.h>
int main() {
int ejecuciones;
int ctiendas;
scanf("%i",&ejecuciones);
int g;
for(g=0;g<ejecuciones;g++){
scanf("%i",&ctiendas);
int tiendas[ctiendas];
int i;
for(i=0;i<ctiendas;i++){
    scanf("%i", &tiendas[i]);
}
int maximo =  INT_MIN;
int minimo =  INT_MAX;
int x;
for (x=0;x<ctiendas;x++){
    if(tiendas[x]<minimo){
        minimo=tiendas[x];
    }
     if(tiendas[x]>maximo){
        maximo=tiendas[x];
    }
}
int ans = (maximo-minimo)*2;
printf("%i\n",ans);
}
return 0;
}