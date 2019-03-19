#include<stdio.h>
#include<stdlib.h>
#define READ 0
#define WRITE 1
#define FREE 2
void  main(){
    int op, mutex = FREE;

    do{
        printf("1. Read\n");
        printf("2. write\n");
        printf("3. End Reading\n");
        printf("4. End Writing\n");

        scanf("%d", &op);

        switch(op){
            case 1: if( mutex == WRITE )
                        printf(" Writing in process..Can't Read.\n");
                    else{
                        printf(" Reading...\n");
                        mutex = READ;
                    }
                break;
            case 2 :if( mutex == READ)
                        printf(" Reading in process..Can't Write.\n");
                    else if( mutex == WRITE )
                        printf(" Writing already in process..Can't Write.\n");
                    else{
                        printf("Writing...\n");
                        mutex = WRITE;
                    }
                break;
            case 3: if( mutex == READ )
                        printf(" Ended Reading.. ");
                    else
                        printf("Reading is not in process...\n");
                break;
            case 4: if( mutex == WRITE )
                        printf(" Ended Writing.. ");
                    else
                        printf("Writing is not in process...\n");
                break;
        }
    }while(op!=5);
}