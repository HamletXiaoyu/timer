/* timer3.c --- 
 * Filename: timer3.c
 * Author: 郑丁方
 * Created: Sun Apr  1 14:23:29 2018 (+0800)
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


#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static int count = 0;
static struct itimerval oldtv;
struct itimerval itv;

void set_timer()
{
	itv.it_interval.tv_sec = 1;
	itv.it_interval.tv_usec = 0;
	itv.it_value.tv_sec = 1;
	itv.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &itv, &oldtv);
}

void uninit_time()  
{  
    itv.it_value.tv_sec = 0;  
    itv.it_value.tv_usec = 0;  
    itv.it_interval = itv.it_value;  
    setitimer(ITIMER_REAL, &itv, NULL);  
}

void signal_handler(int m)
{
	count ++;
	printf("%d\n", count);
}

void function()
{
    for(int i = 0; i<100; ++i){
        printf("iam counting %d...\n", i);
        sleep(1);
        if( i == 10 )
            uninit_time();
    }
}

int main()
{
	signal(SIGALRM, signal_handler);
	set_timer();
        function();        
	return 0;
}
