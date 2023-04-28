//
// Created by andrew-drink on 28/04/23.
//

#ifndef ALGGAUSS_FUNSTR_H
#define ALGGAUSS_FUNSTR_H

string sanitize_str( string s, int i ) {
    if ( s.empty() )
        throw (string)"Empty string";

    if ( s.at(i) == ' ' )
        return sanitize_str( s, i++ );
    else
        return s.substr( i, s.length() );
}

string fstr( string s, int i, int f ) {
    switch (f) {
        case 1: {
            // string tmp = "";
            int c = 0;
            Razionale r = Razionale();
            if ( s.at(i) == '(' ) {
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
            }
        }

    }
}

#endif //ALGGAUSS_FUNSTR_H
