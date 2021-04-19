#include <stdio.h>
#include <string.h>

int main()  {
    char * ptr;
    char strFloat[20];
    float number=103.02543;
    sprintf(strFloat, "%.4f", number);
    printf("str is %s\r\n", strFloat);
    ptr = strstr(strFloat, ".");
    if (ptr != NULL) {
        printf("decimal point position is : %d\n", (strlen(strFloat) - strlen(ptr)));
    }
    return 0;
}