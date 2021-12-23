## unordered_map容器

`unordered_map`容器和`map`容器一样，以键值对(pair类型)的形式存储数据，存储的各个键值对互不相同且不允许被修改。但由于`unordered_map`容器底层采用的是哈希表存储结构，该结构本身不具有对数据排序功能，所以不会自行对存储的键值对进行排序。



## pair使用

```c++
pair<T1,T2> p1;
pair<T1,T2> p1(v1,v2);
pair<int,string> anon;

```

变量间赋值

```c++
pair<int,double> p1;
p1.first = 1;
p1.second = 2.5;


```

生成新的pair对象

``` c++
pair<int,double> p1;
p1 = make_pair(1,1.2);
```

定义多个对象

```c++
typedef pair<string,string> Author;
Author prost("March","Proust");
Author Joy("James","Joy");
```

