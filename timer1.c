/* timer1.c --- 
 * Filename: timer1.c
 * Author: 郑丁方
 * Created: Sun Apr  1 12:14:46 2018 (+0800)
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

 
int main ()
{
	 
	 
    unsigned int x_hours=0;
    unsigned int x_minutes=0;
    unsigned int x_seconds=0;
    unsigned int x_milliseconds=0;
    unsigned int totaltime=0,count_down_time_in_secs=0,time_left=0;

    clock_t x_startTime,x_countTime;
    count_down_time_in_secs=10;  // 1 minute is 60, 1 hour is 3600

 
    x_startTime=clock();  // start clock
    time_left=count_down_time_in_secs-x_seconds;   // update timer

    while (time_left>0) 
    {
        x_countTime=clock(); // update timer difference
        x_milliseconds=x_countTime-x_startTime;
        x_seconds=(x_milliseconds/(CLOCKS_PER_SEC))-(x_minutes*60);
        x_minutes=(x_milliseconds/(CLOCKS_PER_SEC))/60;
        x_hours=x_minutes/60;

        time_left=count_down_time_in_secs-x_seconds; // subtract to get difference 


        printf( "\nYou have %d seconds left ( %d ) count down timer by TopCoder ",time_left,count_down_time_in_secs);
    }


    printf( "\n\n\nTime's out\n\n\n");

    return 0;
}

/* #include <signal.h> */
/* #include <unistd.h> */
/* #include <stdio.h> */

/* volatile int stop=0; */

/* void sigalrm_handler( int sig ) */
/* { */
/*     stop = 1; */
/* } */

/* int main(int argc, char **argv) */
/* { */
/*     struct sigaction sact; */
/*     int num_sent = 0; */

/*     sigemptyset(&sact.sa_mask); */
/*     sact.sa_flags = 0; */
/*     sact.sa_handler = sigalrm_handler; */
/*     sigaction(SIGALRM, &sact, NULL); */

/*     alarm(60);  /\* Request SIGALRM in 60 seconds *\/ */
/*     while (!stop) { */
/*         send_a_packet(); */
/*         num_sent++; */
/*     } */

/*     printf("sent %d packets\n", num_sent); */
/*     exit(0); */
/* } */
