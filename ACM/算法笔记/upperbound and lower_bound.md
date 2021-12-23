### lower_bound 和 upper_bound

都是利用二分法查找的方法再一个排好序的数组中进行查找的



lower_bound(begin,end,num)  可以是数组元素的地址

从数组的begin位置到end-1 位置查找第一个==大于或等于 num==的数字，返回该数字的地址，

不存在返回 end ，

### upper_bound(begin,end,num)

从数组的begin位置到end-1 位置二分查找==第一个大于num== 的数字，找到返回该数字的地址

不存在返回end 

应用 ==A-B problem==   

### 返回数的位置(从1开始)

假如要找 5 的位置,n是数组的长度

`(upper_bound(a,a+n,5)-a)+1`