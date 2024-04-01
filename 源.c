#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include<stdlib.h>
#include<string.h>
/*字符串匹配算法 BF KMP

str:主串
sub:子串
返回值：返回子串在主串当中的下标，如果不存在返回-1；

*/

/*
str:主串
sub：子串
pos:代表从主串的pos位置开始找
*/
void Getnext(char* sub, int* next,int LenSub)
{
	next[0] = -1;
	next[1] = 0;
	int i = 2;//当前 i下标
	int k = 0;//前一项的next值K
	while (i < LenSub) { 
		if (k == -1 || sub[i - 1] == sub[k]) {
			next[i] = k+1;
			i++;
			k++;
		}
		else {
			k = next[k];
		}
	}
}

void prefix(char* pattern, int* next, int n) {
	next[0] = 0;
	int len = 0;
	int i = 1;
	while (i < n) {
		if (pattern[i] == pattern[len]) {
			len++;
			next[i] = len;
			i++;
		}
		else {
			if(len>0)
				len = next[len - 1];
			else {
				next[i] = len;
				i++;
			}
		}
	}
}
int KMP(char* str, char* sub, int pos)
{
	assert(str != NULL && sub != NULL);//断言
	
	int LenStr = strlen(str);
	int LenSub = strlen(sub);
	if (LenStr==0 || LenSub == 0) {
		return -1;
	}
	if (pos < 0 || pos >= LenStr) return -1;


	int* next = (int*)malloc(sizeof(int) * LenSub);
	assert(next != NULL);

	//Getnext(sub, next, LenSub);
	prefix(sub, next, LenSub);

	int i = pos;//遍历主串
	int j = 0;//遍历子串

	while (i < LenStr && j < LenSub) {
		//如果使用Getnext()这里j==-1；
		//如果使用prefix()这里j==0；
		//主要是因为俩个next的第一位分别是-1和0；
		if (j == 0 || str[i] == sub[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		} 
	} 
	if (j >= LenSub) {
		return i - j;
	}
	else return -1;
} 

int BF(char*str,char*sub)
{
	assert(str != NULL && sub != NULL);//如果出现错误会立即退出且debug告诉在哪
	if (str == NULL || sub == NULL) {
		return -1;
	}//和上述assert功能相同，主要是assert很多编译器不同意

	int LenStr = strlen(str);
	int LenSub = strlen(sub);

	int i = 0, j = 0;
	while (i < LenStr && j < LenSub) {
		if (str[i] == sub[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}

	if (j >= LenSub) {
		return i - j;
	}
	else return -1;
}

int main()
{

	printf("%d\n", BF("qqqqqweeyruehhdsjhjf", "sadhusg"));//-1
	printf("%d\n", BF("qqqqqweeyruehhdsjhjf", "q"));//0
	printf("%d\n", BF("qqqqqweeyruehhdsjhjf", "qwee"));//4
	printf("%d\n", BF("qqqqqweeyruehhdsjhjf", "jhjf"));//16
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
	printf("%d\n", KMP("qqqqqweeyruehhdsjhjf", "sadhusg",0));//-1
	printf("%d\n", KMP("qqqqqweeyruehhdsjhjf", "q",0));//0
	printf("%d\n", KMP("qqqqqweeyruehhdsjhjf", "qwee",0));//4
	printf("%d\n", KMP("qqqqqweeyruehhdsjhjf", "jhjf",0));//16
	return 0;
}