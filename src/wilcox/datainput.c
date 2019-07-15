/*  READ DATA FROM ASCII FILES*/

#include <stdio.h>
#include <stdlib.h>
#include "wilcox.h"

	
int opendata(double *data1_ptr, double *data2_ptr, char *filename, int PAIRED){
	FILE *fp;		/*FILE POINTER*/
	int  i,ch;		/*OTHER VARIABLE*/
	
		/*OPEN FILE TO READ*/
	fp=fopen(filename,"r");
	if (fp==NULL){ 	/*IF FILE DOES NOT EXIST*/
  		(void)printf("\n  Sorry! Cannot open this file.\n\n");
  		exit(8);}
	if((ch=fgetc(fp))==EOF){ 	/*IF FILE IS EMPTY*/
		printf("\n\n The file contains no data.\n\n");
		exit(8);}
	
		/*READ DATA AND CALCULATE THE SAMPLE SIZE*/	
	fp=fopen(filename,"r");	
	if (PAIRED==1)
		fscanf(fp,"%lf %lf",&(*(data1_ptr+ARRAY_SIZE)),&(*(data2_ptr+ARRAY_SIZE))); 
	else
		fscanf(fp,"%lf",&(*(data1_ptr+ARRAY_SIZE)));
	
	while(1){
		ch=fgetc(fp);
		if(ch==EOF)
			break;
		else{
		    ARRAY_SIZE++;
		    if (PAIRED==1)
			fscanf(fp,"%lf %lf",&(*(data1_ptr+ARRAY_SIZE)),&(*(data2_ptr+ARRAY_SIZE))); 
		    else
			fscanf(fp,"%lf",&(*(data1_ptr+ARRAY_SIZE)));
		}
	}
	/* ARRAY_SIZE+=1; */   /* BT 12/11/03 */
	fclose(fp);
	
	/*printf("\n         The input data:\n");
	for(i=0;i<ARRAY_SIZE;i++)
		printf("    %lf,  %lf\n",*(data1_ptr+i),*(data2_ptr+i));*/
	
		/*RERURN SAMPLE SIZE*/
	return(ARRAY_SIZE);
}

