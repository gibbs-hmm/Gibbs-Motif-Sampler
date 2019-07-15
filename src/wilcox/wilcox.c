/*
  ***************************************************************
  *   WILCOXON SIGNED RANK TEST FOR SINGLE OR PAIRED SAMPLES!	*
  * THE MAIN FUNCTION CALLS ABOUT 5 OTHER FUNCTIONS, WHICH ARE  *
  * dataiput.c, pnormal.c, pexact.c, ranking.c and sort.c. 	*
  *   IF YOU HAVE ANY TROUBLE WITH THIS PROGRAM, PLEASE CONTACT *
  * YAN ZHANG, CURRENTLY A GRADUATE STUDENT WORKING IN DR. 	*
  * LAWRENCE'S LAB AT WADSWORTH CENTER.  THANK YOU!!! 		*
  ***************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wilcox.h"
	
int main(int argc,char *argv[]) {
        int i;
	int file_true=0;
      	double p_value;
	char   versionStr[64];

	sprintf( versionStr, "wilcox.test 1.02 %s\n", __DATE__ );
	     
	data1_ptr=data1;
	data2_ptr=data2;
	array_ptr=array;
	flag_ptr=flag;
	flag_ptr_ptr=flag_flag;
		
		/*DETERMINE OPTIONS OF COMMAND LINE*/
	if (argc>1){
	     for(i=1;i<argc;i++){
		if (argv[i][0]=='-'){
	            switch(argv[i][1]){
			case 'p':
			case 'P':	/*PAIRED SAMPLE TEST*/
				PAIRED=1;
				break;
			
			case 's':	/*SINGLE SAMPLE TEST*/
			case 'S':	
				PAIRED=0;
				break;	
			case 'm':
			case 'M':
				MU=atof(&argv[i][2]);
				break;
			case 'g':
			case 'G':
				alternative=1;
				break;
			case 'l':
			case 'L':
				alternative=2;
				break;
		   	case 't':
		   	case 'T':
		   		alternative=0;	
		   		break;							
			default:
			       	printf("       Invalid option %s\n",argv[i]);
				exit(8);}}
		      else{
			filename=argv[i];
			file_true=1;}}}
	else{
      	        printf( "%s", versionStr );
		printf("\n  USAGE: wilcox.test <filename> [options]\n");
		printf("     <filename> = the file that stored your data\n");   
		printf("     options:\n");
		printf("       -s or -S                 -Single sample test  (default)\n");
		printf("       -p or -P                 -Paired sample test\n");
		printf("       -m<float> or -M<float>   -Hypothosesed Median (default=0)\n");
		printf("       -t or -T                 -Two-sided test (default)\n");
		printf("       -g or -G                 -Alternative hypothesis greater than the median\n");
		printf("       -l or -L                 -Alternative hypothesis less than the median\n\n\n");
		exit(8);}

	if(file_true==0){
		printf("          Please Enter File Name\n");
		printf("    USAGE: wilcox.test <filename> [options]\n");
		exit(8);}
		
	ARRAY_SIZE=opendata(data1,data2,filename,PAIRED);
	   
	for (i=0;i<ARRAY_SIZE; i++){		
	        if (PAIRED==1)
		   *(array_ptr+i)=*(data1_ptr+i)-*(data2_ptr+i)-MU;
		 else
		   *(array_ptr+i)=*(data1_ptr+i)-MU;
		*(flag_ptr_ptr+i)=*(array_ptr+i);
		*(flag_ptr+i)=*(array_ptr+i);
		
		if (*(array_ptr+i) < 0){
		    *(array_ptr+i)*=-1;
		    *(flag_ptr+i)*=-1;}}
	
		
		/* SORTING AND RANKING THE ABSOLUTE VALUE OF DIFFERENCES*/
 	sort(array,flag,flag_flag);
	ranking(array,flag,flag_flag);
		
		/*COMPUTING THE TEST STATISTICS - THE SUM OF POSITIVE RANKS*/
	/*printf("\n  Test Statistics = Sum of Positive Ranks = %lf\n\n", T_positive);*/
	   
	   /*************************************************************
	    *	IF THE SAMPLE SIZE IS NOT GREATER THAN 25, AND THERE IS *
	    *	NO ZERO OR TIES IN THE ABSOLUTE VALUE OF DIFFERENCES,   *
	    *	CALL psignrank() TO COMPUTE THE EXACT P-VALUE           *
	    *************************************************************/
	   	  
	 printf( "%s", versionStr );
	 if(ARRAY_SIZE<26 && n_zero==0 && n_ties==0){
                 p_value=psignrank(ARRAY_SIZE,T_positive,alternative);
  	         printf("\n       Exact Wilcoxon Signed-rank Test \n\n");
	         printf("    The exact p-value = %f;    the sample size = %d\n\n",p_value,ARRAY_SIZE);}
         
          /**************************************************************
           * IN OTHER SITUATIONS, SUCH AS SAMPLE SIZE LARGER THAN 25,   *
           * THERE IS ZERO OR TIES IN THE ABSOLUTE VALUE OF DIFFERENCES *
           * CALL pnorm() FOR P-VALUE NORMAL APPROXIMATION.             *
           **************************************************************/
         else{
	         printf("\n    Wilcoxon Signed-rank test with normal correction  "); 
	         pnorm(ARRAY_SIZE,T_positive,n_zero,n_ties,cub_ties,alternative);}
	if(alternative==0){   
	     printf("    alternative hypothesis: true mu is NOT equal to %f\n\n",MU);}
	else
	     if(alternative==1)
	     	printf("    alternative hypothesis: true mu is GREATER than %f\n\n",MU);
	     else
	     	printf("    alternative hypothesis: true mu is LESS than %f\n\n",MU);
		
	
	/*	free(array);
	free(flag);
	free(flag_flag); */

	return( 0 );
}
