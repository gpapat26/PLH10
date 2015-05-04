#include <stdio.h>
#include <stdlib.h>

int N = 20;


void readAnnualIncome(float *a);
void printAnnualIncome(float *a);
void calculateAnnualTax(float *a, float *b,float *c);
void printAnnualTax(float *a, float *b,float *c);
float calculate22(float a);
float calculate32(float a);
float calculate42(float a);
void printGreatestClearedIncomeAndTax(float *a, float *b,float *c);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//printf("test");
	float AnnualIncomes[N];
	float AnnualTax[N];
	float AnnualClearIncome[N];
	readAnnualIncome(AnnualIncomes);
	printAnnualIncome(AnnualIncomes);
	calculateAnnualTax(AnnualIncomes,AnnualTax,AnnualClearIncome);
	printAnnualTax(AnnualIncomes,AnnualTax,AnnualClearIncome);
	printGreatestClearedIncomeAndTax(AnnualIncomes, AnnualTax,AnnualClearIncome);
	return 0;
}

float calculate22(float a){
	float b = a-(0.22)*a;
//	printf("test %4f \n",b);
	return b;
}
float calculate32(float a){
	float b = a-(0.32)*a;
//	printf("test %4f \n",b);
	return b;
}
float calculate42(float a){
	float b = a-(0.42)*a;
//	printf("test %4f \n",b);
	return b;
}

void readAnnualIncome(float *a){
	int i;
	int amount;
	amount = 1;
	for(i=0;i<N;i++){
	//	printf("test %d \n",i);	
   //	printf("amount %d \n",amount);
    printf("please enter amount\n --->");
    scanf("%d",&amount);
		
	while (amount<0){
		
		 printf("please enter amount greater or equal to Zero \n --->");
		 scanf("%d",&amount);
		// printf("amount %d \n",amount);	
		 	
	}
	
	a[i]= amount;	
	}	
}


void printAnnualIncome(float *a){
	int i;
	for(i=0;i<N;i++){
		printf("You have entered the amount(s) %f \n",a[i]);	
	}
	printf("\n");
}

void printAnnualTax(float *a, float *b,float *c){
		int i;
	for(i=0;i<N;i++){
		printf("Amount %3.3f  is taxed for %3.3f  and is cleared to %3.3f which calculates to  %3.3f per month \n",a[i],b[i],c[i],c[i]/12);	
	}
	
}



void calculateAnnualTax(float *a,float *b,float *c){
	int i;
	float tax;
	for(i=0;i<N;i++){
	//	printf("Annual amount %4f \n",a[i]);
		

		if(a[i]>=42000){
		//	printf("Annual amount megalo %4f \n",a[i]);
			float first = calculate22(25000);
			float second =calculate32(17000);
			float num= a[i]-25000-17000;
			float third =calculate42(num);
			int clearAmount = first+ second + third;
		//	printf("Annual amount megalo tax %4f \n",tax);
			c[i]=clearAmount;
			tax= a[i]-clearAmount;
			b[i]=tax;
				
		}
		else if(a[i]<42000 && a[i]>25000){
			//printf("Annual amount  mesaio %f \n",a[i]);
			
			float first = calculate22(25000);
			float second =calculate32(a[i]-25000);
		
			int clearAmount = first+ second ;
		//	printf("Annual amount mesaio tax %4f \n",tax);
			c[i]=clearAmount;
			
			tax= a[i]-clearAmount;
			b[i]=tax;
			
				
		}else{
			//printf("Annual amount mikro %f \n",a[i]);
			float first = calculate22(a[i]);
			int clearAmount = first;
		   // printf("Annual amount mikro tax %4f \n",tax);	
		   	c[i]=clearAmount;
		   	
		   	tax= a[i]-clearAmount;
		   	b[i]=tax;
			
		}		
		
			
	}
	
}

void printGreatestClearedIncomeAndTax(float *a, float *b,float *c){	
	
	int i=0;
	float maxClearedIncome=c[0];
	float maxTax=b[0];
	for (i=0;i<N-1;i++){
		int j=0;
		for(j=i+1;j<N;j++){
		   if (c[j]>maxClearedIncome){
		   		maxClearedIncome= c[j];
		   }
		   if (b[j]>maxTax){
		   		maxTax= b[j];
		   }	
		}
	}
	
	printf("The greatest cleared annual income is %3.3f  and the max tax is  %3.3f\n",maxClearedIncome,maxTax);
	
}




