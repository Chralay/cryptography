#ifndef TASK2_H_INCLUDED
#define TASK2_H_INCLUDED

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

class RandomNumber{//���ģ���2��ʼ��n-1 
public:
    RandomNumber(){
        srand(time(0));
    }
    long long get(long long end = 1){
        return rand()%(end-2)+2;
    }
};

int isEqual(long long a[],int i){
	int flag=0;//Ĭ�ϲ���� 
	for(int j=0;j<i;j++){
		if(a[j]==a[i]){
		  flag=1;
		  break;	
		}
	}
	return flag;
}


long long mainFuntion2(long long n)
{                                       //����������� 
	RandomNumber t;
    long long num;
    long long a,b;
    long long arr[1000];
    long long brr[1000];
    int flag;
    int ii;
    num=(long long)(n*2)/3;
	for(int i=0;i<num;i++){                 //����ͬ������������� 
        arr[i]=t.get(n);	
        while(isEqual(arr,i)==1){
        	arr[i]=t.get(n);
		} 
	}
    flag=1;    
	ii=0;                             //��ͬ������ͨ��������� 
    for(int i=0;i<num;i++){
    	
    	a=b=arr[i];
    	printf("���Դ���%3d a =%5d : %d^(%d) = %d mod %d\n",i+1,a,a,n,ModExp(a,n,n),n);
    	if(b!=ModExp(arr[i],n,n)){
    		flag=0;
    		brr[ii]=arr[i];
    		ii++;
		}

	} 
	if(flag==1){
			printf("������Ϊ�׵ķ�����Զ�ͨ���������ж�����������");
		}
	else{
		printf("��������Ϊ�׵ķ������û��ͨ��������һ���Ǻ�����\n");
		for(int i=0;i<ii;i++){
			printf("%d��",brr[i]);
		} 
	}
    return 0;
}
#endif // TASK2_H_INCLUDED
