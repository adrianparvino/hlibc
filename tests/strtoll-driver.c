#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *s1 = "   -12315299'end of the string has noise'";
	long long ans = 0; 
	ans = strtoll(s1, &s1, 10);
	printf("%lld\n", ans);
	printf("end of string== %s\n", s1); 
	char *s2 = "0x2F4";
	ans = strtoll(s2, &s2, 16);
        printf("%x\n", (unsigned int)ans);
	printf("%x\n", 0xff);
	char *s3 = "2F4";
        ans = strtoll(s3, &s3, 16);
        printf("%x\n", (unsigned int)ans);
	printf("%x\n", 0x2F4);
	char *s4 = "0s2ff4cb6";
        ans = strtoll(s4, &s4, 19);
        printf("%x\n", (unsigned int)ans);
	printf("%x\n", 0x2F4);
	return 0;
}

