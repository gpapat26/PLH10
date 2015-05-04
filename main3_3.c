#include <stdio.h>
#include <stdlib.h>


double dyn(double x, int k);

double p(double *s,double x,int n);

double Horner(double *s,double x,int n);

 int N = 10;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	
	//double s[10]={1,1,1,1,1,1,1,1,1,1};	
	//Test poluonym calculation without horner
	//printf(" %lf with args  2 , 3 \n",p(s,2,3));
	//Test poluonym calculation with horner
	//printf(" %lf with args  2 , 3 \n",Horner(s,2,3));	
	
	double s[N];
	int i;
	double temp;
	double x;
	int b;
	
	printf("Plase insert the order of the polyonym \n --->");
	scanf("%d",&b);
	while(b>N || b <0){
	printf("The order can be positive , less than 10. \n --->");
	scanf("%d",&b);
	}
	
	
	for(i=0;i<N;i++){
		printf("Plase insert co-efficent a( %d ) \n --->",i);
		scanf("%lf",&temp);
		s[i]=temp;		
	}
	
	printf("Plase insert x \n --->");
	scanf("%lf",&x);


	printf("Calculate polyonym without horner: %lf  \n",p(s,x,b));
	//Test poluonym calculation with horner
	printf(" Calculate polyonym with horner: %lf \n",Horner(s,x,b));	
	
	
	return 0;
}


/*  x5 = x4*x */
double dyn(double base, int power){
	if(power==0){
		return 1;
	}
	else if(power==1){
		return base;
	}
	else{
		return dyn(base,power-1)*base;
	}
	
}

double p(double *s,double x,int n){
	
	int i;
	double sum=0;
	
	for(i=0;i<=n;i++){		
		sum=sum+s[i]*dyn(x,i);	
	//	printf("%lf - %d \n",sum,i);						
	}

	return sum;
	
}


double Horner(double * s,double x, int n)
{
  
    double dbResult = 0.;
    int i;
    for(i = 0; i <= n; i++)
    {
        dbResult = dbResult * x + s[i];
    }
    return dbResult;
}



