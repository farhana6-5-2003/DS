#include <stdio.h>
//#define SAMPLE 10
void main()
{
#ifdef SAMPLE
	printf("With preprocessor directive\n");
#else
	printf("With out #ifdef\n");
#endif
}
