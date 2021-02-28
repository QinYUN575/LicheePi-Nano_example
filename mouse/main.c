/**
 * 版权声明：本文为CSDN博主「hello_zard」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
 * 原文链接：https://blog.csdn.net/A694543965/article/details/79834008
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//cat /proc/bus/input/devices找到鼠标的对应的事件

#define MOUSE "/dev/input/event1"

int main(int argc, char **argv)
{
    int fd, retval;
    struct input_event event;
    fd_set readfds;
    int ret;
    struct timeval tv;
    struct timeval time;
    // 打开鼠标设备,
    fd = open(MOUSE, O_RDONLY);
    // 判断是否打开成功
    if (fd < 0)
    {
        perror("open "
               "MOUSE");
        exit(1);
    }

    while (1)
    {
        // 设置最长等待时间
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);

        retval = select(fd + 1, &readfds, NULL, NULL, &tv);
        if (retval == 0)
        {
            printf("Time out!\n");
        }
        if (FD_ISSET(fd, &readfds))
        {
            // 读取鼠标设备中的数据
            ret = read(fd, &event, sizeof(struct input_event));
            // 打印出从鼠标设备中读取到的数据
            time = event.time;
            printf("timeS=%d,timeUS=%d,type=0x%02x,code=0x%02x,value=%d   \n", time.tv_sec, time.tv_usec, event.type, event.code, event.value);
        }
    }
    close(fd);
    return 0;
}
