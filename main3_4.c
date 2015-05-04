#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define grammes 3
#define stiles 4

int N = grammes;
int size = stiles;


void read_frequencies(int F[][N], int Q[], int size);

void invert_frequencies(int F[][N], double idf[], int size);


void report_query(int F[][N], int Q[], double idf[], double similarity[N], int size);

void print_tables(int F[][N], int Q[],double idf[]);

void print_invert_frequencies( double idf[]);


	





int main(int argc, char *argv[]) {
	
	int F[grammes][stiles];
	
	int Q[stiles];
	
	double idf[stiles];
	
	double similarity[grammes];
	
	read_frequencies(F,Q,stiles);	
	
	invert_frequencies(F, idf, stiles);
	
	report_query( F,  Q,  idf,  similarity,  size);
	
//	print_invert_frequencies(idf);
	
//	print_tables(F,Q,idf);
	
//	printf("Press any key to exit...");
//	int j;
//	scanf("%d",&j);

	
	return 0;
}

void read_frequencies(int F[][N], int Q[], int size){
	
	int i,j,f_input=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<size;j++){
			printf("Please provide Frequency ( %d , %d ) = \n --->",i,j);
			scanf("%d",&f_input);
			while(f_input<0){
				printf("Please provide positive F( %d , %d ) = \n --->",i,j);
				scanf("%d",&f_input);
				}
			F[i][j]=f_input;			
		}
	}
	
	
	for(j=0;j<size;j++){
		printf("Please provide Q( %d ) = \n --->",j);
		scanf("%d",&f_input);
		
		while(f_input<0){
		printf("Please provide positive F( %d ) = \n --->",j);
		scanf("%d",&f_input);
		}
		
		Q[j]=f_input;			
	}
	
	
	
	
	
}



void report_query(int F[][N], int Q[], double idf[], double similarity[N], int size){
	
	double TF_IDF[N][size];
	
	
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<size;j++){
		  TF_IDF[i][j]=F[i][j]*idf[j];
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<size;j++){
		  TF_IDF[i][j]=F[i][j]*idf[j];
		   printf(" TF_IDF( %d , %d ) = %lf  \n ",i ,j , TF_IDF[i][j] );
		}
	}
	
	
	double w[size];
	
	for(j=0;j<size;j++){
	 	w[j]=idf[j]*Q[j];
	}
	
	for(j=0;j<size;j++){
	 	 printf(" w( %d ) = %lf  \n ",j , w[j] );
	}
	
	double arithmitis[N] ;
	
	double sum = 0.0;
	for(i=0;i<N;i++){
	
		for(j=0;j<size;j++){
		  sum=sum+TF_IDF[i][j]*w[j];
		}
		arithmitis[i] = sum ;
		sum = 0.0;
	}
	
	for(i=0;i<N;i++){
		 printf(" arithmitis( %d ) = %lf  \n ",i , arithmitis[i] );
	}
	
	double aristero_melos_paranomasti[N];
	
	double sum2 = 0.0;
	for(i=0;i<N;i++){
		for(j=0;j<size;j++){
		  sum2 = sum2 + TF_IDF[i][j]*TF_IDF[i][j];
		}
	aristero_melos_paranomasti[i] = sqrt(sum2);
	sum2 = 0.0;	
	}
	
	
	for(i=0;i<N;i++){
		 printf(" aristero_melos_paranomasti( %d ) = %lf  \n ",i , aristero_melos_paranomasti[i] );
	}
	
	double deksi_melos_paranomasti = 0.0;
	
	double sum3 = 0.0;
	for(j=0;j<size;j++){
	 	sum3 = sum3+w[j]*w[j];
	}
	
	deksi_melos_paranomasti  = sqrt(sum3);
	
    printf(" deksi_melos_paranomasti = %lf  \n ", deksi_melos_paranomasti );
    
    
    double teliko_apotelesma[size] ;
    
    
    for(j=0;j<N;j++){
	 teliko_apotelesma[j]=arithmitis[j]/( aristero_melos_paranomasti[j]*deksi_melos_paranomasti);
	}
	
	for(j=0;j<N;j++){
	 printf(" teliko_apotelesma( %d ) = %lf  \n ",j , teliko_apotelesma[j] );
	}
    
    
  
	
	
	
	
	
	

	
	
	
	
	//similarity ---> result
	
	//F [i,j] ---> freqi,j
	//Q[i] ---> freq i,q
	//wi,j ---> F [i,j] *  idf[i]
	
	
	// w i,j * w i,q--->	
	// (F [i,j]  *  idf[i])   * (Q[i] * idf[i])
	
