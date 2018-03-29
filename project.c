#include<stdio.h>
float **matrixA;	//for the first matrix
float **matrixB;	//for the second matrix
float **matrixRes;	//for the results of additon,multiplication and subtraction matrix
int rowA,columnA,rowB,columnB,row,column,navigate;	//rowA,columnA,rowB,columnB store sizes of A and B row and column are counters

void add()
{
	
//function to add two matrices
if((rowA==rowB)&&(columnA==columnB))
    {
    printf("A+B\n");		//Unless the dimensions are same addition not possible
    matrixRes=(float **)malloc(rowA*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixRes[row]=(float *)malloc(columnA*sizeof(float));
    for(row=0;row<rowB;row++)
    {
        for(column=0;column<columnB;column++)
        {
            matrixRes[row][column]=matrixA[row][column]+matrixB[row][column];		//Add corresponding elements
            printf("%.2f ",matrixRes[row][column]);
        }
        printf("\n");
    }
    for(row=0;row<rowA;row++)
        free(matrixRes[row]);
    free(matrixRes);
    }
else
printf("Incompatible for addition\n");
}
void sub()
{
if((rowA==rowB)&&(columnA==columnB))
    {
	//unless dimension are smae subtraction not possible
	
    printf("A-B\n");
    matrixRes=(float **)malloc(rowA*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixRes[row]=(float *)malloc(columnA*sizeof(float));		//dynamic allocation
    
    for(row=0;row<rowB;row++)
    {
        for(column=0;column<columnB;column++)
        {
            matrixRes[row][column]=matrixA[row][column]-matrixB[row][column];		//subtracting the corresponding elements
            printf("%.2f ",matrixRes[row][column]);
        }
        printf("\n");
    }
    for(row=0;row<rowA;row++)
        free(matrixRes[row]);
    free(matrixRes);
    }
else
printf("Incompatible for subtraction\n");
}


void mult()
{
if((columnA==rowB))
    {
	//for two matrices to allow for multiplication number of column of first matrix should be equal to number of rows in other matrix
    printf("A*B\n");
    matrixRes=(float **)malloc(rowA*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixRes[row]=(float *)malloc(columnB*sizeof(float));
    for(row=0;row<rowB;row++)
    {
        for(column=0;column<columnB;column++)
        {
		//code to multiply two matrices
            matrixRes[row][column]=0;
            for(navigate=0;navigate<columnA;navigate++)
            matrixRes[row][column]+=matrixA[row][navigate]*matrixB[navigate][column];
            printf("%.2f ",matrixRes[row][column]);
        }
        printf("\n");
    }
    for(row=0;row<rowA;row++)
        free(matrixRes[row]);
    free(matrixRes);
    }
else
printf("Incompatible for multiplication\n");
}


float determinant(float **matrix,int size)
{
    //A recursive function to get the determinant
    float **temp;			//the temporary matrix to store subsequent smaller matrix
    float det=0;			//initalise value of deteminant zero

    if(size==1)
    det=matrix[0][0];		//in case the matrix passed has size 1
else
    if(size==2)
    det=matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];//in case the matrix passed has size 2
else
    {

        int cctr,ictr,ctr;
    for(column=0;column<size;column++)
    {
	//now we create another matrix properly exculding the first row and the element's corresponding colummn and then find its resulting determinant
        temp=(float **)malloc((size-1)*sizeof(float));
        for(ctr=0;ctr<size-1;ctr++)
        temp[ctr]=(float *)malloc((size-1)*sizeof(float));
        for(ctr=1;ctr<size;ctr++)
        {
            cctr=0;
            for(ictr=0;ictr<size;ictr++)
            {
                if(ictr==column)
                    continue;
                temp[ctr-1][cctr]=matrix[ctr][ictr];
                cctr++;
            }
        }
            det=det+pow(-1,column)*matrix[0][column]*determinant(temp,size-1);		//pass the new matrix
        for(ctr=0;ctr<size-1;ctr++)
        free(temp[ctr]);
        free(temp);
    }
}
    return det;		//return claculated determinant
}


void matrixInverse()
{
int i, j,r,c;
    float determinant = 0;
    printf("Enter the number of rows and column for matrix M\n");
    scanf("%d%d",&r,&c);
    int mat[r][c];
    printf("Enter elements of matrix row wise:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
           scanf("%d", &mat[i][j]);
    
    printf("\nGiven matrix is:");
    for(i = 0; i < r; i++){
        printf("\n");
        
        for(j = 0; j < c; j++)
            printf("%d\t", mat[i][j]);
    }
    
    //finding determinant
    for(i = 0; i < r; i++)
        determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
    
    printf("\nInverse of matrix is: \n");
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++)
            printf("%.2f\t",((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant);
        
        printf("\n");
    }
    
   return 0;
}


void choice() {
	int n;

	printf("\nSelect...\n\n");
	printf("... 1 for matrix addition\n");
	printf("... 2 for matrix multiplication\n");
	printf("... 3 for matrix substraction\n");
	printf("... 4 for matrix inverse\n");
	printf("... 5 for matrix normal and trace\n");
	printf("... 6 for matrix transpose\n");
	printf("\nEnter your choice: ");
	scanf("%d",&n);
	printf("\n");
	switch(n)
	{
		case 1: add();
				printf("\n\n\nTime complexity is n^2");
				break;
				
		case 2: mult();
				printf("\n\n\nTime complexity is n^3");
				break;
				
		case 3: sub();
				printf("\n\n\nTime complexity is n^2");
				break;
				
		case 4: matrixInverse();
				printf("\n\n\nTime complexity is n^2");
				break;
				
		case 5: trace();
				printf("\n\n\nTime complexity is n^2");
				break;
				
		case 6: transpose1();
				break;		
				
		default: printf("Wrong choice");
	}
	
	
}

void transpose1() {

	static int array[10][10];
    int i, j, m, n;
 
    printf("Enter the number of rows and column for matrix M\n");
    scanf("%d %d", &m, &n);
    printf("Enter the matrix: \n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("The given matrix is \n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf(" %d", array[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of matrix is \n");
    for (j = 0; j < n; ++j)
    {
        for (i = 0; i < m; ++i)
        {
            printf(" %d", array[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\n\nTime complexity is n^2");
}

void trace() {

        int i, j, m, n, sum = 0, sum1 = 0, a = 0, normal;
 		printf("Enter the number of rows and column for matrix M\n");
        scanf("%d %d", &m, &n);
 		int array[m][n];
        printf("Enter the n coefficients of the matrix \n");
        for (i = 0; i < m; ++i) 
        {
            for (j = 0; j < n; ++j)
            {
                scanf("%d", &array[i][j]);
                a = array[i][j] * array[i][j];
                sum1 = sum1 + a;
            }
        }
        
        printf("\nGiven matrix is:");
    	for(i = 0; i < m; i++){
        printf("\n");
        
        for(j = 0; j < n; j++)
            printf("%d\t", array[i][j]);
    }
 
        normal = sqrt(sum1);
        printf("\nThe normal of the given matrix is = %d\n", normal);
        for (i = 0; i < m; ++i) 
        {
            sum = sum + array[i][i];
        }
 
        printf("Trace of the matrix is = %d\n", sum);
	
}

int main()
{
	printf("Welcome to matrix computation...\n\n\n\n");
    printf("Enter the number of rows and column in A\n");
    scanf("%d%d",&rowA,&columnA);
    printf("Enter the number of rows and column in B\n");
    scanf("%d%d",&rowB,&columnB);//entering sizes
    matrixA=(float **)malloc(rowA*sizeof(float));
    matrixB=(float **)malloc(rowB*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixA[row]=(float *)malloc(columnA*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixB[row]=(float *)malloc(columnB*sizeof(float));
    printf("Enter the matrix A\n");
    for(row=0;row<rowA;row++)//entering the matrices
    for(column=0;column<columnA;column++)
    scanf("%f",&matrixA[row][column]);
    printf("Enter the matrix B\n");
    for(row=0;row<rowB;row++)
    for(column=0;column<columnB;column++)
    scanf("%f",&matrixB[row][column]);
    char c = 'y';
	char *c1 = &c;
	
	choice();
	
    for(row=0;row<rowA;row++)
        free(matrixA[row]);
    for(row=0;row<rowB;row++)
        free(matrixB[row]);
    free(matrixA);
    free(matrixB);
}