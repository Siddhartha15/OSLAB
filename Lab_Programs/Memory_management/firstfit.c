#include<stdio.h>
// int MemSize;
int NofPart;  
int NofProc;


void main()
{
    // printf("Enter total Memory size\n");
    // scanf("%d",&MemSize);
    printf("Enter No of Partitions of Memory\n");
    scanf("%d",&NofPart);
    int i=0;
    int MemArray[NofPart];
    int MemRem[NofPart];

    for(i=0;i<NofPart;i++)
    {
        printf("Enter Memory Partition %d size: ",i);
        scanf("%d",&MemArray[i]);
    }

    printf("Enter the No of processes\n");
    scanf("%d",&NofProc);
    int ProcArray[NofProc];
    int ProcAllot[NofProc];
    int MemAllot[NofPart];

    for(i=0;i<NofProc;i++)
        ProcAllot[i]=-1;
    for(i=0;i<NofPart;i++)
        MemAllot[i]=-1;
    for(i=0;i<NofPart;i++)
        MemRem[i]=-1;



    for (int i = 0; i < NofProc; i++)
    {
        printf("Enter process %d size: ",i);
        scanf("%d",&ProcArray[i]);
    }

    int j=0;
    for( i=0;i<NofProc;i++)
    {
        if(ProcAllot[i] == -1)
        {    

            for(j=0;j<NofPart;j++)
            {
                    if(MemAllot[j]!= 1 && ProcArray[i]< MemArray[j])
                    {
    
                        MemAllot[j]=1;
                        ProcAllot[i]=j;
                        MemRem[j]=MemArray[j]-ProcArray[i];
                        break;
                    }
                    else if( MemAllot[j] == 1)
                    {
                        if( ProcArray[i]< MemRem[j])
                        {
                            ProcAllot[i]=j;
                            MemRem[j]=MemRem[j]-ProcArray[i];
                            break;
                        }
                    }        
                    
                
            }
            
        }
    }
    printf("ProcId\tProcSize\tBlockAllot\n");
    for(i=0;i<NofProc;i++)
    {
         printf("%d    \t%d      \t%d        \n",i,ProcArray[i],ProcAllot[i]);
    }
    printf("Internalfrag\n");
    for(i=0;i<NofPart;i++)
    {
        printf("%d\n",MemRem[i]);
    }
}