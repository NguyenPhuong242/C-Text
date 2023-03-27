#include "Line.h"
#include <assert.h>
#include <string.h>

void Line_clean(Line line)
{
    free(line.chars);
}

Line Line_read(FILE *file, size_t initialCapacity)
{
    assert(1 <= initialCapacity);
    size_t capacity = initialCapacity, length = 0;
    char *chars = malloc(capacity);
    assert(chars != NULL);
    for (;;)
    {
        int character = fgetc(file);
        if(character == EOF) break;
        if (length == capacity - 1)
        {
            size_t newCapacity = 2 * capacity;
            printf("line_a\n");
            char * newChars = realloc(chars, newCapacity);
            assert(newChars != NULL);
            chars = newChars;
            capacity = newCapacity;
        }
        chars[length] = character;
        length++;
        if (character == '\n')
            break;
    }
    chars[length] = '\0';
    printf("line_b\n");
    chars = realloc(chars, length+1);
    return (Line)
    {
        .chars = chars,
        .length = length,
    };
}

bool Line_isEnd(Line line)
{
    return line.length == 0;
}

bool Line_endsWithNL(Line line)
{
    return line.chars[line.length - 1] == '\n' && line.length != 0;
}

bool Line_startsWithNL(Line line)
{
    return line.length == 1 && line.chars[0] == '\n';
}


char *Line_findString(Line line, char const string[])
{
    char *start = line.chars;
    for (;;)
    {
        char *found = strstr(start, string);
        if (found)
            return found;
        char *zero = strchr(start, '\0');
        if (zero == line.chars + line.length)
            return NULL;
        start = zero + 1;
    }
}

char *Line_findNthString(Line line, char const string[], int nth)
{
    if (nth <= 0)
        return NULL;
    int length = strlen(string);
    char *start = line.chars;
    int count = 0;
    for (;;)
    {
        char *found = strstr(start, string);
        if (found)
            count++;
        if (count == nth)
            return found;
        if (found)
        {
            start = found + length;
            continue;
        }
        char *zero = strchr(start, '\0');
        if (zero == line.chars + line.length)
            return NULL;
        start = zero + 1;
    }
}