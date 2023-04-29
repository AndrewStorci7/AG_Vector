//
// Created by sandr on 29/03/2023.
//

int findChar( string );

class Razionale {
private:
    int n;
    char sep;
    int d;

public:

    /**
     * Default constructor
     */
    Razionale() {
        n   = 0;
        sep = '/';
        d   = 1;
    }

    /**
     * Constructor
     * @param n Numeratore
     * @param d Denominatore
     */
    Razionale( int n, int d ) {

        if ( d == 0 )
            throw (string)"den-zero";

        this->n = n;
        this->d = d;
        /*
        if ( n >= d ) {
            if ( n % d == 0 ) {
                this->n = n / d;
                this->d = d / d;
            } else {
                this->n = n;
                this->d = d;
            }
        } else {
            if ( d % n == 0 ) {
                this->n = d / n;
                this->d = n / n;
            } else {
                this->n = n;
                this->d = d;
            }
        }*/
        sep     = '/';
    }

    /**
     * Constructor for inline-command
     * @param s
     */
    Razionale( string s ) {
        bool den = false;
        int d = 0;
        for ( int i = 0; i < s.length(); i++ ) {
            if ( s.at(i) == '/' ) {
                if ( (i - 1) == 0 )
                    this->n = (int)s.at( 0 ) - 48;
                else
                    this->n = stoi( s.substr( 0, i ) );
                den = true;
                d = ++i;
                break;
            }
        }

        if ( den ) {
            int check = ( d == ( s.length() - 1 ) ) ? (int)s.at(d) - 48 : stoi( s.substr( d ) );
            if ( check == 0 )
                throw (string)"den-zero";

            this->d = check;
        } else {
            int check = ( ( s.length() - 1 ) == 0 ) ? (int)s.at(0) - 48 : stoi( s );
            this->n = check;
            this->d = 1;
        }

        this->sep = '/';
    }

    /**
     * Constructor with only one parameter
     * @param n Numeratore
     */
    Razionale( int n ) {
        this->n = n;
        this->d = 1;
        sep     = '/';
    }

    // getter and setter
    void setN( int n ) { this->n = n; }
    void setD( int d ) { this->d = d; }
    int getN() { return this->n; }
    int getD() { return this->d; }

    Razionale operator+( const Razionale& o ) {
        Razionale r;
        r.d = ( o.d == this->d ) ? o.d : this->d * o.d;
        r.n = ( ( r.d / this->d ) * this->n ) + ( ( r.d / o.d ) * o.n );
        return r;
    }

    Razionale operator-( const Razionale& o) {
        Razionale r;
        r.d = ( o.d == this->d ) ? o.d : this->d * o.d;
        r.n = ( ( r.d / this->d ) * this->n ) - ( ( r.d / o.d ) * o.n );
        return r;
    }

    template <typename T>
    Razionale operator*( const T& o ) {
        Razionale ret;
        int num = 0, den = 0;
        if ( is_same<T, int>::value ) {
            num = o * this->n;
            ret = Razionale( num );
            return ret;
        } else if ( is_same<T, Razionale>::value ) {
            num = this->n * o.n;
            den = this->d * o.d;
            ret = Razionale( num, den );
            return ret;
        }
    }


    /*Razionale operator=(const Razionale& o ) {
        Razionale ret = Razionale( o.n, o.d );
        return ret;
    }
    */


};

inline int findChar( string s ) {
    for ( int i = 0; i < s.length(); i++ )
        if ( s.at(i) == '/')
            return i;
    return 0;
}

ostream& operator<<( ostream& dest, Razionale& o ) {
    dest << o.getN() << '/' << o.getD() << endl;
    return dest;
}

istream& operator>>( istream& serc, Razionale& o ) {
    try {
        string s = "";
        serc >> s;
        if ( !s.empty() )
            o = Razionale( s );
    } catch ( string e ) {
        cout << e << ": il denominatore non può essere zero\n";
    }

    return serc;
}

/*ostream& operator<<( ostream& dest, Razionale& o ) {
    dest << o.getN() << '/' << o.getN() << endl;
    return dest;
}*/

/*std::ostream& operator>>( std::ostream& dest, Razionale o ) {
    dest << o.getN() << '/' << o.getN() << std::endl;
    return dest;
}*/
