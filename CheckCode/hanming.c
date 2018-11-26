/* Author: Ji, Zhonghua, jzh@eh2tech.com
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>
#include <assert.h>


uint8_t GetHanmingNum(char*);
void GetHanming(char hanming[], char code[]);
int CheckHanming(char hanming[], uint8_t errorVec[]);
int CorrectHanming(uint8_t* errorVec, uint8_t len);


int main(void)
{
    /*(gdb) disp hanming */

    char code[256]="10011101";
    char hanming[256]={0};

    GetHanming(hanming, code);
    printf("source=%s, hanming=%s\n", code, hanming);


    uint8_t errorVec[10]={0};
    /*(gdb) set hanming[1]='0' */
    hanming[1]='0';
    int errCount= CheckHanming(hanming, errorVec);

    printf("before corrected: %s\n", hanming);
    if(errCount) {
        int error_index=CorrectHanming(errorVec, 10);
        if(hanming[error_index]=='1'){
            hanming[error_index]= '0';
        }else {
            hanming[error_index]= '1';
        }
    }
    printf("after corrected:  %s\n", hanming);

    return 0;
}

/*****
 * 从一个字符串code中读取二进制信息码，然后
 * 计算海明码，并附加到信息码中去
 * [out] char hanming[], 计算获得的最终的海明码
 * [in] char code[], 原始信息码 
 * ******/
void GetHanming(char hanming[], char code[])
{
    //位数计算
    int K = strlen(code);
    uint8_t r = GetHanmingNum(code);
    char* pSrc = code;
    char* pDes = hanming;
    
    //定位置&填充
    for(int i = 0; i<r; i++) {//将空的hanming填入信息码中
        int idx = pow(2,i)-1;
        hanming[idx] = '?';
        pDes++;
        for(int j=0;j<pow(2,i)-1; j++){//后续2^i个直接复制
            *pDes++ = *pSrc++;
        }
    }// ??1?001?1101

    //定数值 => 1110 0011 1101
    for(int i=0; i<r; i++) {//逐个将?换成'0'或者'1'
        int idx = pow(2,i)-1;
        assert(hanming[idx]=='?'); 
        hanming[idx]='0';
        int sum=0, interval=pow(2,i);
        for(int j=idx; j<strlen(hanming); 
                j+=2*interval/*sum一个interval，跳过一个interval*/) {
            for(int k=0;k<interval && j+k<strlen(hanming);k++) {//连续检验interval位
                sum+=hanming[j+k] - '0';
                printf("hanming[%d]=%c\n", j+k, hanming[j+k]);
            }
        }
        printf("\n");
        if(sum%2!=0){ //sum为奇数,偶校验
            hanming[idx]='1';
        }
    }
}

/*****
 * 从一个字符串hanming中读取二进制海明码，然后
 * 检查海明码，找出错误的Gx,将所有错误的Gx中的x
 * 放入errorVec[]中并返回
 * [out] uint8_t errorVec[] 所有错误的Gx
 * [in] char hanming[], 海明码
 * [ret] int, 错误的Gx的个数
 * ******/
int CheckHanming(char hanming[], uint8_t errorVec[])
{
    int count=0;
    uint8_t error[256]={0};

    //校验码检查, 流程和“定数值”相同
    for(int i=0; pow(2,i) < strlen(hanming); i++){
        count++;
        printf("\n");
        int idx = pow(2,i) -1;
        int xor=0, interval = pow(2,i);
        for(int j=idx; j<strlen(hanming); j+=2*interval) {
            for(int k=0; k<interval && j+k<strlen(hanming); k++) {
                xor^=hanming[j+k] - '0';
                printf(" %d", j+k);
            }
        }
        printf("\n");
        printf("G%d, xor=%d\n", i, xor);
        error[i]=xor;
    }

    int errCount=0;int j=0;
    for(int i=0; i<count; ++i) {//检查所有的错误
        if(error[i]==1) {
           errorVec[j++]=i; //记录错误编号
           errCount ++;
        }
    }

    return errCount;
}

uint8_t ErrorTable[256][10]={
    {0},
    {1},
    {0,1},
    {2},
    {0,2},
    {1,2},
    {0,1,2},
    {3},
    {0,3},
    {1,3},
    {0,1,3},
    {2,3},
    {0,2,3},
    {1,2,3},
    {0,1,2,3},
    {4},
    {0,4},
    {1,4},
    //...

};
/*****
 * 根据海明码的错误向量errorVec, 查表找到
 * 海明码的错误位
 * [in] uint8_t errorVec[] 海明码错误向量 ,还有所有检查发现有错误的海明码位序
 * [in] uint8_t len 错误向量的长度
 * [ret] int, 错误位序
 *
 * Note: 并没有修正海明码的错误
 * ******/
int CorrectHanming(uint8_t* errorVec, uint8_t len)
{
    int idx=0;
    int i, j;
    for(i=0; i<256; ++i) {
        for(j=0; j<len; j++) { 
            /*(gdb) p *errorVec@len */
            /*(gdb) p ErrorTable[3] */
            if(errorVec[j]!=ErrorTable[i][j]) {//不完全相同
                break;
            }
        }
        if(j==len) break;//能够比较到最后一个元素都相等，说明找到了
    }

    return i;
}

/*
 *  计算信息码对应的海明码的长度
 *  [in] char* code 信息码字符串
 *  [ret] 海明码的长度（不含原始信息码）
 */
uint8_t GetHanmingNum(char* code)
{
    int K = strlen(code);
    if(K>248) { printf("too long to support it"); return 0;}
    else if(K>120) return 8;
    else if(K>57) return 7;
    else if(K>26) return 6;
    else if(K>11) return 5;
    else if(K>4) return 4;
    else if(K>1) return 3;
    else return 2;
}

