#include<stdio.h>

void main(){

    int i,j,k;

    int indexes[100];
    for(i=0;i<100;i++)
        indexes[i]=0;
    printf("Enter the frame capacity\n");
    int capacity;
    scanf("%d",&capacity);
    int frameReference[capacity];
    for(i=0;i<capacity;i++)
        frameReference[i]=-1;
    printf("Enter the page reference stream size\n");
    int size;
    scanf("%d",&size);
    int pageReference[size];
    printf("Enter the reference stream\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&pageReference[i]);
    }

    int pageFaults=0;
    int frameCount=0;
    int pagePresent=0;
    for(i=0;i<size;i++)
    {
        pagePresent=0;
        for(j=0;j<frameCount;j++)
        {
            if(pageReference[i] == frameReference[j])
                {
                    pagePresent = j;
                    break;
                }
        }

        if(frameCount < capacity)
        {
            
            if(pagePresent == 0)
            {
                frameReference[frameCount]=pageReference[i];
                frameCount++;
                pageFaults++;
            }
            indexes[pageReference[i]]=i;
        }
        else
        {
            if(pagePresent == 0)
            {
                int lru=99999,ind=-1;
                for(j=0;j<capacity;j++)
                {
                    if(indexes[frameReference[j]] < lru)
                    {
                        lru=indexes[frameReference[j]];
                        ind=j;
                    }
                }
                if(ind != -1)
                    frameReference[ind] = pageReference[i];
                pageFaults++;
            }
            indexes[pageReference[i]]=i;
        }
        if( pagePresent == 0)
        {
            printf("page Fault\n");
        }
        else
        {
            printf("page hit %d\n",pagePresent);
        }
    }


    printf("Page Faults: %d\n",pageFaults);
}