###  sstream类用法

<sstream>定义了三个类: istringstream 、ostringstream 和stringstream

下面介绍流的输入和输出操作

数据类型转换

```c++
#include<string>
#include<sstream>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
stringstream sstream;
    // stringstream sstream(line) // 用字符串初始化
string strResult;
int nValue = 100;

    //将int数据类型的数据放入输入流中
sstream << nValue;
    //从sstream中抽取前面插入的int类型的值，进入string strResult
sstream >> strResult;
cout << "[cout]strResult is "<< strResult << endl;
printf("[printf]strResult is: %s\n",strResult.c_str());
return 0;
}
##结果
[cout]strResult is 100
[printf]strResult is: 100
```

```c++
stringstream sstream;
int first,second;
sstream << "456";

sstream >> first;
```



多个字符串的拼接

在stringstream中存放多个字符串

```c++
int main()
{
stringstream sstream;
sstream<< "first"<<" "<<"string,";
sstream << "second string";
cout << "strResult is:"<<sstream.str()<<endl;
//清空 sstream
sstream.str("");
sstream << "third string";
cout<< "After clear,strResult is:"<<sstream.str()<<endl;
return 0;

}
##注意: sstream.str()sstream在调用str()时，会返回临时的string对象，整个表达式结束后会被析构
如需要进一步操作对象，先把其值赋给一个string变量后再操作
```

### 结构体流输入输出

```c++
#include<bits/stdc++.h>
using namespace std;
struct Point{
     int a;
     double b;
     string name;
	 string group;
};
//流输出
ostream& operator<<(ostream& out,const Point& f)
{
	out << f.name <<" "<<f.a  <<" "<<f.b<<endl;
	out << f.group;
	return out;
 } 
 int main()
 {
 	Point f;
 	f.name = "apple";
    f.group= "sagawg";
 	f.b= 4;
 	cout<< f;
 	return 0;
 }
```

数据输入和输出过程也是数据传输的过程，数据就像流水一样。在C++标准中，将用于进行数据输出输入的类统称为流类，iostream文件包含，cin是流类istream的对象，cout是流类ostream的对象

输入流

```c#
istream & operator>>(istream &in, Point &f){
    in >> f.a >>f.b>>f.name >>f.group;
    return in;
}
```

