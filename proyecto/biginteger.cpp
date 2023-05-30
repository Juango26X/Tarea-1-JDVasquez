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
    else if (digitos.size()!=num.digitos.size()){
        if (signo==0){
            if (digitos.size() < num.digitos.size()) {
                ans = true;
            } 
            else if (digitos.size() > num.digitos.size()) {
                ans = false;
            } 
        }
        else if (signo==1){
            if (digitos.size() < num.digitos.size()) {
                ans = false;
            } 
            else if (digitos.size() > num.digitos.size()) {
                ans = true;
            } 
        }
        
    } 
    else {
            list<int>::const_iterator it1 = digitos.begin();
            list<int>::const_iterator it2 = num.digitos.begin();
            if (signo == 0){
                int flag1 = 0;
                while (it1 != digitos.end()&&flag1!=1) {
                    if (*it1 < *it2) {
                        ans = true;
                        flag1 = 1;
                    } 
                    else if (*it1 > *it2) {
                        ans = false;
                         flag1 = 1;
                    }
                    ++it1;
                    ++it2;
                }
            }
            else{
                int flag=0;
                while (it1 != digitos.end()&&flag!=1) {
                    if (*it1 < *it2) {
                        ans = false;
                        flag = 1;
                    } 
                    else if (*it1 > *it2) {
                        ans = true;
                        flag = 1;
                    }
                    ++it1;
                    ++it2;
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
        if(signo==0){
            num.signo=0;
        }
        else if (signo==1){
            num.signo=1;
        }
        list<int>ans;
        if (signo != num.signo) {
            if(signo==0){
                num.signo=0;
            }
            else if (signo==1){
                num.signo=1;
            }
        } 
       
        else {
            list<int>::reverse_iterator it1;
            list<int>::reverse_iterator it2;
            list<int>::reverse_iterator end1;
            list<int>::reverse_iterator end2;
            int signoans;
            int sobra = 0;
            if (signo==0){
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
            else if(signo==1){
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
                cout << "p";
                ans.pop_front();
            }

            digitos = ans;
            signo = signoans;
        }
    }
}

void BigInteger::substract(BigInteger& num) {
        list<int>ans;
        if (signo != num.signo) {
            if(signo==0){
                num.signo=0;
            }
            else if (signo==1){
                num.signo=1;
            }
        } 
       
        else {
            list<int>::reverse_iterator it1;
            list<int>::reverse_iterator it2;
            list<int>::reverse_iterator end1;
            list<int>::reverse_iterator end2;
            int signoans;
            int sobra = 0;
            if (signo==0){
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
            else if(signo==1){
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
                cout << "p";
                ans.pop_front();
            }

            digitos = ans;
            signo = signoans;
        }
}

BigInteger BigInteger::operator+(BigInteger& num) {
    BigInteger ans1;
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
            ans1.digitos.push_front(sum % 10);  
            carry = sum / 10;  
        }
        ans1.signo = signo;
        signo=ans1.signo;
        digitos=ans1.digitos;
    }
    else{
        if(signo==0){
            num.signo=0;
        }
        else if (signo==1){
            num.signo=1;
        }
        list<int>ans;
        if (signo != num.signo) {
            if(signo==0){
                num.signo=0;
            }
            else if (signo==1){
                num.signo=1;
            }
        } 
       
        else {
            list<int>::reverse_iterator it1;
            list<int>::reverse_iterator it2;
            list<int>::reverse_iterator end1;
            list<int>::reverse_iterator end2;
            int signoans;
            int sobra = 0;
            if (signo==0){
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
            else if(signo==1){
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
                cout << "p";
                ans.pop_front();
            }

            ans1.digitos = ans;
            ans1.signo = signoans;
        }
    }
    return ans1;
}
BigInteger BigInteger::operator-(BigInteger& num) {
    BigInteger ans1;
    list<int>ans;
        if (signo != num.signo) {
            if(signo==0){
                num.signo=0;
            }
            else if (signo==1){
                num.signo=1;
            }
        } 
       
        else {
            list<int>::reverse_iterator it1;
            list<int>::reverse_iterator it2;
            list<int>::reverse_iterator end1;
            list<int>::reverse_iterator end2;
            int signoans;
            int sobra = 0;
            if (signo==0){
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
            else if(signo==1){
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
                cout << "p";
                ans.pop_front();
            }

            ans1.digitos = ans;
            ans1.signo = signoans;
        }
    return ans1;
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
        vector<int> subproducto(lugar, 0);

        for (int d2 : num.digitos) {
            int producto = (d1 * d2) + subproducto_carry;
            subproducto.push_back(producto % 10);
            subproducto_carry = producto / 10;
        }
        while (subproducto_carry > 0) {
            subproducto.push_back(subproducto_carry % 10);
            subproducto_carry /= 10;
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

string BigInteger::toString() {
    string result;
    if (signo == 1) {
        result += "-";
    }
    for (int digit : digitos) {
        char digitChar = '0' + digit;  
        result += digitChar;          
    }
    return result;
}
static BigInteger multiplicarListaValores(list<BigInteger>& lista) {
    BigInteger producto;
    for (BigInteger& valor : lista) {
        producto.product(valor);
    }
    return producto;
}

