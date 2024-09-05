#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static void fputs(const char * str);
static int fstrchr(const char * str, int find);
static int fstrlen(const char * str);
char * fstrcpy(char * destptr, const char * srcptr);
char * fstrncpy(char * destptr, const char * srcptr, size_t n);
char * strcat(char * destptr, const char * srcptr);
char * strncat(char * destptr, const char * srcptr, size_t n);
char * fgets(char * string, int num);
char * fstrdup(const char * string);

int main()
{
    const char * str = "Hello";

    fputs(str);

    int find = 'e';
    int pos_el = fstrchr(str, 'e');
    printf("Элемент %c находится на месте %d \n", (char) find, pos_el);

    int len  = fstrlen(str);
    printf ("Длинна введённой строки %d \n", len);

    char ff[] = "cтрока для вставки";

    fstrcpy(ff, str);
    fputs(ff);

    char nff[] = "abcfgghkjjhjhjhjh";            //Вопрос в комите 1 
    fstrncpy(nff, str, 3);
    puts(nff);                                

    strncat(nff, str, 5);
    fputs(nff);

    printf("\n");                               //Вопрос в комите 1
    fgets(nff, 2);                            
    fputs(nff);

    fputs(fstrdup(str));                        //Почему нет ошибки на аргумент

    return 1;
}

static void fputs(const char * str)
{
    assert(str);

    printf("%s \n", str);
}

static int fstrchr(const char * str, int find)
{
    assert (str);

    int i = 0;

    while(1)
    {
        int x = (int) * (str + i);
        i ++;

        if (x == 0)
        {
            return -1;
        }

        else if (x == find)
        {
            return i;
        }
    }
}

static int fstrlen(const char * str)
{
    assert (str);

    int i = 0;
    int x = -1;

    while(x != 0)
    {
        x = (int) * (str + i);
        i++;
    }
    return i - 1;
}

char * fstrcpy(char * destptr, const char * srcptr)
{    
    assert (destptr);
    assert (srcptr);

    int len_srcpt = fstrlen(srcptr);

    for (int i = 0; i <= len_srcpt; i++)
    {
        *(destptr + i) = *(srcptr + i);                             
    }
    return destptr;
}

char * fstrncpy(char * destptr, const char * srcptr, size_t n)
{    
    assert (destptr);
    assert (srcptr);

    size_t len_srcpt = fstrlen(srcptr);

    for (size_t i = 0; (i <= len_srcpt) && (i + 1 <=  n); i++)
    {
        *(destptr + i) = *(srcptr + i);
        if (i + 1 == n)
        {
            *(destptr + i + 1) = (char) 0;
        }
    }
    return destptr;
}

char * strcat(char * destptr, const char * srcptr)
{    
    assert (destptr);
    assert (srcptr);

    char * test_destptr = destptr;
    int len_destptr = fstrlen(test_destptr);

    fstrcpy(destptr + len_destptr, srcptr);
    return destptr;
}

char * strncat(char * destptr, const char * srcptr, size_t n)
{    
    assert (destptr);
    assert (srcptr);

    char * test_destptr = destptr;
    int len_destptr = fstrlen(test_destptr);

    fstrncpy(destptr + len_destptr, srcptr, n);
    return destptr;
}

char * fgets(char * string, int num)
{
    assert (string);

    char * buf_string = (char *) calloc(num, sizeof(char));

    scanf("%s", buf_string);
    fstrcpy(string, buf_string);                                 //Почему не выдаёт ошибку на второй аргумент

    free(buf_string);
    return string;
}

char * fstrdup(const char * string)
{
    assert (string);

    char * buf_string = (char *) calloc(fstrlen(string) + 1, sizeof(char));

    fstrcpy(buf_string, string);                                
    return buf_string;
}