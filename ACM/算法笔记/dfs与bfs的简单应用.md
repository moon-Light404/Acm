

### 栈实现迷宫算法

```c++
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAZE_X 20
#define MAZE_Y 20
typedef int Status;
typedef struct{
 int x;
 int y;
}PosType;//坐标位置
typedef struct{
  int maze[MAZE_X][MAZE_Y];//迷宫地图
  PosType size;//实际的迷宫长、宽
  PosType start;//起点的坐标
  PosType end;//重点的坐标
}MazeType;
typedef struct{
 int ord; //通道块在路径上的序号；
 PosType seat;
 int di ;//通道块走向下一个通道块的方向
}SElemType;// 栈的元素类型
typedef struct{
  SElemType* base;
  SElemType* top;
  int stacksize;
}SqStack;
int InitStack(SqStack &s){
 //构造一个空栈
 s.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
 if(!s.base) exit(OVERFLOW);
 s.top=s.base;
 s.stacksize=STACK_INIT_SIZE;
 return OK;
}
int GetTop(SqStack s,SElemType &sElem){
    //如果栈不空，用sElem返回s的栈顶元素，并返回OK
    if(s.top==s.base) return ERROR;
    sElem = *(s.top-1);
    return OK;
 
}
int Push(SqStack &s,SElemType sElem){
  //插入sElem元素为新的栈顶元素
  if(s.top-s.base>=s.stacksize){
    //栈满，追加存储空间
    s.base = (SElemType*) realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
    if(!s.base) return OVERFLOW;
    s.top = s.base+s.stacksize;//重新使top指向栈顶
    s.stacksize+=STACKINCREMENT;
  }
  *s.top=sElem;
  s.top++;
  return OK;
 
}
int Pop(SqStack &s,SElemType &sElem){
   //出栈操作
   //若栈不空，则删除栈顶元素，并用sElem返回其值
   //失败返回ERROR，成功返回OK
   if(s.base==s.top) return ERROR;
   sElem=*(--s.top);
   return OK;
}
int StackLength(SqStack s){//向下方向：1
  //返回栈的元素个数，即栈的长度
  return s.top-s.base;
}
int StackEmpty(SqStack s){
     if(StackLength(s)==0) return TURE;
     else return FALSE;
}
int FootPrint(MazeType &m,PosType seat){//留下走过的标记
    m.maze[seat.x][seat.y]=2;//将走过的位置标记为2
    return TURE;
}
int MazeInit(MazeType &m){ // 初始化迷宫
    int x,y;
    printf("输入迷宫的长和宽（不超过%d）： ",MAZE_X);
    scanf("%d%d",&x,&y);//迷宫的实际长宽
    if(x>MAZE_X||x<0||y>MAZE_Y||y<0){
        printf("x,y范围不合法");
        return ERROR;}
    printf("\n请输入%d * %d 的迷宫，1代表通路，0代表墙\n",x,y);
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf("%d",&m.maze[i][j]);//初始化迷宫
        }
    }
    printf("\n请输入起点坐标：");
    scanf("%d%d",&(m.start.x),&(m.start.y));//设置起点
    printf("\n请输入终点坐标: ");
    scanf("%d%d",&(m.end.x),&(m.end.y));// 重点
    m.size.x=x;m.size.y=y;
    return OK;
}
int NextPos(MazeType m,SElemType &e,SqStack &s){//看上下左右方向是否可以走， 并且用 e 返回下一个通道的坐标
    //向下方向：1 
    //向右方向：2 
    //向上方向：3
    //向左方向：4
     if(e.seat.x<MAZE_X-1&&m.maze[e.seat.x+1][e.seat.y]==1){//如果可以向下走
            (s.top-1)->di=1;//告诉栈顶元素下一个元素的位置
            e.seat.x++;//向下走
            return TURE;}
     if(e.seat.y<MAZE_Y-1&&m.maze[e.seat.x][e.seat.y+1]==1){//向右
            (s.top-1)->di=2;
            e.seat.y++;
            return TURE;}
     if(e.seat.x>0&&m.maze[e.seat.x-1][e.seat.y]==1){// 向上
            (s.top-1)->di=3;
            e.seat.x--;
            return TURE;}
     if(e.seat.y>0&&m.maze[e.seat.x][e.seat.y-1]==1){ //向左
            (s.top-1)->di=4;
            e.seat.y--;
            return TURE;}
     return FALSE; //如果都不满足，说明当前通道是死路
     }
int MazePath(MazeType &maze , SqStack &s){
    InitStack(s);//构建一个空栈
    SElemType e;
    e.seat.x = maze.start.x; //获得初始坐标
    e.seat.y = maze.start.y;
    e.ord=1; 
       Push(s,e);
       FootPrint(maze,e.seat);
    do{
        if(NextPos(maze,e,s)){ //当前路径可以继续往下走，e 返回下一个路径的坐标
            e.ord=s.top-s.base+1;//当前步数
            Push(s,e);// 将下一个路径作为当前路径
            FootPrint(maze,e.seat);//留下痕迹
            if((e.seat.x==maze.end.x)&&(e.seat.y==maze.end.y)) return TURE;//如果到达终点，则停止
        }else{//当前路径不能往下走，死路
              Pop(s,e);//后退一步
              GetTop(s,e);//把后一步当作当前路径
        }
 
    }while(!StackEmpty(s)); //如果栈不为空，说明还有通道可以走
    return FALSE;
}
void visitmaze(MazeType m){ //查看走过后的迷宫
   for(int i=0;i<m.size.x;i++){
        printf("\n");
    for(int j=0;j<m.size.y;j++){
        printf("%d ",m.maze[i][j]);
    }
   }
}
int StackTraverse(SqStack s){
  SElemType* p=s.base;
 
  for(;p<s.top;p++){
  printf("第%d步 当前坐标:（%d,%d) 下一方向：%d \n",p->ord,(p->seat.x),(p->seat.y),p->di);
  }
 
}
int main()
{
    MazeType maze;
    SqStack s;
    MazeInit(maze);
    int i=MazePath(maze,s);
    printf("%d",i);
    visitmaze(maze);
    printf("\n");
    StackTraverse(s);
}
 
```

