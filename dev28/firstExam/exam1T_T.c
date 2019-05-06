#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct 
{
    char** array;
    size_t size;
} string_list;

////////// String Builder
typedef struct
{
    char* string;
    size_t length;
} string_builder;

void sb_init(string_builder* sb)
{
    sb->string = (char*)malloc(0);
    sb->length = 0;
};

size_t calculate_size(const char* a)
{
    const char* orig = a;
    while (*a)
    {
        a++;
    }
    return a - orig;
}

void sb_add_str(string_builder* sb, const char* s)
{
    size_t n = calculate_size(s);
    sb->string = (char*) realloc(sb->string, sizeof(char*)*((sb->length) + n + 1));
    memcpy(sb->string + sb->length, s, n + 1);
    sb->length += n;
};
void sb_add_char(string_builder* sb,const char c)
{
    sb->string = (char*) realloc(sb->string, sizeof(char*)*((sb->length) +  2));
    sb->string[sb->length] = c;
    sb->string[sb->length+1] = '\0';
    sb->length ++;
}

void sb_release(string_builder* sb)
{
    free(sb->string);
    sb->length = 0;
};
//////////


void sl_init(string_list* sl)
{
    sl->array = malloc(0);
    sl->size = 0;
}

size_t sl_size(const string_list* sl)
{
    return sl->size;
}

void sl_add(string_list* sl, const char* s)
{
    size_t len = calculate_size(s);
    sl->array = (char**) realloc(sl->array, sizeof(char**)*(sl->size+1));
    sl->array[sl->size] = (char*)malloc(sizeof(char)* len+1);
    memcpy(sl->array[sl->size], s, len+1);
    sl->size++;
}

void split_words(string_list* sl, const char* word)
{
    string_builder aux;
    sb_init(&aux);
    while (*word)
    {
        if(*word != ' ' )
        {
            if (*word !=',')
            {
                sb_add_char(&aux, *word);
            }
        } else
        {
            sl_add(sl, aux.string);
            sb_release(&aux);
            sb_init(&aux);
        }
        word++;
    }
    if(aux.length > 0)
    {
        sl_add(sl, aux.string);
        sb_release(&aux);
    }
}

char* sl_string_at(const string_list* sl, size_t position)
{
    return sl->array[position];
}

void sl_release(string_list* sl)
{
    for (size_t i = 0; i < sl->size; i++)
    {
        free(sl->array[i]);
    }
    free(sl->array);
}

void sl_populate(string_list* sl, size_t n, ...)
{
    va_list args;
    va_start(args, n);
    for (size_t i = 0 ; i < n; i++)
    {
        sl_add(sl, va_arg(args, const char*));
    }
    va_end(args);
}

void sl_join(string_list* sl, const char* sep, char* a)
{
    string_builder sb;
    sb_init(&sb);
    for (size_t i = 0; i < sl->size; i++)
    {
        sb_add_str(&sb, sl->array[i]);
        if (i != sl->size-1)
        {
            sb_add_str(&sb, sep);
        }
    }
    sprintf(a,"%s", sb.string);
    sb_release(&sb);
}

void sl_copy_if(string_list* sl_a, const string_list* sl_b, int(*comp)(const char*))
{  
    for (size_t i = 0; i < sl_b->size; i++)
    {
        if(comp(sl_b->array[i]))
        {
            sl_add(sl_a, sl_b->array[i]);
        }
    }
}

void sl_transform(string_list* sl, char* (*lower)(const char*))
{
	for (size_t i = 0; i < sl->size; i++)
    {
        char * aux = lower(sl->array[i]);
		sl->array[i] = aux;
        sb_release(&aux);
    }
}

void sl_reverse(string_list* sl)
{
	for (size_t i = 0 ; i < ((sl->size / 2)); i++)
    {
		char* aux = sl->array[i];
        sl->array[i] = sl->array[sl->size-i-1];
        sl->array[sl->size-i-1] = aux;
	}
}

void sl_iterate_with_param(string_list* sl, int (*accum)(const char*), int* sum)
{
    for(size_t i = 0; i < sl->size; i++)
    {
        *sum += accum(sl->array[i]);   
    }
}

void sl_insert_at(string_list* sl, size_t n, const char* s)
{
    string_list aux;
    sl_init(&aux); 
    for(size_t i = 0; i < sl->size; i++)
    {
        sl_add(&aux, sl->array[i]);
    }
    sl_release(sl);
    sl_init(sl);
    for(size_t i = 0; i < aux.size; i++)
    {
        if( i == n)
        {
            sl_add(sl, s);
        }
        sl_add(sl, aux.array[i]);
    }
    sl_release(&aux);
}



/**
 * Punteros a funcion faltantes
 */

int word_ends_with_o(const char* s)
{
    size_t len = strlen(s);
    return s[len-1] == 'o';
}

