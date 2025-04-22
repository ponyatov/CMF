#include "os.hpp"
#include "cli.hpp"

void clif(char* filename) {
    yyfile = filename;
    yylineno = 1;
    // open
    assert((yyin = open(yyfile, O_RDONLY)));
    // get host memory spec
    int pagesize = 0;
    assert((pagesize = getpagesize()) == 4096);
    // get file size
    struct stat st;
    assert(0 == fstat(yyin, &st));
    char* buf = (char*)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, yyin, 0);
    assert(buf);
    // parse
    cli(buf, buf + st.st_size);
    // close file
    munmap(buf, pagesize);
    close(yyin);
    yyin = 0;
    yyfile = nullptr;
    yylineno = 0;
}
