#include "cli.hpp"
#include <string.h>

char* yyfile = nullptr;
int yylineno = 0;
int yyin = 0;

void cli(char* str) { cli(str, str + strlen(str)); }
