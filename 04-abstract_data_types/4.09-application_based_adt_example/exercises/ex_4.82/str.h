#ifndef STR_H
#define STR_H

typedef struct String *str;

str str_create(char*);
int str_comp(str, str);
str str_concat(str, str);
str str_copy(str, str);
int str_len(str);
void str_print(str);

#endif
