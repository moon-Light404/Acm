### 1、字典树

字典树搜索快捷，又称单词查找树，是一种树形结构，如图：

![image-20211205101704999](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202112051017139.png)

上图是一颗`trie`树，表示了集合`{'a','to', 'tea', 'ted', ' ten','i' ,'in' ,'inn'},`。

基本性质：

- 根节点不包含字符

- 从根节点到某一个节点，路径上经过的字符链接起来，为该节点对应的字符串
- 每个节点的所有子节点包含的字符不同

通常会在节点处设置一个标志，表示以该节点结尾是否构成一个字符串。



>  实现插入和查询字符串个数

### <a href = "https://www.acwing.com/activity/content/code/content/45282/"> Trie字符串统计</a>

用一个二维数组`children[p][u]`表示`p`对应的子节点`u`，这里节点的索引用`idx`表示，出现一个递增一个，`idx`用来指向链接。

`cnt[idx]`数组用来表示以`idx`索引为结尾的字符串数量，每次插入时`cnt[idx]++;`

每个节点是用索引来标记的，所以`cnt[idx]`表示以该索引为结尾的字符串数量，`children[p][u]=++idx`代表`p->u`的`u`的索引值，遍历是直接使用索引`idx`就可以了。

- 插入操作
- 查询操作

```c++
#include <iostream>
using namespace std;
const int N = 100010;
int children[N][26], cnt[N], idx;
char s[N];
// 插入
void insert(char *s) {
	int p = 0; // idx从0开始遍历，根节点没有数据
	for (int i = 0; s[i]; i++) {
		int u = s[i] - 'a';
		if (!children[p][u])
			children[p][u] = ++idx; // 增加 p->u 的边
		p = children[p][u]; // 从当前索引继续查找或插入
	}
	cnt[p]++; // 最后p代表最后字符节点的索引值
}
// c
int query(char *s) {
	int p = 0; // 从根节点开始查找
	for (int i = 0; s[i]; i++) {
		int u = s[i] - 'a';
		if (!children[p][u])
			return 0; // 中间值都不匹配，就不用往下查找了
		p = children[p][u];
	}
	return cnt[p];
}

int main() {
	int n;
	char c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'I') {
			cin >> s;
			insert(s);
		}

		else if (c == 'Q') {
			cin >> s;
			cout << query(s) << endl;
		}

	}

	return 0;
}
```

