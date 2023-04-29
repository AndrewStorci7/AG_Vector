//
// Created by andrew-drink on 28/04/23.
//

#ifndef ALGGAUSS_VECTOR_H
#define ALGGAUSS_VECTOR_H


class Vector {
private:
    Razionale* R;
    int n;
public:

    Vector() {
        n = 3;
        R = new Razionale[n];
        for ( int i = 0; i < n; i++ )
            R[i] = Razionale();
    }

    Vector( int n ) {
        this->n = n;
        this->R = new Razionale[n];
        for ( int i = 0; i < n; i++ )
            cin >> R[i];
    }

    // getter and setter
    void setN( int n ) { this->n = n; }
    int getN() { return this->n; }

    void print() {
        for ( int i = 0; i < this->n; i++ ) {
            cout << "X" << i << ": " << R[i] << ", ";
        }
    }
};

istream& operator>>( istream& s, Vector& o ) {
    int n = 0;
    bool valid = false;
    while ( !valid ) {
        cout << "Inserisci il numero di variabili: ";
        s >> n;
        if ( n == 0 )
            cin.clear();
        else if ( n > 10 )
            cin.clear();
        else if ( cin.fail() ) {
            cin.clear();
            cin.ignore( 10000000, '\n' );
        } else
            valid = true;
    }
    o = Vector( n );
    return s;
}

#endif //ALGGAUSS_VECTOR_H
