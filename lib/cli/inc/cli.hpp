/// @defgroup cli cli
/// @ingroup lib
/// @brief CLI: Command Line Interface
/// @{

/// @brief interpret file
extern void clif(char* filename);

/// @brief interpret string
extern void clis(char* str);

/// @brief interpret memory buffer
extern void cli(char* p, char* pe);

extern char* yyfile;             ///< current file/stream name
extern int yylineno;             ///< current line number
extern int yyin;                 ///< script file handler
extern void yyerror(char* msg);  ///< syntax error callback

/// @}
