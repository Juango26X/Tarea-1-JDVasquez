#include "lista.h"

Lista crearLista(){
  Lista lst;
  lst = NULL;
  return lst;
}

Lista anxLista(Lista lst, Elemento elem){
  Lista nuevo, tmp;
  nuevo = (Lista) malloc(sizeof(struct nodo));
  nuevo->dato = elem;
  nuevo->sig = NULL;
  
  if(lst == NULL)
    lst = nuevo;
  else{
    tmp = lst;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }
  
  return lst;
}

Lista insLista(Lista lst, Elemento elem, int pos){
  Lista nuevo,tmp;
  
  nuevo = (Lista) malloc(sizeof(struct nodo));
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista(lst)){
    if(pos == 1){
      nuevo->sig = lst;
      lst = nuevo;
    }
    else{
      tmp = lst;
      int i;
      for(i = 0; i < pos-2; i++)
        tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
    }
  }
  
  return lst;
}

Lista elimLista(Lista lst, int pos){
  Lista tmp;
  
  if(pos >= 1 && pos <= longLista(lst)){
    if(pos == 1)
      lst = lst->sig;
    else{
      tmp = lst;
      int i;
      for(i = 0; i < pos-2; i++)
        tmp = tmp->sig;
      tmp->sig = tmp->sig->sig;
    }
  }
  
  return lst;
}

Elemento infoLista(Lista lst, int pos){
  Lista tmp;
  tmp = lst;
  int i;
  
  for(i = 1; i < pos; i++)
    tmp = tmp->sig;
  return tmp->dato;
}

int longLista(Lista lst){
  Lista tmp;
  int cont = 0;
  tmp = lst;
  
  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }
  
  return cont;
}

int vaciaLista(Lista lst){
  return lst == NULL;
}
