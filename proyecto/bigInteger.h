#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <list>
#include <iostream>
#include <deque>
#include <string>

using namespace std;

class BigInteger {
    
    private:
        list<int>digitos;
        int signo; //0 positivo 1 negativo

    public:
        BigInteger();
        BigInteger(string&);
        BigInteger(BigInteger&);
        void imprimir();
        void add(BigInteger&);
        void product(BigInteger&);
        void substract(BigInteger&);
        //void remainder(BigInteger&);    
        //void pow(BigInteger&);
        //string toString();
        bool operator ==(BigInteger&);
        bool operator<( BigInteger&) ;
        bool operator <=( BigInteger&) ;
        BigInteger operator +( BigInteger&) ;
        BigInteger operator -( BigInteger& ) ;
        //BigInteger operator*( BigInteger& ) ;
        //BigInteger operator/( BigInteger& ) ;
        //BigInteger operator %( BigInteger& ) ;
        static BigInteger sumarListaValores(list<BigInteger>&);  
        //BigInteger multiplicarListaValores(list<BigInteger>& lista);  
};

#endif