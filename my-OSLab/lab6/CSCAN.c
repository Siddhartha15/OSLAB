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

    int initial_header,previous_header, limit;
    printf("Enter the r/w initial_header position\n");
    scanf("%d",&initial_header);
    printf("Enter the r/w previous_header position\n");
    scanf("%d",&previous_header);
    printf("Enter the cylinder size\n");
    scanf("%d",&limit);

    int choice; // 1-left to right or 2-right to left
    if(previous_header > initial_header)
        choice = 2;
    else 
        choice = 1;

    int seektime=0;
    int cpinitial_header = initial_header;
    printf("%d->",initial_header);
    if(choice == 1) //left to right
    {
        for(i=initial_header;i<=limit;i++)
        {
            for(j=0;j<no_of_requests;j++)
            {
                if( (i == requests[j].req_no ) && (requests[j].visited == 0))
                {
                    requests[j].visited=1;
                    seektime+=abs(initial_header-requests[j].req_no);
                    initial_header=i;
                    printf("%d->",initial_header);
                }
            }
        }
        seektime+=abs(initial_header-limit);
        initial_header=limit;
        printf("%d->",initial_header);
        initial_header=0;
        printf("%d->",initial_header);
        for(i=0;i<=cpinitial_header;i++)
        {
             for(j=0;j<no_of_requests;j++)
            {
                if( (i == requests[j].req_no ) && (requests[j].visited == 0))
                {
                    requests[j].visited=1;
                    seektime+=abs(initial_header-requests[j].req_no);
                    initial_header=i;
                    printf("%d->",initial_header);
                }
            }
        }
        
    }
    else if(choice == 2) //right to left
    {
        for(i=initial_header;i>=0;i--)
        {
            for(j=0;j<no_of_requests;j++)
            {
                if( (i == requests[j].req_no ) && (requests[j].visited == 0))
                {
                    requests[j].visited=1;
                    seektime+=abs(initial_header-requests[j].req_no);
                    initial_header=i;
                    printf("%d->",initial_header);
                }
            }
        }
        seektime+=abs(initial_header-0);
        initial_header=0;
        printf("%d->",initial_header);
        initial_header=limit;
        printf("%d->",initial_header);
        
        for(i=limit;i>=cpinitial_header;i--)
        {
             for(j=0;j<no_of_requests;j++)
            {
                if( (i == requests[j].req_no ) && (requests[j].visited == 0))
                {
                    requests[j].visited=1;
                    seektime+=abs(initial_header-requests[j].req_no);
                    initial_header=i;
                    printf("%d->",initial_header);
                }
            }
        }
       
    }

    printf("\nseektime : %d\n", seektime);
    
    
}