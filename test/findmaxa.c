#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
#define length 64

void funs(char* str,int len)
{
    //先做分词,用一个指针数组存储word
    int i=0,j=0;
    int last=0;//上一次空格出现的位置
    char* words[MAX];
    for(;i<len;i++){
        if(str[i]==' '){
            if(i - last == 1){
                last = i;
                continue;//连续空格
            }
            char *word=(char*)malloc(length);
            memset(word,0,length);
            if(last != 0){
                strncpy(word,str+last+1,i-last-1);
            }else{
                strncpy(word,str+last,i-last);
            }
            last = i;
            words[j++] = word;
        }
    }
    //找出单词数组中出现a次数最多的单词,不支持出现次数一样的情况。
    if(j>0){
       int max = 0,index=-1;
        for(i=0;i<j;i++){
            int k=0,num=0;//每个单词a出现的次数为num
            for(;k<strlen(words[i]);k++){
                if(words[i][k] == 'a'){
                    num++;
                }
            }
            if(num > max){
                max = num;//单词出现a的次数的最大值
                index = i;//数组中的位置
            }
        }
        if(index != -1){
            printf("出现a最多的单词是:%s\n",words[index]);
        }else{
            printf("没有a出现\n");
        }
        //释放资源
        for(i=0;i<j;i++){
            free(words[i]);
        }
    }
}

int main()
{
    char a[MAX] = {0};
    printf("please input a string:");
    gets(a);//it's dangers.nerver use this function--->man gets,it's just for test
    funs(a,MAX);
    return 0;
}
