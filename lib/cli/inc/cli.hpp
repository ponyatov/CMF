/// @defgroup cli cli
/// @ingroup lib
/// @brief CLI: Command Line Interface
/// @{

/// @brief interpret file
extern void clif(char *filename);

/// @brief interpret string
extern void clis(char *str);

/// @brief interpret memory buffer
/// @param[in] p  lexer pointer (current position)
/// @param[in] pe lexer end pointer (end of data)
extern void cli(char *p, char *pe);

extern char *yyfile;             ///< current file/stream name
extern int yylineno;             ///< current line number
extern int yyin;                 ///< script file handler
extern void yyerror(char *msg);  ///< syntax error callback

/// @name token conversion
/// @{
extern int dec(char *ts, char *te);    ///< decimal integer token
extern int hex(char *ts, char *te);    ///< hexadecimal token
extern int oct(char *ts, char *te);    ///< octal
extern int bin(char *ts, char *te);    ///< binary
extern float num(char *ts, char *te);  ///< floating point
/// @}

#include <string>

using namespace std;

#define Dsz 0x10

class Object {
    string value;
    size_t ref;

   public:
    Object();
    Object(string V);
    ~Object();
    virtual string val();
};

class Int : public Object {
    int value;
    public:
    Int(int n);
    string val();
};

extern Object *D[Dsz];
extern size_t Dp;

extern void push(Object *o);
extern void push(int n);

/// @}
