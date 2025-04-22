/// @defgroup cli cli
/// @ingroup lib
/// @brief CLI: Command Line Interface
/// @{

/// @brief interpret file
extern void cli(char* filename);

extern char* yyfile;  ///< current file/stream name
extern int yylineno;  ///< current line number
extern int yyin;      ///< script file handler

/// @}
