#include "../internal/internal.h"

int vsnprintf(char *str, size_t lim, const char *fmt, va_list argptr)
{
	int ret = 0;
	ret = _printf_inter(NULL, str, lim, 2, fmt, argptr);
	va_end(argptr);
	return ret;
}
