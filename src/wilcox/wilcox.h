
#define TRUE 1
#define FALSE 0

#define DATA_SIZE 5000

	/*HYPOTHESESED MEDIAN, DEFAULT=0*/
double MU;

	/*PAIRED(1) OR SINGLE(0) SAMPLE TEST, DEFAULT=0*/
int PAIRED;

	/*ALTERNATIVE HYPOTHESIS, "0"=TWO-SIDED, "1"=GREATER, "2"=LESS, DEFAULT=0*/ 
int alternative;
		
	/*FILE THAT STORED SAMPLE DATA*/
char *filename;
		
	/*EXTERNAL VARIABLES TAHT USED IN THE FOLLOWING SUBROUTINES*/
double T_positive;		/*TEST STATISTICS, SUM OF POSITIVE RANKS*/
int  n_zero;			/*NUMBER OF ZEROS*/
int  n_ties,cub_ties;		/*NUMBER OF TIES AND CUBE TIES*/	


	/*SAMPLE SIZE N*/
int ARRAY_SIZE;
	
	/*FIRST SAMPLE*/					
double data1[DATA_SIZE];

        /*SECOND SAMPLE*/    
double data2[DATA_SIZE];

double array[DATA_SIZE];		/*ARRAY FOR THE ABSOLUTE DIFFERENCE*/
double flag[DATA_SIZE];		/*AUXILATY ARRAY*/
double flag_flag[DATA_SIZE];

	/*ARRAY POINTER*/
double *data1_ptr,*data2_ptr;
double *array_ptr, *flag_ptr,*flag_ptr_ptr;

	
	     /***************************************************************
	      * SUBROUTINES, WITH single_sample(), paired_sample() used for *
	      * data input, and sort(), ranking() USED FOR SORTING AND      *
 	      * RANKING RESPECTIVELY. psignrank() IS USED FOR CALCULATING   *
	      * THE EXACT P-VALUE, WHILE pnorm() IS USED FOR P-VALUE NORMAL * 
	      * APPROXIMATION.						    *
	      ***************************************************************/
int single_sample();		
int paired_sample();        	 
void sort();			
double ranking();
double psignrank();				
double pnorm();

int opendata(double *data1_ptr, double *data2_ptr, char *filename, int PAIRED);
