#include <unistd.h>
#include "syscall.h"

int rename(const char *o, const char *n)
{
#ifdef SYS_rename
	return syscall(SYS_rename, o, n);
#else
	return syscall(SYS_renameat, AT_FDCWD, o, n);
#endif
}

