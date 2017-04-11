#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <iostream>
#include <alchemy/task.h>
#include <alchemy/timer.h>

RT_TASK demo_task[5];

void demo(void *arg)

{

  RT_TASK *curtask;
  RT_TASK_INFO curtaskinfo;

  // hello world
  rt_printf("Hello World!\n");

  // inquire current task
  curtask=rt_task_self();
  rt_task_inquire(curtask,&curtaskinfo);

  // print task name
  rt_printf("Task name : %s \n", curtaskinfo.name);

}

 
int main(int argc, char* argv[])
{
  char  str[5][10] ;

  sprintf(str[0],"hello");
  sprintf(str[1],"hello1");
  sprintf(str[2],"hello2");
  sprintf(str[3],"hello3");
  sprintf(str[4],"hello4");

  for(int i = 0; i < 5; i++)
    rt_task_create(&demo_task[i], str[i], 0, 50 + i, 0);

  for(int i = 0; i < 5; i++)
    rt_task_start(&demo_task[i], &demo, 0);
    
  usleep(1E6);
  return 0;
}