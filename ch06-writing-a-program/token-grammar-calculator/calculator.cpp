#include "../../std_lib_facilities.h"

/*
Grammar: 
    Expression:
        Term
        Term '+' Expression
        Term '-' Expression

    Term:
        Primary
        Term '*' Primary
        Term '/' Primary
        Term '%' Primary

    Primary:
        Number
        '(' Expression ')'

    Number:
        float point literal
*/

class Token {
    public:
        char kind;
        double value;
};

class Token_stream {
    public:
        Token get();            // get a Token
        void putback(Token t);  // put a Token back to stream
    private:
        bool full{false};       // indicate if there is a token in buffer
        Token buffer;           // keep the token we put back
};

double expression();
double term();
double primary();

Token_stream ts;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
int main() {
    try {
        double val = 0;
        while(cin) {
            Token t = ts.get();

            if(t.kind == 'q')
                break;
            if(t.kind == ';')
                cout << "=" << val << "\n";
            else
                ts.putback(t);
            val = expression();
        }
    } catch(exception &e) {
        cerr << e.what() << "\n";
        return 1;
    } catch(...) {
        cerr << "exception \n";
        return 2;
    }
    return 0;
}

double expression() {
    double left = term();
    Token t = ts.get();

    while(true) {
        switch(t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double term() {
    double left = primary();
    Token t = ts.get();

    while(true) {
        switch(t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if(d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }    
            default:
                ts.putback(t);
                return left;
        }
    }
}

double primary() {
    Token t = ts.get();
    switch(t.kind) {
        case '(':   // handles '(' Expression ')'
            {
                double d = expression();
                t = ts.get();
                if(t.kind != ')') error("')' expected");
                return d;
            }
        case '8':
            return t.value;
        default:
            error("primary expected");
    }
    return 0;
}

Token Token_stream::get() {
    if(full) {
        full = false;
        return buffer;
    }
    
    char ch;
    cin >> ch;

    switch(ch) {
        case ';':
        case 'q':
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            cin.putback(ch);
            double value;
            cin >> value;
            return Token{'8', value};
        default:
            error("bad token");    
    }
    return Token{};
}

void Token_stream::putback(Token t) {
    if(full) error("putback() into a full buffer");
    buffer = t;
    full = true;
}