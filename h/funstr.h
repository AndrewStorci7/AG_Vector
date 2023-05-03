//
// Created by andrew-drink on 28/04/23.
//

#ifndef ALGGAUSS_FUNSTR_H
#define ALGGAUSS_FUNSTR_H
int A[30] = {};
int __index = 0; // global index for A[]
Vector* __V = new Vector[100]; // global array of vectors

string fstr(string, int, int);

string sanitize_str(string s, int i ) {
    if ( s.empty() )
        throw (string)"Empty string";

    if ( s.at(i) == ' ' )
        return sanitize_str( s, i++ );
    else
        return s.substr( i, s.length() );
}

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
    // cout << ss << endl;
    int f = 0;
    if ( ss == "-h" || ss == "-H" || ss == "--help" )
        __help();

    if ( ss.at(i) == '|' && ss.at(i + 1) == '|' ) {
        f = 1;
    } else if ( ss.at(i) == 'p' && ss.at(i + 1) == 'r' ) {
        f = 2;
    } else if ( ss.at(i) == '<' ) {
        f = 3;
    } else if ( ss.at(i) == '(' ) {
        f = 4;
        /*if ( ss.at(i + 1) == '(' ) {

        } else {
            string tmp = "";
            for ( int k = 0; k <  )
        }*/
    }

    // A[__index] = f;
    // __index++;
    // cout << __index << endl;
    // cout << A[__index - 1 ] << endl;
    try {
        fstr( ss, i, f);
    } catch( string e ) {
        cout << e << endl;
    }
    // cout << fstr( ss, i, f) << endl;
}

// TODO: finire funzione per controllo comando
string fstr( string s, int i, int f ) {
    switch (f) {
        case 1: {
            // string tmp = "";
            int c = 0;
            Razionale r = Razionale();
            //do_command();
            /*if ( s.at(i) == '(' ) {
                // check if the vector is written manually
                for ( int j = i + 1; j < s.length(); j++ ) {
                    if ( s.at(j) == ')' )
                        break;
                    if ( s.at(j) != ',' ) {
                        // substr of the first number :: x1, x2, x3
                        c = j;
                    } else {

                    }
                }
            } else if ( s.at(i) == '<' ) {
                // check if it's a scalar product
            } else {
                // Check into the array
            }*/
        }
            break;
        case 2: {
            string num = "";
            int __indexRaz = 0;

            if ( s.at(i + 2) == '(' ) {
                if ( s.at(i + 3) == '(' ) {
                    Razionale* __raz = new Razionale[10];
                    for ( int k = i + 4; i < s.length(); k++ ) {
                        if ( s.at(k) == ',' || s.at(k) == ')' ) {
                            num = s.substr(i+4, k - 1);
                            Razionale tmp = Razionale( num );
                            __raz[__indexRaz] = tmp;
                            __indexRaz++;
                        }
                    }
                    Vector v = Vector( __indexRaz + 1, __raz );
                }
            } else if ( s.at(i + 2) == '(' && s.at(i + 3) == ')' )
                throw (string)"Empty fun";
        }
            break;
        case 3: {

        }
            break;
        case 4: {

        }
            break;

    }
}

#endif //ALGGAUSS_FUNSTR_H
