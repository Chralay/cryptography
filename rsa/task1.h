#ifndef TASK1_H_INCLUDED
#define TASK1_H_INCLUDED
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
long long ModExp(long long b, long long m, long long n);
void hello(){
printf("fsdf");
}

long long mainFuntion1(long long n){                     //����ƽ�������� 

    long long num;
    long long a;
    long long arr[100];
    long long count=0;         //�����ж��ٸ�ƽ���� 
    
    srand(time(0));
	num=(long long)(n/2)+1;

    long long ii=0;
    for(int i=1;i<=num;i++){
        printf("(+%d)^2 = %3d mod %d",i,ModExp(i,2,n),n);
        printf("\t(-%d)^2 = %3d mod %d\n",i,ModExp(-i,2,n),n);     
		if(ModExp(i,2,n)==1){
			arr[ii]=i;
			count++;
			ii++;
			if(ModExp(-i,2,n)==1){
				arr[ii]=n-i;
				count++;
				ii++;
			}
			
		}
	}
	if(count==2){
		printf("%d ������\n1 ģ %d ��ƽ�����У�\n",n,n);
        for(int i=0;i<ii;i++){
		printf("%d, ",arr[i]);
	 }		
	}
	else{
		printf("%d ��������\n1 ģ %d ��ƽ�����У�\n",n,n);
		for(int i=0;i<ii;i++){
		printf("%d, ",arr[i]);
	 }
	}

	return 0;
}
#endif // TASK1_H_INCLUDED
