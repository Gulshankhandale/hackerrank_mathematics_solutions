#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    long long candy,j;
    int t,count=0;
    scanf("%d",&t); 
    for(int i=0;i<t;i++)
    {
        scanf("%lldL",&candy);
        for(j=1;j<=candy;j++)
        {
            candy-=(j*j);
            if((long long)candy < 0)
                break;
            else
                count++;
        }
        printf("%d\n",count);
        count=0;
    }
    return 0;
}
