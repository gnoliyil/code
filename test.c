#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main()
{ 
#ifdef OPEN_MAX
printf("%d\n", OPEN_MAX);
#else 
printf("NO OPEN_MAX");
#endif
return 0; 
}
