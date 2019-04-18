#include<stdio.h>
#include<stdlib.h>


struct request{
    int req_no;
    int visited;
};

void main(){
    int no_of_requests,i,j,k;
    printf("Enter No of Requests\n");
    scanf("%d",&no_of_requests);
    struct request requests[no_of_requests];

    printf("Enter the requets sequence\n");
    for(i=0;i<no_of_requests;i++)
    {
        scanf("%d",&requests[i].req_no);
        requests[i].visited=0;
    }

    int header;
    printf("Enter the r/w head pos\n");
    scanf("%d",&header);

    int n=no_of_requests,mindistance=1e9,min_trackpos,seektime=0;
    printf("%d->",header);
    while(n)
    {
        mindistance=1e9;

        for(i=0;i<no_of_requests;i++)
        {
            if((abs(header-requests[i].req_no) < mindistance)&&(requests[i].visited == 0))
            {
                mindistance=abs(header-requests[i].req_no);
                min_trackpos=i;
            }
        }
        requests[min_trackpos].visited=1;
        header=requests[min_trackpos].req_no;
        seektime+=mindistance;
        n--;
        printf("%d->",header);
    }

    printf("Seek time: %d\n" ,seektime);
}