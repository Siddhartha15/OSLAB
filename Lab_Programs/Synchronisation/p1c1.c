#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mutex=1,full=0,empty=3,x=0;

int main(){

    int n;// n is the choice that user will enter 

    void producer();
    void consumer();
    int signal(int);
    int wait(int);

    printf("\n1.Producer\n2.Consumer\n3.Exit");

    while(1){
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1: if((mutex==1)&&(empty!=0))
                        producer();
                    else
                        printf("Clash!!\n");
                    break;
            case 2: if((mutex==1)&&(full!=0))
                        consumer();
                    else
                        printf("Buffer is empty!!\n");
                    break;
            case 3:
                    exit(0);
                    break;
        }
    }


}

int wait(int s)
{
    return (--s);
}
 
int signal(int s)
{
    return(++s);
}
 
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    char c;
    printf("\nProducer produces the item %d\n",x);
    printf("do you want to terminate producing(y/n)\n");
    getchar();
    scanf("%c",&c);
    if(c == 'y')
    {
        printf("completed production\n");
         mutex=signal(mutex);
    }
    if(c == 'n')
    {
        printf("Still producing\n");
    }
}
 
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signal(mutex);
}