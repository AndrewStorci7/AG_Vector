//
// Created by sandr on 29/03/2023.
//

#ifndef ALGGAUSS_GBLFUN_H
#define ALGGAUSS_GBLFUN_H
#include "funstr.h"
string p = "\n> ";  // Pre-content line
string str;         // Line-command

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

/*
 * OLD FUNCTION start()
 *

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
*/

/**
 * __help()
 * Manual ...
 */
void __help() {
    string quit;
    do {
        cout << "\nYou asked for help ?\n There I am\n";
        cin >> quit;
    } while( quit == "q" || quit == "Q" || quit == "QUIT" || quit == "quit" );
}

/**
 * Main function
 * @param s
 */
void do_command( string s, int i ) {
    string ss;
    try {
        ss = sanitize_str( s, 0 );
    } catch( string e ) {
        cout << e << ": stringa vuota\n";
    }
    cout << ss << endl;
    int f = 0;
    if ( ss == "-h" || ss == "-H" || ss == "--help" )
        __help();

    if ( ss.at(i) == '|' && ss.at(i + 1) == '|' ) {
        f = 1;

    } else if ( ss.at(i) == 'p' && ss.at(i + 1) == 'r' )
        f = 2;
    else if ( ss.at(i) == '<' )
        f = 3;

    cout << f << endl;
    // fstr( f, i);
}

void start() {
    string pre = "Welcome !\n This program can calculate:\n\t- Scalar product\n\t- Vectorial product\n\t- Proiection of a Vector (r^n)\n\nIf you need help type \"-h\" or \"-H\" or \"--help\" ";
    cout << pre;
    bool valid = false;
    while ( !valid ) {
        try {
            cout << p;
            cin >> str;
            do_command( str, 0 );
        } catch( string e ) {
            cout << e << endl;
            valid = false;
        }

    }
}
#endif //ALGGAUSS_GBLFUN_H
