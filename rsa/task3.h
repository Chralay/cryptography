#ifndef TASK3_H_INCLUDED
#define TASK3_H_INCLUDED
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
long long ModExp(long long b, long long m, long long n);

long long mainFuntion3(long long n){          //是否为素数（Miller）
	RandomNumber t;
	long long a;
	long long m;
	long long p;
	long long num=0;
	long long count;
	long long arr[1000];
    int flag;
	
	long long b;
	long long bb;

	count=(long long)(n*2)/3;
	p=n-1;
	
	if(n!=2 && n%2==0){
		printf("%d就2的倍数合数，不用判断，请输入一个奇数。",n);
	}
	else
	{
	 for(int i=0;i<count;i++){                 //赋不同的随机数在数组 
        arr[i]=t.get(n);	
        while(isEqual(arr,i)==1){
        	arr[i]=t.get(n);
		} 
	}
	flag=0; 
	
	while(p%2==0){//是偶数 
	  p=p/2;
	  num++;
	 }
	m=p;           //m为n-1的最大奇因子 
	
	printf("%d=2^%d * %d +1\n",n,num,m);     //测试
	for(int j=0;j<count;j++){
		printf("测试次数%3d:",j);
    if(ModExp(arr[j],m,n)==1 || ModExp(arr[j],m,n)==n-1){
    	printf("a=%d   : %d^%d mod %d = %d\n",arr[j],arr[j],m,n,ModExp(arr[j],m,n));
    	flag=1;
	}
    else{
     	bb=b=ModExp(arr[j],m,n);
     	for(int i=0;i<num;i++){
     		b=ModExp(b,2,n); 
     		if(b==1 ||b==n-1){
            break;
		 }
		}
		if(b==1 ||b==n-1){
			flag=1;
		}
		if(flag==1)printf("a=%d   : %d^2 mod %d = %d\n",arr[j],bb,n,b);
		else {
			printf("\n测试没通过");
			break;
		}
	 }
	 
	}
	
    }
    
	return 0;
}

#endif // TASK3_H_INCLUDED
