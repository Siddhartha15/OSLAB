#include<stdio.h>

struct file_alloc{
    char id[10];
    int start, end, size;
}f[20];

int main()
{
    printf("Enter the block size\n");
    int s;
    scanf("%d",&s);

    int cnt = 0, i;
    while(1)
    {
        printf("Enter 1 to add file and 2 to view table : ");
        int n;
        scanf("%d", &n);
        switch(n)
        {
            case 1: {
                printf("Enter filename and size :");
                scanf("%s %d", f[cnt].id, &f[cnt].size);
                printf("Enter the start address manually\n");
                int startAddr;
                scanf("%d",&startAddr);
                int flag=0;
                for(i=0;i<cnt;i++)
                {
                    if((startAddr >= f[i].start) && (startAddr <= f[i].end))
                    {
                        flag=1;
                        break;
                    }
                }
                int endaddr = startAddr +(int)(f[cnt].size/(s)) - 1;
                int flag1=0;
                for(i=0;i<cnt;i++)
                {
                    if((endaddr >= f[i].start) && (endaddr <= f[i].end))
                    {
                        flag1=1;
                        break;
                    }
                }
                if(flag == 0 && flag1 == 0)
                {
                    f[cnt].start=startAddr;
                f[cnt].end = endaddr;
                cnt++;
                }
                else{
                    printf("ERROR : Already file is allocated in that addr or No space Available\n");
                }
                
                break;
            }
            case 2: printf("ID\t\tStart\t\tEnd\n");
                for(i = 0; i < cnt; i++)
                {
                    printf("%s\t\t%d\t\t%d\n", f[i].id, f[i].start, f[i].end);
                }
        }
    }
}
