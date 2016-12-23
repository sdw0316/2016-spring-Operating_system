#include <linux/kernel.h>
#include <linux/linkage.h>

int queue[100];//queue
int tail=-1;//end of queue
int i;//index

/*
enqueue function
*/
asmlinkage void sys_my_enqueue(int n) {
	/*
	큐에 중복된 값 있나 검사.
	*/
	for (i = 0; i < tail; i++) {
		if (queue[i] == n) {
			printk("This value is already in Queue\n");
			return;
		}
	}
	/*
	큐가 가득 차 있는지 검사.
	*/
	if(tail==100){
		printk("Queue is full\n");
		return;
	}
	/*
	하니면 큐에 값 추가 하고 tail++
	*/
	queue[++tail] = n;
	printk("Queue : ");
	for (i = 0; i <= tail; i++) {
		printk("%d ", queue[i]);
	}//queue 상태 출력
	printk("\n");
}

/*
dequeue function
*/
asmlinkage int sys_my_dequeue(void) {
	/*
	queue 비었을 경우 검사
	*/
	int result;
	if (tail < 0) {
		printk("Queue is Empty\n");
		return -1;
	}
	/*
	아니면 dequeue
	*/
	else {
		result = queue[0];
		for (i = 0; i <= tail; i++) {
			queue[i] = queue[i + 1];
		}//index 0번의 값 빼고 하나씩 당김
		tail--;//tail값 감소
		printk("Queue : ");
		for (i = 0; i <= tail; i++) {
			printk("%d ", queue[i]);
		}//queue 상태 출력
		printk("\n");
		return result;
	}
}
