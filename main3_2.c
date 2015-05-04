#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define N 8
#define M 3

//demo: int weights[N]={10,20,15,20,5,5,15,10};

int weights[N];

//demo: int scores[N][M]={{4,5,5},{5,5,5},{5,4,4},{4,5,5},{4,3,3},{4,4,3},{4,3,4},{4,4,5}};
// { crit1{country1, country2, country3},crit2{country1.. ,},crtiteria3{}, ...}
int scores[N][M];

// demo : float finalScores[M]={4.35,4.30,4.50};
float finalScores[M]={0,0,0};

char* countries[M]={"\"country 1\"","\"country 2\"","\"country 3\""};

char* criteria[N] ={"\"Goverment Stability\"","\"National coin stability\"","\"Tax policy\"","\"Access to Markets\"",
	"\"Access to sypliers\"","\"workforce education\"","\"Culture and education\"","\"labor costs\""};


void printCriteria( char* a[]);
void read_weights();
void print_weights();
void read_scores();
void print_scores();
void best_country();
void print_best_country();
void BubbleSort();

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	

	
			
	//printCriteria(criteria);	
	read_weights();
	//print_weights();
	
	
	read_scores();
	
//	 print_scores();
	 
	 best_country();
 
	
	
	return 0;
}

void printCriteria( char* a[]){
	int i;
	for(i=0;i<N;i++){
		printf("%s \n",a[i]);
	}
}

void read_weights(){
	
	int final_sum = 0;
		int w=0;
		int sum=0;
		int i;
		
	    
	//Check if final sum is 100%
	while (final_sum != 100){
	    bool sums_dont_match=false;
	
		
		for(i=0;i<N;i++){
					
			printf("Please insert weight for criteria %s , remaining= %d  , no= %d \n -->",criteria[i],100-sum,N-i);
			scanf("%d",&w);
			
			//Check for negative values
			while(w<=0){
				printf("Please insert positive weights, remaining= %d , no= %d \n -->",100-sum,N-i);
				scanf("%d",&w);		
			}
			//Check for values over 100
			while(w >= 100){
				printf("Please insert weights less than 100 , remaining= %d , no= %d \n -->",100-sum,N-i);
				scanf("%d",&w);
				
					while(w<=0){
				printf("Please insert positive weights, remaining= %d , no= %d \n -->",100-sum,N-i);
				scanf("%d",&w);		
			}		
			}

			
			sum = sum+w;
			weights[i]=w;
			//Check if sum is greater than 100 and array is not filled up yet
			if(sum>=100 && i<N-1 && !sums_dont_match){
				printf("The final percentage does not calculate to 100  . Please re enter the weights from start \n");
				    sums_dont_match=true;
					sum=0;
					w=0;
					int j=0;
					for(j=0;j<N;j++){
						weights[j]=0;
					}
				break;	
			}							
		}
		
		i= 0;
		final_sum=sum;
		//Check if array is filled up but sum is not 100% exactly
		if (final_sum != 100 && !sums_dont_match){
			printf("The final percentage does not calculate to 100  . Please re enter the weights from start \n");
			//Clear Data, variables , conditions not met
			sum=0;
			w=0;
			sums_dont_match=true;
			int j=0;
			for(j=0;j<N;j++){
				weights[j]=0;
			}
			
			
		}
	
	
	}
				
}


void print_weights(){
	
	int j=0;
			for(j=0;j<N;j++){
				printf(" Weight : %d : %d",j,weights[j]);
				weights[j]=0;
			}
	
}

void read_scores(){
	
	int i,j;
	int input;
	
	for(i=0;i<M;i++){ //Loop Countries
		for (j=0;j<N;j++){ //Loop Grades
			do{						
			printf("Please insert grade no %d - %s for country: %s . \n Note that grade must be positive values and greater than zero. \n -->",j+1,criteria[j],countries[i]);			
			scanf("%d",&input);
			scores[j][i]=input;
			}while(input>5 || input <0);
						
			
		}
			
	}
	
}

void print_scores(){
	
	int i,j;
	int input;
	
	for(i=0;i<M;i++){ //Loop Countries
		for (j=0;j<N;j++){ //Loop Grades
							
			printf("Grade no %d -%s for country: %s is: %d \n",j+1,criteria[j],countries[i],scores[j][i]);
			
											
		}
			
	}
	
}

void best_country(){
	

	    int j;
	    int i;
		for(i=0;i<M;i++){ //Loop Countries
		int sum=0;
			for (j=0;j<N;j++){ //Loop Grades
			//printf("debug finalScores %f + scores %d weights %d \n",finalScores[i],scores[j][i],weights[j]);								
			    finalScores[i]=finalScores[i]+(scores[j][i]*weights[j]);
			    																				
			}
		
			finalScores[i]=finalScores[i]/100;
		}
		
		
		print_best_country();	
	
}


void print_best_country(){
		
 BubbleSort();
 int i;
 for(i=0;i<M;i++){
 //	printf(" value %d is %2.2f",i,finalScores[i]);
 	if (finalScores[M-1]==finalScores[i]){// M-1 value is the Max 
 	printf(" The country %s has the greatest value = %2.2f",countries[i],finalScores[i]);
 	}
 }			
	
}


void BubbleSort()
 {
 int i, j, temp;
 for (i = 0; i < (M - 1); ++i)
 {
      for (j = 0; j < M - 1 - i; ++j )
      {
           if (finalScores[j] > finalScores[j+1])
           {
                temp = finalScores[j+1];
                finalScores[j+1] = finalScores[j];
                finalScores[j] = temp;
           }
      }
 }
 }
 
   




