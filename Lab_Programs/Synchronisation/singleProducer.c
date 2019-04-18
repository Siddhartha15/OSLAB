#include<stdio.h>

#define Buffer_Size 10

int mutex=1;
int full=0;
int empty=Buffer_Size;

int  wait(int S){
if (S < 0)
{
	printf("nothing to consume\n");
	return 0;
}   // busy waiting
S--;

return S;
}

int   signal(int S){
S++;
return S;
}

void producer(){

//produce an item

empty=wait(empty);
mutex=wait(mutex);



//place in buffer

mutex=signal(mutex);
full=signal(full);

}

void consumer(){
	

full=wait(full);
mutex=wait(mutex);

// remove item from buffer

mutex=signal(mutex);
empty=signal(empty);

// consumes item


}

void main(){

printf("Producer Consumer problem- \n");

int c,i=0;
	while(1){
		printf("Enter 1-produce 2-Consume 3-exit\n");
		scanf("%d",&c);
	 switch(c){
	 	case 1: producer();
	 			printf("full-%d\nempty-%d",full,empty);
	 			break;
	 	case 2: consumer();
	 			printf("full-%d\nempty-%d",full,empty);
	 			break;
	 	case 3: exit(0);
	 		}

	}
	 

}