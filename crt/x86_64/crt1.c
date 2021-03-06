extern int __attribute__((__weak__)) (*main)(int, char **, char **);
int  __attribute__((__weak__)) _init(int, char **, char **);
void __attribute__((__weak__)) _fini(void);

int __attribute__((__noreturn__)) __libc_start_main(
	int (*main)(int, char **, char **), int argc, char **argv,
	int (*init)(int, char **, char **), void (*fini)(void),
	void (*ldso_fini)(void));

void _start(void)
{
	register int (*__main)(int, char **, char **) __asm__("rdi");
	register long __argc                          __asm__("rsi");
	register char **__argv                        __asm__("rdx");
	register void (*__ldso_fini)(void)            __asm__("r9");
	
	__asm__ __volatile__
		("xor  %%rbp , %%rbp \n" /* rbp:undefined -> mark as zero 0 (ABI) */
		 "mov  %%rdx , %3    \n" /* 6th arg: ptr to register with atexit() */
		 "pop  %1            \n" /* 2nd arg: argc */
		 "mov  %%rsp , %2    \n" /* 3rd arg: argv */
		 "andq $-16  , %%rsp \n" /* align stack pointer */
		 "mov  $main , %0    \n" /* 1st arg: application entry ip */
		 : "=r" (__main),
		   "=r" (__argc),
		   "=r" (__argv),
		   "=r" (__ldso_fini)
		 );
	__libc_start_main(__main, __argc, __argv, _init, _fini, __ldso_fini);

	for(;;);
}
