#include "lista.h"
#include <stdio.h>
int contarOcurrencias(Lista lst, Elemento v){
    int contador = 0;
    int i;
    for(i = 1; i <= longLista(lst); i++){
        if(infoLista(lst, i) == v){
            contador++;
        }
    }
    return contador;
}
//La complejidad de esta operación es O(n) en el peor caso

Lista obtenerMenores(Lista lst, Elemento v){
  Lista menores;
  menores = crearLista();
  Lista tmp;
  tmp = lst;
  while(tmp != NULL){
    if(tmp->dato < v)
      menores = anxLista(menores, tmp->dato);
    tmp = tmp->sig;
  }
  return menores;
}
//La complejidad de esta operación es O(n), donde n es el tamaño de la lista lst, ya que se recorre la lista una vez y se realizan operaciones constantes en cada iteración.
int main(){
  
  Lista l;
  l = crearLista();
  l = anxLista(l, 5); 
  l = anxLista(l, 10);
  l = anxLista(l, 12);
  l = anxLista(l, 15);
  Elemento v = 2;
  int ocurrencias = contarOcurrencias(l, v);
  printf("El valor %d aparece %d veces en la lista.\n", v, ocurrencias);

  Lista lst;
  lst = crearLista();
  lst = anxLista(lst, 5);
  lst = anxLista(lst, 8);
  lst = anxLista(lst, 3);
  lst = anxLista(lst, 7);
  lst = anxLista(lst, 2);
  lst = anxLista(lst, 1);
  int v = 6;
  Lista menores;
  menores = obtenerMenores(lst, v);
  printf("Elementos menores que %d:\n", v);
  Lista tmp;
  tmp = menores;
  while(tmp != NULL){
    printf("%d ", infoLista(tmp, 1));
    tmp = tmp->sig;
  }
  
  printf("\n");
return 0;
  
}