//	double Wij[size][N];
//	double Wiq[size] ;
//	double Mult_Wij_Wiq[size][N];
//	double Sum_Mult_Wij_Wiq=0.0;
//	double SQR_Wij[i][j];
//	double SUM_SQR_Wij=0.0;
//	double SQRT_SUM_SQR_Wij;
//	double SQR_Wiq[size];
//	double SUM_SQR_Wiq=0.0;
//	double SQRT_SUM_SQR_Wiq;
	
	
	
	//Calculate w i,j  :  w[i],[j]
//	int i,j;
//	for(i=0;i<size;i++){
////		for(j=0;j<N;j++){
//		 Wij[i][j] =F[i][j]*idf[i];
//		}
//	}
//	
//	//Calculate  w i,q : w[i]
//	for(i=0;i<size;i++){
//		Wiq[i]=Q[i]*idf[i];
//	}
//	
//		//Calculate Mult Wij Wiq
//	for(i=0;i<size;i++){
//		for(j=0;j<N;j++){
//		 Mult_Wij_Wiq[i][j] =Wij[i][j]*Wiq[i];
//		}
//	}
//		
//	//Calculate Sum_Mult_Wij_Wiq
//	for(i=0;i<size;i++){
//		for(j=0;j<N;j++){
//		 Sum_Mult_Wij_Wiq =Sum_Mult_Wij_Wiq+Mult_Wij_Wiq[i][j];
//		}
//	}
//
//
//	//End Arithmitis
//	//Calculate SQR (w [i],[j])
//	
//	for(i=0;i<size;i++){
//		for(j=0;j<N;j++){
//		 SQR_Wij[i][j] =Wij[i][j]*Wij[i][j];
//		}
//	}
//	
//	//Calculate SUM_SQR_Wij
//	
//	for(i=0;i<size;i++){
//		for(j=0;j<N;j++){
//		 SUM_SQR_Wij =SUM_SQR_Wij+SQR_Wij[i][j];
//		}
//	}
//	
//	SQRT_SUM_SQR_Wij=sqrt(SUM_SQR_Wij);
//	
//	
//	//Calculate SQR (Wiq[size]) : SQR (w i,q)
//	
//	for(i=0;i<size;i++){	
//		 SQR_Wiq[i] =Wiq[i]*Wiq[i];		
//	}
//	
//	//Calculate SUM SQR (Wiq[size]) : SUM SQR (w i,q)
//	for(i=0;i<size;i++){	
//		 SUM_SQR_Wiq =SUM_SQR_Wiq+SQR_Wiq[i];		
//	}
//	
//	
//	SQRT_SUM_SQR_Wiq=sqrt(SUM_SQR_Wiq);
//	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
}

void print_tables(int F[][N], int Q[], double idf[]){
	
	int i,j	;
	
	for(i=0;i<N;i++){
		
		for(j=0;j<size;j++){
			
			printf(" F( %d , %d ) = %d  \n ",i ,j , F[i][j] );
				
		}
	}
	
	
		for(i=0;i<size;i++){
			printf("  Q( %d ) = %d \n ",i,Q[i]);
				
		}
		
		
		for(i=0;i<size;i++){
			printf("  idf( %d ) = %lf \n ",i,idf[i]);
				
		}
		
		
		
		
}

void invert_frequencies(int F[][N], double idf[], int size){
	int i,j,sum;
	
	double result;
	
	for(i=0;i<size;i++){
		sum = 0;
		for(j=0;j<N;j++){
			if(F[j][i]!=0){
				sum =sum+1;
			}
			
			
					
		}
		if(sum!=0){
			idf[i]=(double)N/sum;
		}
		else{
			idf[i]= 0;
		}
		sum = 0;
						
	}
	
	
}


void print_invert_frequencies( double idf[]){
int i=0;	
		for(i=0;i<size;i++){
			printf("  idf( %d ) = %lf \n ",i,idf[i]);
				
		}	
}

