# timer

### linux c setitimer用法说明

文件timer3

头文件

```c
#include <sys/time.h>  
```

函数原型

```c
int setitimer(int which, const struct itimerval *new_value,  
            struct itimerval *old_value);  
```

其中which参数表示类型，可选的值有：

**ITIMER_REAL**：以系统真实的时间来计算，它送出SIGALRM信号。

**ITIMER_VIRTUAL**：以该进程在用户态下花费的时间来计算，它送出SIGVTALRM信号。

**ITIMER_PROF**：以该进程在用户态下和内核态下所费的时间来计算，它送出SIGPROF信号。

紧接着的new_value和old_value均为itimerval结构体，先看一下itimerval结构体定义：

```c
struct itimerval {  
    struct timeval it_interval; /* next value */  
    struct timeval it_value;    /* current value */  
};  
  
struct timeval {  
    time_t      tv_sec;         /* seconds */  
    suseconds_t tv_usec;        /* microseconds */  
};  
```

itimeval又是由两个timeval结构体组成，timeval包含tv_sec和tv_usec两部分，其中tv_se为秒，tv_usec为微秒(即1/1000000秒)

其中的new_value参数用来对计时器进行设置，it_interval为计时间隔，it_value为延时时长，下面例子中表示的是在setitimer方法调用成功后，延时1微秒便触发一次SIGALRM信号，以后每隔200毫秒触发一次SIGALRM信号。

**settimer工作机制是，先对it_value倒计时，当it_value为零时触发信号，然后重置为it_interval，继续对it_value倒计时，一直这样循环下去。**

基于此机制，setitimer既可以用来延时执行，也可定时执行。

**假如it_value为0是不会触发信号的，所以要能触发信号，it_value得大于0；如果it_interval为零，只会延时，不会定时（也就是说只会触发一次信号)。**

old_value参数，通常用不上，设置为NULL，它是用来存储上一次setitimer调用时设置的new_value值。