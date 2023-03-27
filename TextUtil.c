#include "Line.h"
#include "Content.h"
#include "TextUtil.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// size_t TextUtil_runNlOnFile (FILE * file, size_t numStart, size_t numStep, bool skipEmpty, FILE * output){
//     size_t num = numStart;//soit num = numStart
//     for(;;){
//         Line line = Line_read (file, 2);
//         if(Line_isEnd(line)){
//             Line_clean(line);
//             break;
//         }
//         bool skipLine = skipEmpty && Line_startsWithNL(line);
//         if(skipLine){
//             fprintf(output, "\n");
//             Line_clean(line);
//             continue;
//         }

//         fprintf(output, "%6zu\t", num);
//         Line_print(line, output);
//         if(!Line_endsWithNL(line)){
//             fprintf(output, "\n");
//         }
//         Line_clean(line);
//         num += numStep;
//     }
//     return num; 
// }

// int TextUtil_runNl (int argc, char * argv[], FILE * output){
//     int status = 0;
//     size_t start = atoi (argv[2]);
//     size_t step = atoi (argv[3]);
//     bool skipEmpty = strcmp(argv[4], "skip") == 0;
//     size_t num = start;
//     if(argc == 1+4){
//         num = TextUtil_runNlOnFile(stdin, num, step, skipEmpty, output);
//         return status;
//     }

//     for(int k = 5; k < argc; k++){
//         bool isDash = (strcmp(argv[k], "-") == 0);
//         char * filename = isDash ? "/dev/fd/0" : argv[k];
//         FILE * file = fopen(filename, "r");
//         if(file == NULL){
//             fprintf(stderr, "error: could not open file '%s'\n", filename);
//             status++;
//             continue;
//         }
//         num = TextUtil_runNlOnFile(file, num, step, skipEmpty, output);
//         fclose(file);
//     }
//     return status;

// }



