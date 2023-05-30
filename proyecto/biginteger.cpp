#include "bigInteger.h"
BigInteger::BigInteger(){

}
BigInteger::BigInteger(string& numero){
    signo= 0;
    if (numero[0]== '-'){
        signo = 1;
    }            
    for(int i=signo;i<numero.length();i++){
        digitos.push_back(numero[i]-'0');
    }
}
    void BigInteger::imprimir(){
        if (signo==1){
            string signos = "-";
            cout << signos;
        }
        for (list<int>::iterator it = digitos.begin(); it != digitos.end(); it++) {
            cout << *it;
        }
    }
BigInteger::BigInteger(BigInteger& bg) {
    signo = bg.signo;
    digitos = bg.digitos;
}
bool BigInteger::operator==(BigInteger& num) {
    return (digitos == num.digitos) && (signo == num.signo);
}

bool BigInteger::operator<(BigInteger& num){
    bool ans =false;
    if (signo > num.signo) {
        ans = true;
    } 
    else if (signo < num.signo) {
        ans = false;
    } 
    else {
        if (digitos.size() < num.digitos.size()) {
            ans = true;
        } 
        else if (digitos.size() > num.digitos.size()) {
            ans = false;
        } 
        else {
            list<int>::const_iterator it1 = digitos.begin();
            list<int>::const_iterator it2 = num.digitos.begin();
            if (signo == 0){
                while (it1 != digitos.end()) {
                    if (*it1 < *it2) {
                        ans = true;
                    } 
                    else if (*it1 > *it2) {
                        ans = false;
                    }
                    ++it1;
                    ++it2;
                }
            }
            else{
                while (it1 != digitos.end()) {
                    if (*it1 < *it2) {
                        ans = true;
                    } 
                    else if (*it1 > *it2) {
                        ans = false;
                    }
                    ++it1;
                    ++it2;
                }
            }
            
        }

    }
    return ans;
}
bool BigInteger::operator<=(BigInteger& num) {
    return (*this < num) || (*this == num);
}

void BigInteger:: add(BigInteger& num){
    BigInteger ans;
    if (signo == num.signo){
        int carry = 0;  
        list<int>::reverse_iterator it1 = digitos.rbegin();
        list<int>::reverse_iterator it2 = num.digitos.rbegin();
        while (it1 != digitos.rend() || it2 != num.digitos.rend() || carry != 0) {
            int sum = carry; 
            if (it1 != digitos.rend()) {
                sum += *it1;
                ++it1;
            }
            if (it2 != num.digitos.rend()) {
                sum += *it2;
                ++it2;
            }
            ans.digitos.push_front(sum % 10);  
            carry = sum / 10;  
        }
        ans.signo = signo;
        signo=ans.signo;
        digitos=ans.digitos;
    }
    else{
        if(signo=0){
            num.signo=0;
        }
        else if (signo=1){
            num.signo=1;
        }
        //substract(num);
    }
}

void BigInteger::substract(BigInteger& num) {
    list<int>ans;
    if (signo != num.signo) {
        if(signo=0){
            num.signo=0;
        }
        else if (signo=1){
            num.signo=1;
        }
        add(num);
    } 
    else {
        list<int>::reverse_iterator it1;
        list<int>::reverse_iterator it2;
        list<int>::reverse_iterator end1;
        list<int>::reverse_iterator end2;
        int* end1;
        int* end2;
        int signoans;
        int sobra = 0;
        if (signo=0){
            if(*this<num){
            signoans =1;
            it1 = num.digitos.rbegin();
            end1= num.digitos.rend();
            it2 = digitos.rbegin();   
            end2= digitos.rend();    
            }
            else{
                signoans =0;
                it1 = digitos.rbegin();
                end1= digitos.rend();
                it2 = num.digitos.rbegin();
                end2= num.digitos.rend();
            }
        }
        else if(signo=1){
            if(*this<num){
            signoans =1;
            it1 = digitos.rbegin();
            end1= digitos.rend();
            it2 = num.digitos.rbegin();
            end2= num.digitos.rend();
 
            }
            else{
            signoans = 0;
            it1 = num.digitos.rbegin();
            end1= num.digitos.rend();
            it2 = digitos.rbegin();   
            end2= digitos.rend();    
            }
        } 
        while (it1 != end1 || it2 != end2) {
            int diff = sobra;
            if (it1 != end1) {
                diff += *it1;
                ++it1;
            }
            if (it2 != end2) {
                diff -= *it2;
                ++it2;
            }
            if (diff < 0) {
                diff += 10;
                sobra = -1;
            } else {
                sobra = 0;
            }
            ans.push_front(diff);
        }
        while (!digitos.empty() && digitos.front() == 0) {
            ans.pop_front();
        }

        digitos = ans;
        signo = signoans;
    }
}

BigInteger BigInteger::operator+(BigInteger& num) {
    BigInteger ans;
    if (signo == num.signo){
        int carry = 0;  
        list<int>::reverse_iterator it1 = digitos.rbegin();
        list<int>::reverse_iterator it2 = num.digitos.rbegin();
        while (it1 != digitos.rend() || it2 != num.digitos.rend() || carry != 0) {
            int sum = carry; 
            if (it1 != digitos.rend()) {
                sum += *it1;
                ++it1;
            }
            if (it2 != num.digitos.rend()) {
                sum += *it2;
                ++it2;
            }
            ans.digitos.push_front(sum % 10);  
            carry = sum / 10;  
        }
        ans.signo = signo; 
    }
    else{
    
    }
    return ans;
}
void BigInteger::product(BigInteger& num) {
    BigInteger ans;
    if (digitos.size() == 1 && digitos.front() == 0) {
        digitos = {0};
        signo = 0;
        return;
    } else if (num.digitos.size() == 1 && num.digitos.front() == 0) {
        digitos = {0};
        signo = 0;
        return;
    }
    int carry = 0;
    int lugar = 0;
    for (int d1 : digitos) {
        int subproducto_carry = 0;
        deque<int> subproducto;

        for (int i = 0; i < lugar; i++) {
            subproducto.push_back(0);
        }
        for (int d2 : num.digitos) {
            int producto = (d1 * d2) + subproducto_carry;
            subproducto.push_back(producto % 10);
            subproducto_carry = producto / 10;
        }
        if (subproducto_carry > 0) {
            subproducto.push_back(subproducto_carry);
        }
        BigInteger subproductoBigInt;
        subproductoBigInt.digitos = list<int>(subproducto.begin(), subproducto.end());
        ans.add(subproductoBigInt);

        lugar++;
    }
    if (signo != num.signo) {
        ans.signo = 1;
    } else {
        ans.signo = 0;
    }
    digitos = ans.digitos;
    signo = ans.signo;
}
static BigInteger sumarListaValores(list<BigInteger>& lista) {
    BigInteger suma;
    for (BigInteger& valor : lista) {
        suma.add(valor);
    }
    return suma;
}

