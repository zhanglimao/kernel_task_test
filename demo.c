#include <linux/init.h>
#include <linux/module.h>
#include <asm/thread_info.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANGLIMAO");

static unsigned char* task_sched_type[] = {"SCHED_OTHER", "SCHED_FIFO", "SCHED_RR"};

static int test_init(void)
{
    printk("current task is %s\n", current->comm);
    
    struct task_struct *head = (struct task_struct *)current;
    struct task_struct *tmp = head;

    do{
        printk("--------start--------\n");
        printk("task name is %s\n", tmp->comm);
        printk("task pid is %d\n", tmp->pid);
        printk("task state is %ld\n", tmp->state);/* -1 unrunnable, 0 runnable, >0 stopped: */
        printk("task sched is %s\n", task_sched_type[tmp->policy]);
        printk("---------end---------\n");
        tmp = container_of(tmp->tasks.next, struct task_struct, tasks);
    }while(tmp != head);
    return 0;
}

static void test_exit(void)
{
    printk("exit\n");
}

module_init(test_init);
module_exit(test_exit);