char* str_to_lower_case(const char* s)
{
	string_builder sb;
    sb_init(&sb);
	while(*s)
	{
		if(*s < 96 && *s > 64 )
		{
			sb_add_char(&sb, *s+32);
		}else
		{
			sb_add_char(&sb, *s);
		}
		s++;
	}
    return sb.string;
}

int accum(const char* s)
{
    int a;
    sscanf(s, "%d", &a);
    return a;
}

/**
 * funciones extra
 */
void to_string(char* container, int i)
{
    sprintf(container, "%d", i);
}

// Write your code here

typedef bool (*PTEST)();

bool test0()
{
        const char* text = "Today, Microsoft announced that it is releasing the May 2019 Update to the Release Preview ring, and it is available now";

        string_list words;
        sl_init(&words);

        split_words(&words, text);

        size_t size = sl_size(&words);

        bool result = size == 21
             && strcmp(sl_string_at(&words, 0), "Today") == 0
                 && strcmp(sl_string_at(&words, 20), "now") == 0
                 && strcmp(sl_string_at(&words, 15), "ring") == 0;

        sl_release(&words);
        return result;
}

bool test1()
{
        string_list words;
        sl_init(&words);
        sl_populate(&words, 10, "Viviana", "Pamela", "Dennis", "Juan", "Alfonso", "Janet", "Jorge", "Rodrigo", "Mauro", "Julia");

        char aux[200];
        sl_join(&words, ", ", aux);

        bool result = strcmp(aux, "Viviana, Pamela, Dennis, Juan, Alfonso, Janet, Jorge, Rodrigo, Mauro, Julia") == 0;
        sl_release(&words);

        return result;
}

bool test2()
{
        string_list words;
        sl_init(&words);
        sl_populate(&words, 5, "Pedro", "Pablo", "Jose", "Maria", "Alvaro");

        string_list filtered_words;
        sl_init(&filtered_words);
        sl_copy_if(&filtered_words, &words, word_ends_with_o);
		
        char aux[100];
        sl_join(&filtered_words, " ", aux);
		
        bool result = strcmp(aux, "Pedro Pablo Alvaro") == 0;

        sl_release(&words);
        sl_release(&filtered_words);

        return result;
}

bool test3()
{
        string_list words;
        sl_init(&words);

        sl_populate(&words, 6, "MI", "nombre", "es", "JUANA AZURDUY", "de", "Padilla");
        sl_transform(&words, str_to_lower_case);

        char aux[100];
        sl_join(&words, " ", aux);

        bool result = strcmp(aux, "mi nombre es juana azurduy de padilla") == 0;
        sl_release(&words);

        return result;
}

bool test4()
{
        string_list words;
        sl_init(&words);

        sl_populate(&words, 7, "MI", "NOMBRE", "es", "Juana", "Azurduy", "de", "Padilla");
        sl_transform(&words, str_to_lower_case);

        char aux[100];
        sl_join(&words, " ", aux);

        bool result = strcmp(aux, "mi nombre es juana azurduy de padilla") == 0;
        sl_release(&words);

        return result;
}

bool test5()
{
        string_list words;
        sl_init(&words);

        sl_populate(&words, 11, "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez", "once");
        sl_reverse(&words);

        char aux[200];
        sl_join(&words, ".- ", aux);

        bool result = strcmp(aux, "once.- diez.- nueve.- ocho.- siete.- seis.- cinco.- cuatro.- tres.- dos.- uno") == 0;
		
        sl_release(&words);

        return result;
}

bool test6()
{
        string_list numbers;
        sl_init(&numbers);

        for (int i = 0; i < 100; i++)
        {
                char aux[20];
                to_string(aux, i);
                sl_add(&numbers, aux);
        }

        int sum = 0;
        sl_iterate_with_param(&numbers, accum, &sum);

        bool result = sum == 4950;

        sl_release(&numbers);
        return result;
}

bool test7()
{
        string_list words;
        sl_init(&words);

        sl_populate(&words, 4, "tres", "cuatro", "cinco", "seis");
        sl_add(&words, "ocho");
        sl_insert_at(&words, 0, "dos");
        sl_insert_at(&words, 0, "uno");
        sl_insert_at(&words, 6, "siete");

        char aux[100];
        sl_join(&words, ".", aux);

        bool result = strcmp(aux, "uno.dos.tres.cuatro.cinco.seis.siete.ocho") == 0;
        sl_release(&words);
        return result;
}


int main()
{
        PTEST tests[] = { test0, test1, test2, test3, test4, test5, test6, test7 };

        int score = 0;
        for (size_t i = 0; i < 8; i++)
        {
                printf("Running test%d\n", (int) i);
                score += tests[i]() ? 1 : 0;
        }

        printf("Final score: %d / 8\n", score);
        return 0;
}
