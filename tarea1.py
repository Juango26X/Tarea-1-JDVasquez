#Tarea1 Juan David Vasquez Pomar
#punto1
import math
def verificarDiagonales(mat):
    pos = 0
    ans = True
    while pos != (len(mat)) and ans != False:
        if mat[pos][pos] == mat[pos][(len(mat)-1)-pos]:
            pos +=1
        else:
            ans = False
    return ans
#punto2
def esCapicua(lista):
    j=0
    ans=True
    while j != len(lista) and ans != False:
        if lista[j] == lista[(len(lista)-1)-j]:
            j +=1
        else:
            ans = False
            j +=1
    return ans
    
#punto3 a
def diferenciaListas(a,b):
    ans=[]
    for i in range(len(a)):
        if a[i] in b:
            b.remove(a[i])
        else: 
            ans.append(a[i])
    return ans

#punto 3 b

def leerImprimir():
    g =int(input())
    for i in range(g):
        a = input()
        listaA = a.split()
        listaA.pop(0)
        b = input()
        listaB = b.split()
        listaB.pop(0)
        ans = diferenciaListas(listaA,listaB)
        ansStr = ", ".join(ans)
        print(ansStr)
    return ansStr



#punto4
def comprobarprimo(i):
    ans = True
    if i <= 1:
        ans = False
    else:
        for q in range(2, int(math.sqrt(i)) + 1):
                if i % q == 0:
                 ans = False
    return ans

def sumardigitos(num): #operación usada para sumardigitos de un numero ejem:. 12345 = 15
    total = 0
    while num > 0:
        digito = num % 10
        total += digito
        num = num // 10
    return total
def mostrarPrimos(n): #operación usada para hayar
    conprimos = []
    for g in range(1,n+1):
        ans=comprobarprimo(g)
        if ans == True:
            print("--> %d,"%(g))
            conprimos.append(g)
    print()
    print("Números entre 1 y 100 con suma de dígitos con valor primo:")
    for e in range(len(conprimos)):
        digito2=sumardigitos(conprimos[e])
        ans2= comprobarprimo(digito2)
        if ans2 == True:
            if e == (len(conprimos)):
             print("%d"%(conprimos[e]),end="")
            else:
                print("%d"%(conprimos[e]),end=",")

mostrarPrimos(100)

#punto5
disp = {0 : [(0, 1), (5, 4), (7, 5)],
1 : [(6, 4), (7, 7)],
2 : [(0, 2), (1, 2), (4, 9), (6, 1)],
4 : [(2, 8), (3, 1), (5, 7)],
6 : [(0, 3), (5, 6), (7, 2)],
7 : [(0, 4), (1, 4), (2, 7)],
8 : [(1, 9), (3, 8), (5, 7), (7, 6)]}

def sumarValoresMatriz(d,b):
    ans=0
    for g in range(len(b)):
        if b[g][0] in d and b[g][1] <= (len(d[b[g][0]])-1):

            #print(b[g][0])
            #print(b[g][1])
            ans += (d[b[g][0]][b[g][1]][1])
        else:
         print("na")
    return ans
sumarValoresMatriz(disp, [(0, 0), (8, 3), (3, 5), (7, 2), (4, 3), (4,6)])
    
