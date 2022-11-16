#include<iostream>
using namespace std;

class Fraction {
    int bunja;
    int bunmo;

public:
    int gcd(int a, int b);//최대공약수
    Fraction() { bunja = 0; bunmo = 1; }
    Fraction(int ja, int mo) { 
        /*int gv = gcd(bunja, bunmo);
        ja = ja/gv;
        mo = mo/gv;*/
        bunja = ja;
        bunmo = mo;
    }
   
    void show() {
        int gv = gcd(bunja, bunmo);
        bunja /= gv;
        bunmo /= gv;
        cout << bunja;
        if(bunmo != 1)
            cout << "/" << bunmo;
    }
    Fraction operator+(Fraction ob);
    Fraction operator+(int n);
    bool operator==(Fraction ob);
    Fraction operator-(Fraction ob);
    Fraction operator*(Fraction ob);
    Fraction& operator+=(Fraction ob);
    Fraction& operator-=(Fraction ob);
    Fraction& operator*=(Fraction ob);
};

int Fraction::gcd(int a, int b)
{
    return (a % b == 0) ? b : gcd(b, a % b);
}

Fraction Fraction::operator+(Fraction ob)
{
    Fraction tmp;
    tmp.bunja = this->bunja * ob.bunmo + this->bunmo * ob.bunja;
    tmp.bunmo = this->bunmo * ob.bunmo;
    return tmp;
}
Fraction Fraction :: operator+(int n)
{
    Fraction tmp;
    tmp.bunja = this->bunja + this->bunmo * n;
    tmp.bunmo = this->bunmo;
    return tmp;
}
bool Fraction::operator==(Fraction ob)
{
    return bunja == ob.bunja && bunmo == ob.bunmo;
}

Fraction Fraction::operator-(Fraction ob)
{
    Fraction tmp;
    tmp.bunja = this->bunja * ob.bunmo - this->bunmo * ob.bunja;
    tmp.bunmo = this->bunmo * ob.bunmo;
    return tmp;
}

Fraction Fraction::operator*(Fraction ob)
{
    Fraction tmp;
    tmp.bunja = this->bunja * ob.bunja;
    tmp.bunmo = this->bunmo * ob.bunmo;
    return tmp;
}

Fraction& Fraction::operator+=(Fraction ob)
{
    
    this->bunja = this->bunja * ob.bunmo + this->bunmo * ob.bunja;
    this->bunmo = this->bunmo * ob.bunmo;
    return *this;
}

Fraction& Fraction::operator-=(Fraction ob)
{
    this->bunja = this->bunja * ob.bunmo - this->bunmo * ob.bunja;
    this->bunmo = this->bunmo * ob.bunmo;
    return *this;
}

Fraction& Fraction::operator*=(Fraction ob)
{
    this->bunja = this->bunja * ob.bunja;
    this->bunmo = this->bunmo * ob.bunmo;
    return *this;
}

int main() {
    Fraction a(3, 4), b(1, 4), c;
    c = a + b;
    c.show();
    cout << endl;
    c = a + 2;
    c.show();
    cout << endl;
    if (a == b)
        cout << "같아요";
    else
        cout << "달라요";
    cout << endl;
    c = a - b;
    c.show();
    cout << endl;
    c = a * b;
    c.show();
    cout << endl;
    a += b;
    a.show(); 
    cout << endl;
    a -= b;
    a.show();
    cout << endl; 
    a *= b;
    a.show();

}