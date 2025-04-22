#include "os.hpp"
#include "cli.hpp"

char* yyfile = nullptr;
int yylineno = 0;
int yyin = 0;

void clis(char* str) { cli(str, str + strlen(str)); }

void yyerror(char* msg) {
    fprintf(stderr, "\n\n%s:%i %s\n\n", yyfile, yylineno, msg);
    exit(-1);
}

Object* D[Dsz];
size_t Dp = 0;

Object::Object() { ref = 0; }

string Object::val() { return value; }

Int::Int(int n) : Object() { value = n; }

string Int::val() {
    ostringstream os;
    os << value;
    return os.str();
}

void push(Object* o) {
    assert(Dp < Dsz);
    D[Dp++] = o;
}
void push(int n) { push(new Int(n)); }
