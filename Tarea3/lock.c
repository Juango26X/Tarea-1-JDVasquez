//Juan David Vasquez Pomar punto3 lock
#include <stdio.h>
void lock(){
 int pos, num1, num2, num3, grados;
    scanf("%d %d %d %d", &pos, &num1, &num2, &num3);
    while ((pos != 0 || num1 != 0) && (num2 != 0 || num3 != 0)) {
    
        grados = 1080; 
        grados += (pos - num1 + 40) % 40 * 9;  
        grados += (num2 - num1 + 40) % 40 * 9;  
        grados += (num2 - num3 + 40) % 40 * 9;  
        
        printf("%i\n", grados);
        scanf("%d %d %d %d", &pos, &num1, &num2, &num3);
    }
    
}
int main() {
    lock();
    return 0;
}