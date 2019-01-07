#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <signal.h>
#include "msdb.h"
#include "msstd.h"
#if defined (_HI3798_)
#include <execinfo.h>
#endif



int g_msfs_debug = 0;

static int g_exit = 0;
static void signal_handler(int signal)
{   
    g_exit = 1;
}

#if defined (_HI3798_)
void print_trace (void)
{
    void *array[100];
    size_t size;
    char **strings;
    size_t i;
    
    size = backtrace (array, 100);
    strings = backtrace_symbols (array, size);
    if (NULL == strings)
    {
        printf("backtrace_synbols");
    }
    
    printf("Obtained %zd stack frames.\n", size);
    for (i = 0; i < size; i++)
    {
        printf("backtrace : %s\n", strings[i]);
    }
    free (strings);
    strings = NULL;
}
#endif 

static void signal_backtrace(int signo)
{
    printf("signal_backtrace sigNo : %d\n", signo);
#if defined (_HI3798_)
    print_trace();
#endif
	exit(0);
}

static void set_test_signal()
{
    signal(SIGINT,  signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGKILL, signal_handler);

	signal(SIGSEGV, signal_backtrace);//11
	signal(SIGBUS, signal_backtrace);// 7
	signal(SIGILL, signal_backtrace);// 4
	signal(SIGSTKFLT, signal_backtrace);// 16
	signal(SIGFPE, signal_backtrace);// 8
	signal(SIGABRT, signal_backtrace);//6
}

#define DB_FILE_PATH "./file/msdb.db"
#if 0
int main(void)
{    
    set_test_signal();
    char b [ 64 ];
    while(!g_exit)
    {
        printf("######### demo ##########\n");
        break;
    }
   	return 0;
}
#else
int main(int argc, char *argv[])
{
    int ret = 0;
    
    reboot_conf conf = {0};
    conf.enable = 1;
    //ret = read_autoreboot_conf("/home/user1/hong/smdd/demo/99-project_bak/file/msdb.db", &conf);
    ms_system("ls -l");
    ret = read_autoreboot_conf(DB_FILE_PATH, &conf);
    printf("ret:%d enable:%d\n", ret, conf.enable);
    //conf.enable = 0;
    //write_autoreboot_conf(SQLITE_FILE_NAME, &conf);
    
    return ret;
}
#endif

