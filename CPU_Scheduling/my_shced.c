#include <linux/kernel.h>
#include <linux/linkage.h>

int faster_pid;
int slower_pid;

/*process가 syscall을 호출하면 그 process의 pid를 커널 변수로 저장한다*/
asmlinkage void sched_faster(int pid){
	faster_pid = pid;
}
asmlinkage void sched_slower(int pid){
	slower_pid = pid;
}

/*syscall로 호출해준 pid를 kernel내 다른 소스코드에서 사용할 수 있도록 export해준다*/
EXPORT_SYMBOL(faster_pid);
EXPORT_SYMBOL(slower_pid);
