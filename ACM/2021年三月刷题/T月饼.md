### 递归写法



```c++
#include <iostream>
using namespace std;
const int N=1e4+10;
double f[N][N],c[N]; // f[i][j] 表示前i件物品总重量(且总重量 <= j)的最大价格
double a[N],b[N];
// 把吨数当成体积v,每吨都有单价c
int main(){
	int n,m;
	cin>>n>>m; // 月饼种树和最大需求量
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		cin>>b[i];
		double x=b[i],y=a[i];
		c[i]=x/y; // 单价
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
// 			f[i][j]=f[i-1][j-1];
            // f[i-1][j] 当前物品不选
			for(int k=0;k<=a[i];k++){
			    if(k <= j){
			        f[i][j]=max(f[i][j],f[i-1][j-k]+c[i]*k);
			    }
			
			}
			//cout<<f[i][m]<<endl;
		}
	}
	printf("%.2lf\n",f[n][m]);
	
}

```

