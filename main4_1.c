#include <stdio.h>
#include <stdlib.h>

#define N 3

int** Make2DIntArray(int arraySizeX, int arraySizeY);
void free2DArray(int **matrixF,int nx);
void loadMatrix(int **matrixF, int size);
void printMatrix(int **matrixF,int size);
int findFriends(int **matrixF,int size, int user);
int commonFriends(int **matrixF,int size,int user1,int user2);
int* fetchFriendsByUserId(int **matrixF,int size,int user);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int** matrixF = Make2DIntArray(N, N); 
	 		
	loadMatrix(matrixF,N);
	
	//Test Method : printMatrix(matrixF,N);
	
	free2DArray(matrixF,N);
	
	return 0;
}

void loadMatrix(int **matrixF, int size){
	//printf("test");
	int i,j,input;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(i>j){
				printf("please provide relationship between %d and %d \n",i,j);
				scanf("%d",&input);
				matrixF[i][j]=input;
				matrixF[j][i]=input;
			}
			
				if(i==j){			
				matrixF[i][j]=0;				
			}
			
		
		}		
	}
}

void printMatrix(int **matrixF,int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("item  %d , %d  = %d \n",i,j,matrixF[i][j]);	
		}		
	}
}


int** Make2DIntArray(int arraySizeX, int arraySizeY) {  
	int** theArray; 
	 
	theArray = (int**) malloc(arraySizeX*sizeof(int*));
	int i;  
	for (i = 0; i < arraySizeX; i++)  
	   theArray[i] = (int*) malloc(arraySizeY*sizeof(int));  
	return theArray;  
} 

void free2DArray(int **matrixF,int nx){
	int i;
	for (i = 0; i < nx; i++){  
       free(matrixF[i]);  
    }  
    free(matrixF);  
}

int findFriends(int **matrixF,int size, int user){
	
	int j =0;
	int i = user;
	int sum = 0;
	
	for(j=0;j<size;j++){
		//	printf("item  %d , %d  = %d \n",i,j,matrixF[i][j]);	
		if(matrixF[i][j] == 1){
			sum++;	
		}
		
	}	
	return sum;	
}

int commonFriends(int **matrixF,int size,int user1,int user2){
	
	
	int* friends1= fetchFriendsByUserId(matrixF,size,user1);
	
	int* friends2= fetchFriendsByUserId(matrixF,size,user2);
	
	//TODO
			
			
}

/* method that fetches array of friends. Array contains the id of friend or 0 if no friend */
int* fetchFriendsByUserId(int **matrixF,int size,int user){
	
		
	int j =0;
	int i = user;
	

	int friends[size];
	int *p = friends;

	
	/* */
	for(j=0;j<size;j++){
	
		if(matrixF[i][j] == 1){
		   friends[j]=j;
		}
		else{
			friends[j]= -1;
		}
		
	}	
	return 	p;
		
}







