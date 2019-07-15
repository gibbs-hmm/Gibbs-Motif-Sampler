
/* ranking the differences*/

#include "wilcox.h"

double ranking(double *array_ptr, double *flag_ptr, double *flag_ptr_ptr){
	int i,j,k,ties;
	int count=0,rank=1,index=1;
	double totalrank;
	for(i=0;i<ARRAY_SIZE;i++)		/*GET THE NUMBER OF TOTAL ZERO DIFFERENCES*/
		if(*(array_ptr+i)==0.0)		/*STORED IN n_zero*/
			count+=1;
	n_zero=count;
				
	for(i=0;i<ARRAY_SIZE;i++,rank++)	/*RANKING THE DIFFERENCES*/
		*(array_ptr+i)=rank;
	
		/* OBTAIN THE SUM AND CUBE SUM OF TIES IF THEY ARE AVAILABLE*/
	for(i=0; i<ARRAY_SIZE-1;i+=index){
	   index=1;
	   ties=FALSE;	
	   totalrank=*(array_ptr+i);
	   for(j=i+1;j<ARRAY_SIZE;j++){
	        if( (*(flag_ptr+i)) == (*(flag_ptr+j)) ){	
	               	index+=1;
	        	totalrank+=*(array_ptr+j);
	        	ties=TRUE;}}
	   if(ties==TRUE){
	    	for(k=i;k<i+index;k++)
	    		*(array_ptr+k)=totalrank/(float)index;
	    	if (*(flag_ptr_ptr+i)!=0){
	   	     n_ties+=index;    	 
	   	     cub_ties+=index*index*index;}}
	}
	
	for(i=0;i<ARRAY_SIZE;i++)
		if (*(flag_ptr_ptr+i)<0)
			*(array_ptr+i)*=-1;
			
		/* CALCULATE THE SUM OF POSITIVE RANKS, IT IS ALSO THE 
		   TEST STATISTICS*/
	for(i=count;i<ARRAY_SIZE;i++)		
		if ( *(array_ptr+i) > 0)
			T_positive+=*(array_ptr+i);
		
	return(T_positive, n_zero,n_ties,cub_ties);
}

