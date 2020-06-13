#ifndef TASK4_H_INCLUDED
#define TASK4_H_INCLUDED
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
long long ExtGCD(long long a,long long b,long long &x,long long &y);
long long getInverse(long long e,long long f);               //ģ���㷨 
long long gcd(long long a, long long b);
long long ModExp(long long b, long long m, long long n);
int miller(long long n);                                     //��rsa�������ж��Ƿ�Ϊ���� 

int mainFuntion4(long long p,long long q){                   //RSA�㷨ȫ����
	RandomNumber t;
	long long n;
	long long f;
	long long e,d;
	long long c,m,mm;
    while(miller(p)==0){
    	p++;
	}
	while(miller(q)==0){
		q++;
	}
	n=p*q;
	f=(p-1)*(q-1);
	printf("p=%lld,q=%lld,n=%lld,f=%lld\n",p,q,n,f);
	
	e=t.get(f);
	while(gcd(f,e)!=1){
		e=t.get(f);
	}
	printf("���ѡȡ��eΪ��%lld\n",e);
	
	d=getInverse(e,f);
	printf("��Ӧ��dΪ��%lld\n",d);
	
	printf("���������ģ�");
	scanf("%lld",&m);
	c=ModExp(m,e,n);
	
	printf("��Ӧ�����ģ�%lld\n",c);
	printf("��ʽ��%lld = %lld^%lld (mod%lld)\n",c,m,e,n);
	
	printf("\n������Ϊ��%lld\n",c);
	mm=ModExp(c,d,n);
	
	printf("��Ӧ������Ϊ��%lld\n",mm);
	printf("��ʽ��%lld = %lld^%lld (mod%lld)\n",mm,c,d,n);
	
	return 0;	
} 

long long gcd(long long a, long long b){
	int c;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

long long getInverse(long long e,long long f){         //ģ�� 
	long long x,y;
	long long d;
	ExtGCD(e,f,x,y);
	d=x;
	if(d<0){
		d=f+x;
	}
	return d;
}

long long ExtGCD(long long a,long long b,long long &x,long long &y)
 {
       if(b==0)
      {
          x=1;
          y=0;
         return a;
    }
     long long gcd=ExtGCD(b,a%b,x,y);
     long long x2=x,y2=y;
      x=y2;
     y=x2-(a/b)*y2;
     return gcd;
 }
 
 long long ModExp(long long b, long long m, long long n){
 	int i, j;
	long long quotient, s = 1;
    long long mm[200];
    quotient = m;
    for (i = 0; quotient != 0; i++)
    {
        mm[i] = quotient % 2;
        quotient = quotient / 2;
    }
    j = i;
    for (i = 0; i < j; i++)
    {
        if (mm[i] == 1)
        {
            s = (s * b) % n;
        }
        b = (b * b) % n;
    }
    return s;
 }
 
 int miller(long long n){
	RandomNumber t;
	long long a;
	long long m;
	long long p;
	long long num=0;
	long long count;
	long long arr[1000];
	
	long long b;
	long long bb;
	
	int flag_miller=0;                        //Ĭ�ϲ������� 
	count=(long long)(n*2)/3;
	p=n-1;
	
	if(n!=2 && n%2==0){
		flag_miller=0;                        //��������
		 
	}
	else
	{
	 for(int i=0;i<count;i++){                 //����ͬ������������� 
        arr[i]=t.get(n);	
        while(isEqual(arr,i)==1){
        	arr[i]=t.get(n);
		} 
	}
	
	while(p%2==0){//��ż�� 
	  p=p/2;
	  num++;
	 }
	m=p;           //mΪn-1����������� 
	
	for(int j=0;j<count;j++){
    if(ModExp(arr[j],m,n)==1 || ModExp(arr[j],m,n)==n-1){
    	flag_miller=1;
	}
	else if(n==2 ||n==3){
		flag_miller=1;  
	}
    else{
     	bb=b=ModExp(arr[j],m,n);
     	for(int i=0;i<num;i++){
     		b=ModExp(b,2,n); 
     		if(b==1 ||b==n-1){
			flag_miller=1;
            break;
		 }
		}
		if(b==1 ||b==n-1){
			flag_miller=1;
		}
		if(flag_miller==1){
			return flag_miller;
	}
		else {
            flag_miller=0;
            return flag_miller;
		}
	 }
	 
	}
	
    }
}

#endif // TASK4_H_INCLUDED
