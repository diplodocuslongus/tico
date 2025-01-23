#include <stdio.h>
#include <unistd.h>

void parse_arguments(int argc,
                     char* argv[],
                     unsigned int* rate,
                     unsigned int* bph,
                     unsigned int* evalue,
                     unsigned int* zoom,
                     unsigned int* time,
                     unsigned int* everyline,
                     unsigned int* cvalue,
                     unsigned int* verbose,
                     unsigned int* fitN,
                     unsigned int* teeth,
                     double* SDthreshold,
                     char** device,
                     FILE** fpposition,
                     FILE** fpmaxcor,
                     FILE** fptotal,
                     FILE** fpDefPeak,
                     FILE** fpInput);
