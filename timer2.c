/* timer2.c --- 
 * Filename: timer2.c
 * Author: 郑丁方
 * Created: Sun Apr  1 12:40:28 2018 (+0800)
 */

/* Copyright 郑丁方.
 * 
 * 允许免费使用，拷贝，修改，发布，但在所有的拷贝上必须保留上述
 * copyright部分和本使用声明部分，除非显示声明，copyright的持有者
 * 不得作为再发布软件的广告。copyright的持有者对使用本软件的适用范围不做任何声明，
 * 
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<sys/time.h>

#define N 100 //设置最大的定时器个数

int i=0,t=1;//i代表定时器的个数；t表示时间，逐秒递增

struct Timer //Timer结构体，用来保存一个定时器的信息
{
    int total_time;//每隔total_time秒
    int left_time;//还剩left_time秒
    int func;//该定时器超时，要执行的代码的标志
}myTimer[N];//定义Timer类型的数组，用来保存所有的定时器

void setTimer(int t,int f)//新建一个计时器
{
    struct Timer a;
    a.total_time=t;
    a.left_time=t;
    a.func=f;
    myTimer[i++]=a;
}

 

void timeout()//判断定时器是否超时，以及超时时所要执行的动作

{
    printf("Time: %d\n",t++);
    int j;
    for(j=0;j<i;j++)
    {
       if(myTimer[j].left_time!=0)
           myTimer[j].left_time--;
       else
       {
           switch(myTimer[j].func)
           {      //通过匹配myTimer[j].func，判断下一步选择哪种操作
           case1:
              printf("------Timer 1: --Hello Aillo!\n");break;
           case2:
              printf("------Timer 2: --Hello Jackie!\n");break;
           case3:
              printf("------Timer 3: --Hello PiPi!\n");break;
           }
           myTimer[j].left_time=myTimer[j].total_time;//循环计时
       }
    }
}

 

int main()//测试函数，定义三个定时器
{
    setTimer(3,1);
    setTimer(4,2);
    setTimer(5,3);
    signal(SIGALRM,timeout);//接到SIGALRM信号，则执行timeout函数

    while(1)
    {
       sleep(1);//每隔一秒发送一个SIGALRM
       kill(getpid(),SIGALRM);
    }
    exit(0);
    return 0;
}
