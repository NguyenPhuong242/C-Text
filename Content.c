#include "Content.h"
#include <assert.h>
#include <errno.h>

Content Content_read(FILE * file, size_t initialCapacity){
    assert(initialCapacity >= 1);
    size_t capacity = initialCapacity, count = 0;
    Line * lines = malloc (capacity * sizeof * lines);
    /*Line * lines= malloc(capacity * sizeof(Line))*/
    assert(lines!=NULL);
    for(;;){
        Line line = Line_read(file, 80);
        if(count == capacity){
            size_t newCapacity = 2 * capacity;
            /*Line * newLines = realloc(lines, newCapacity * sizeof * lines);*/
            Line * newLines = realloc(lines, newCapacity * sizeof(Line));
            assert(newLines != NULL);
            lines = newLines;
            capacity = newCapacity;
        }
        lines[count]= line; count++;
        if(Line_isEnd(line)) break;
    }
    /*lines = realloc (lines, count * sizeof * lines);*/
    lines = realloc(lines, count * sizeof(Line));
    if (lines == NULL){
        if (errno == ENOMEM)
            printf("nomem\n");
            else
            printf("other\n");
    }
    return (Content){
        .lines = lines, 
        .lineCount = count-1, 
    };
}

void Content_clean(Content content){
    for(size_t k = 0; k <= content.lineCount; k++){
        Line_clean(content.lines[k]);
    }
    free(content.lines);
}
