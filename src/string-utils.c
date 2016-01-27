#define IN_STRING_UTILS_C_
#include "string-utils.h"

char* string_trim_right(char* str)
{
	char* end = str + strlen(str) - 1;
	while (str < end && isspace(*end))
		*end-- = '\0';
	return str;
}

char* string_keep_if(int (*cond)(int c), char* str)
{
	size_t i, k = 0;
	for (i = 0; str[i]; ++i) {
		int c = str[i];
		if (cond(c))
			str[k++] = c;
	}
	str[k] = '\0';
	return str;
}

int string_ends_with(const char* cmp, const char* str)
{
	size_t cmp_len = strlen(cmp);
	size_t str_len = strlen(str);

	if (cmp_len > str_len)
		return 0;

	return strcmp(str + str_len - cmp_len, cmp) == 0;
}

char* string_tolower(char* str)
{
	char* ptr = str;
	while (*ptr) {
		*ptr = tolower(*ptr);
		++ptr;
	}
	return str;
}

char* string_replace_char(char m, char r, char* str)
{
	char* ptr = str;
	for (; *ptr; ++ptr)
		if (*ptr == m)
			*ptr = r;
	return str;
}
