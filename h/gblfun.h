//
// Created by sandr on 29/03/2023.
//

#ifndef ALGGAUSS_GBLFUN_H
#define ALGGAUSS_GBLFUN_H
#include "../classes/Razionale.cpp"
using namespace std;

// TODO: FINIRE ALGORTIMO PER TROVARE MCD
template <typename T>
T calc_divisor( T& r, T& o) {
    T ret;
    if ( r.getD() == 1 && o.getD() == 1 ) {
        if ( r.getN() == o.getN() )
            return ret = r - o;
        if ( r.getN() > o.getN() )
            return ret = T( ( r.getN() * o.getN() ) );
    }
}

void inizialize_matrix( Razionale **m, int r, int c, int i ) {
    if ( r == 1 )
        return;

    m[r - r] = new Razionale[c];
    return inizialize_matrix( m, r-1, c, i+1 );
}

void insert_data( Razionale **m, int r, int c ) {
    for ( int i = 0; i < r; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            Razionale new_r = Razionale();
            cout << "R" << i + 1 << " _ x" << j + 1 << ": ";
            cin >> new_r;
            m[i][j] = new_r;
        }
    }
}

void start() {
    int row = 0, col = 0;
    bool valid = false;
    while ( !valid ) {
        cout << "Inserisci le colonne: ";
        cin >> col;
        if ( cin.fail() ) {
            cin.clear();
            cin.ignore( INT_MAX, '\n' );
        } else if ( col <= 0 || col > 31 )
            cout << "Inserisci un numero tra 1 e 30!\n";
        else
            valid = true;
    }
    valid = false;
    while ( !valid ) {
        cout << "Inserisci le righe: ";
        cin >> row;
        if ( cin.fail() ) {
            cin.clear();
            cin.ignore( INT_MAX, '\n' );
        } else if ( row <= 0 || row > 31 )
            cout << "Inserisci un numero tra 1 e 30!\n";
        else
            valid = true;
    }
    Razionale **matrice = new Razionale* [row];
    inizialize_matrix( matrice, row, col, 0 );
    insert_data( matrice, row, col );
}

#endif //ALGGAUSS_GBLFUN_H
