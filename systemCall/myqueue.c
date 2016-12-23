#include <stdio.h>

int main(){
	while(1){
		int flag;
		printf("select option \n");
		printf("0.enqueue 1.deqeueu 2.exit\n");
		scanf("%d",&flag);
		if(flag==0){
			int n;
			printf("enqueue number : ");
			scanf("%d",&n);
			syscall(316,n);
		}
		else if(flag == 1){
			syscall(317);
		}
		else if(flag == 2){
			break;
		}
		else{
			printf("incorrect input");
		}
	}
	return 0;
}
