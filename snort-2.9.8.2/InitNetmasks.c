/******************************************************************
 *  @file       InitNetmasks.c
 *  @version    v1.0 
 *  @author     ymm 
 *  @date       2016/06/30
 *  @brief      snort代码InitNetmasks的使用
 *  @history      
 *  1. 2016/06/30  author ymm    初步完成
 ******************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <arpa/inet.h>
#include <stdlib.h>

int ConvertBigEndianIPToString(uint32_t int_ip, char *str_ip)
{
#ifndef _WIN32
    str_ip[0] = 0;
    inet_ntop(AF_INET, &int_ip, str_ip, 60);
#endif

    return 0;
}

int ConvertLittleEndianIPToString(uint32_t int_ip, char *str_ip)
{

#ifndef _WIN32
    str_ip[0] = 0;
    uint32_t tmpVal = htonl(int_ip);
    inet_ntop(AF_INET, &tmpVal, str_ip, 60);
#endif

    return 0;
}

#define SnortAlloc(a) calloc(1,(a))

uint32_t *netmasks = NULL;   /* precalculated netmask array */
static void InitNetmasks(void)
{
    if (netmasks == NULL)
        netmasks = (uint32_t *)SnortAlloc(33 * sizeof(uint32_t));

    netmasks[0]  = 0x00000000;
    netmasks[1]  = 0x80000000;
    netmasks[2]  = 0xC0000000;
    netmasks[3]  = 0xE0000000;
    netmasks[4]  = 0xF0000000;
    netmasks[5]  = 0xF8000000;
    netmasks[6]  = 0xFC000000;
    netmasks[7]  = 0xFE000000;
    netmasks[8]  = 0xFF000000;
    netmasks[9]  = 0xFF800000;
    netmasks[10] = 0xFFC00000;
    netmasks[11] = 0xFFE00000;
    netmasks[12] = 0xFFF00000;
    netmasks[13] = 0xFFF80000;
    netmasks[14] = 0xFFFC0000;
    netmasks[15] = 0xFFFE0000;
    netmasks[16] = 0xFFFF0000;
    netmasks[17] = 0xFFFF8000;
    netmasks[18] = 0xFFFFC000;
    netmasks[19] = 0xFFFFE000;
    netmasks[20] = 0xFFFFF000;
    netmasks[21] = 0xFFFFF800;
    netmasks[22] = 0xFFFFFC00;
    netmasks[23] = 0xFFFFFE00;
    netmasks[24] = 0xFFFFFF00;
    netmasks[25] = 0xFFFFFF80;
    netmasks[26] = 0xFFFFFFC0;
    netmasks[27] = 0xFFFFFFE0;
    netmasks[28] = 0xFFFFFFF0;
    netmasks[29] = 0xFFFFFFF8;
    netmasks[30] = 0xFFFFFFFC;
    netmasks[31] = 0xFFFFFFFE;
    netmasks[32] = 0xFFFFFFFF;
}

int main(int argc,char *argv[])
{
    InitNetmasks();
    char ip[16] = {0};
    int i = 0;
    for(i = 0; i < 33; i++){
        ConvertLittleEndianIPToString(netmasks[i], ip);
        printf("ip= %s\n", ip);
    }

    return 0;
}
