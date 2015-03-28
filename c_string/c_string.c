#include <stdio.h>
#define __USE_GNU
#include <string.h>


void c_string(void)
{
    /* char *strstr(const char *haystack, const char *needle);
     * char *strcasestr(const char *haystack, const char *needle);
     * haystack 大海捞针般寻找，needle 针
     * strstr 在haystack中寻找第一次出现needle的substr返回其指针，如果找不到返回NULL
     * strcasestr与strstr类似，但是忽略大小写
     *
     * */
    char *haystack = "abcdefghabcdddd";
    char *needle = "cd";
    char *substr = strstr(haystack, needle);

    printf("substr=%s \n", substr);

    substr = strcasestr("abcdedcdddddd", "CD");
    //substr = strcasestr(haystack, needle);

    printf("substr=%s \n", substr);

    /*size_t strspn(const char *s, const char *accept);
     *size_t strcspn(const char *s, const char *reject);
     *
     *
     * */

    size_t len = strspn("cdefghhhh111", "cdefg");
    printf("len=%lu\n", len);

    len = strcspn("abcdefgh", "cde");
    printf("len=%lu\n", len);
}

int main(int argc, char *argv[])
{

    c_string();

    return 0;
}
