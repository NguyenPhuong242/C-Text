#include "Line.h"
#include "Content.h"
#include "TextUtil.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
size_t TextUtil_runNlOnFile (FILE * file, size_t numStart, size_t numStep, bool skipEmpty, FILE * output){
    size_t num = numStart;//soit num = numStart
    for(;;){
        Line line = Line_read (file, 2);
        if(Line_isEnd(line)){
            Line_clean(line);
            break;
        }
        bool skipLine = skipEmpty && Line_startsWithNL(line);
        if(skipLine){
            fprintf(output, "\n");
            Line_clean(line);
            continue;
        }

        fprintf(output, "%6zu\t", num);
        Line_print(line, output);
        if(!Line_endsWithNL(line)){
            fprintf(output, "\n");
        }
        Line_clean(line);
        num += numStep;
    }
    return num; 
};

int TextUtil_runNl (int argc, char * argv[], FILE * output){

};
