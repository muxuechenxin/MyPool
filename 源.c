#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include<stdlib.h>
#include<string.h>
/*�ַ���ƥ���㷨 BF KMP

str:����
sub:�Ӵ�
����ֵ�������Ӵ����������е��±꣬��������ڷ���-1��

*/

/*
str:����
sub���Ӵ�
pos:�����������posλ�ÿ�ʼ��
*/
void Getnext(char* sub, int* next,int LenSub)
{
	next[0] = -1;
	next[1] = 0;
	int i = 2;//��ǰ i�±�
	int k = 0;//ǰһ���nextֵK
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
	assert(str != NULL && sub != NULL);//����
	
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

	int i = pos;//��������
	int j = 0;//�����Ӵ�

	while (i < LenStr && j < LenSub) {
		//���ʹ��Getnext()����j==-1��
		//���ʹ��prefix()����j==0��
		//��Ҫ����Ϊ����next�ĵ�һλ�ֱ���-1��0��
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
	assert(str != NULL && sub != NULL);//������ִ���������˳���debug��������
	if (str == NULL || sub == NULL) {
		return -1;
	}//������assert������ͬ����Ҫ��assert�ܶ��������ͬ��

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