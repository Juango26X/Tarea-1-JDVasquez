
#include <list>
#include <forward_list>
#include <iostream>
#include <deque>
using namespace std;

class BigInteger {
public:
    list<int> digitos;
    BigInteger(string);
    BigInteger(BigInteger&);
        void add(BigInteger&);
    void product(BigInteger&);
    void subtract(BigInteger&);
    void remainder(BigInteger&);
    void pow(BigInteger&);
    string toString() ;
    bool operator ==( BigInteger& ) ;
    bool operator<( BigInteger& ) ;
    bool operator <=( BigInteger& ) ;
    BigInteger operator +( BigInteger& ) ;
    BigInteger operator -( BigInteger& ) ;
    BigInteger operator*( BigInteger& ) ;
    BigInteger operator/( BigInteger& ) ;
    BigInteger operator %( BigInteger& ) ;
    BigInteger sumarListaValores(list<BigInteger>& lista);
    BigInteger multiplicarListaValores(list<BigInteger>& lista);

};


