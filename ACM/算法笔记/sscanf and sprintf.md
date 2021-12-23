### sscanf:从一个字符串中读进与指定格式相符的数据

原型  `int sscanf(const char* str,const char* format,....)`

例如 `sscanf(b,"%d",&c)`指的是==从 b 中读取整形的数据到 c 中==

成功返回参数数目，失败返回 0



~注意 ： sscanf 与 scanf 功能类似，都是用于输入，后者以键盘为主，前者以==固定字符串==为输入源

利用它可以从字符串中取出整数、浮点数和字符串等等

例子

```c++
#include<stdiio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char srt[100];
    //用法一：取指定长度的字符串
    sscanf("12345","%4s",str);
    printf("%s\n",str);  //1234
    
    //用法二 ：格式化时间
    int year,month,day,hour,minute,second;
    sscanf("2020/08/19  23:32:34","%d/%d/%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
    printf("%d-%d-%d  %d:%d:%d\n",year,month,day,hour,minute,second);
    
    
    
    //用法三：读入字符串
    sscanf("12345","%s",str);
    printf("nstr= %s\n",str);
    
    
    
    
    //用法四：%*d 和 %*s   加了星号(*)  表示跳过此数据不读入，不读入参数中
    sscanf("123456acc","%*d%s",str);
    printf("nstr = %s\n",str); 
    
    
    
    //用法五：取到指定字符为止的字符串
    "%[^+]"
        
    //用法六：取到指定字符串位置的  "%[^a-z]"
}
```

### sprintf:打印到字符串中，其他数据类型转换为字符串

`int sprintf(char* string_buffer,const char* format_string,[args])`

buffer 是字符数组名， format 是格式化字符串

```c++
//控制精度
char str[20];
double f=14,30998;
sprintf(str,"%6.2f",f);


//连接多个数值
int a=20984,b=48090;
sprintf(str,"%3d%6d",a,b);
str[]="20984 48090"
    
    
    
//将多个字符串连接成串
 char str[20];
char s1[5]={'A','B','C'};
char s2[5]={'T','Y','x'};//字符串赋值方式
sprintf(str,"%.3s%.3s",s1,s2);//在字符串输出中，%m.n   m 表示宽度(字符串供占的列数)  n表示实际的字符数



//


```

