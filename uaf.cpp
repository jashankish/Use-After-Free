#include "standardizedHeader"

#define BUFSIZER1   512
#define BUFSIZER2   ((BUFSIZER1/2) - 8)

int main(int argc, char **argv) {
    
    // Define 4 different pointers
    char *buf1R1;
    char *buf2R1;
    char *buf2R2;
    char *buf3R2;

    // Two blocks each with size = 512
    buf1R1 = (char *) malloc(BUFSIZER1);
    buf2R1 = (char *) malloc(BUFSIZER1);

    // Free the second one
    free(buf2R1);

    // Two block each with size = 248 (256-8)
    buf2R2 = (char *) malloc(BUFSIZER2);
    buf3R2 = (char *) malloc(BUFSIZER2);

    // Fuction inputs: char * strncpy ( char * destination, const char * source, size_t num );
    // Copy input (argv[1]) to original (deleted) block with size = one less than size of original
    strncpy(buf2R1, argv[1], BUFSIZER1-1);
    
    // Free the remaining blocks
    free(buf1R1);
    free(buf2R2);
    free(buf3R2);
}
