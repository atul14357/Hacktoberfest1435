#include <stdio.h>
#include <string.h>
int main()
{
    printf("Enter the string\n");
    char s[100],sc[100];
    scanf("%[^\n]s", s);
    int i,k=0,n,p=0;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    k = strlen(s);
    for(i=0;i<=n;i++)
    {
        sc[p] = s[i];
        p++;
    }
    sc[p] = '\0';
    printf("%s\n", sc);
    p=0;
    for(i=k-n;i<k;i++)
    {
        sc[p] = s[i];
        p++;
    }
    sc[p] = '\0';
    printf("%s", sc);
    getch();
    return 0;
}
