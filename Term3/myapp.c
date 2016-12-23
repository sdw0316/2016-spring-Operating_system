#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 32768

int main(){
	char pid[100];
	char path[100];

	char buffer[100];
	char name[100];
	int vmsize;
	int rss;
	int shared;
	int wss[MAX+1] = {0, };
	
	int i;
	int loop=0;

	FILE *fp;
		
	printf("%10s%10s%12s%12s%12s%10s\n","PID","Name","VMsize","PMsize","Shared","WSS");
	
	while(1){
		if(loop>120){
			break;
		}
		for(i=1;i<=MAX;i++){
			int present;	//working set of current process
			sprintf(pid, "%d", i);

			/*open status*/
			strcpy(path,"/proc/");
			strcat(path, pid);
			strcat(path, "/status");
			fp=fopen(path, "r");
			
			if(fp!=NULL){
				fscanf(fp,"%s	%s",buffer, name);
			}
			else{
				continue;			
			}
			fclose(fp);
			/*open statm*/

			strcpy(path,"/proc/");
			strcat(path, pid);
			strcat(path, "/statm");
			fp=fopen(path, "r");

			if(fp!=NULL){
				fscanf(fp,"%d %d %d",&vmsize, &rss, &shared);
			}
			fclose(fp);
			present = rss;
			
			/*print info*/
			printf("%10s%10s%10dKB%10dKB%10dKB",pid, name, vmsize*4, rss*4, shared*4);
			if(present != wss[i])
				printf("\t*");
			
			printf("\n");
			wss[i] = present;
		}
		usleep(500000);
		loop++;
	}
	return 0;
}	
