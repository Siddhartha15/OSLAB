#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int fID;
    struct node *next;
};

struct file{
    int fID;
    int size;
    struct node *start;
    struct node *end;
}f[20];


int main()
{
    int cnt = 0, i, j;
    printf("Enter the block size\n");
    int s;
    scanf("%d",&s);
    
    while(1)
    {
        printf("Enter 1 to add file and 2 to view table : ");
        int n;
        scanf("%d", &n);
        switch(n)
        {
            case 1: printf("Enter file ID and size :");
                scanf("%d %d", &f[cnt].fID, &f[cnt].size);
                int n=(int)(f[cnt].size/s);
                struct node *head=NULL;
                struct node *temp;
                temp=head;
                for(i=0;i<n;i++)
                {
                    //printf("------------------------------\n");
                    struct node *ptr=(struct node *)malloc(sizeof(struct node));
                    if(head == NULL)
                    {
                        head=ptr;
                        head->fID=f[cnt].fID;
                        head->next=NULL;
                        temp=head;
                    }
                    else{
                        ptr->fID=f[cnt].fID;
                        ptr->next=NULL;
                        temp->next=ptr;
                        temp=temp->next;
                    }
                }
                f[cnt].end=temp;
                temp->next=NULL;
                f[cnt].start=head;
                cnt++;
                break;
            case 2: printf("ID\t\tStart\t\t\tEnd\n");
                for(i = 0; i < cnt; i++)
                {
                    printf("%d\t\t%p\t\t%p\n", f[i].fID, f[i].start,f[i].end);
                    struct node *a = f[i].start;
                    while(1)
                    {
                        if(a == NULL)
                        {
                            break;
                        }
                         printf("%p->",a);
                        a=a->next;
                       
                    }
                    printf("null\n");
                }
        }
    }
}
