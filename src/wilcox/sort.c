
/*This is a general purpose sorting program*/

#include "wilcox.h"
void sort(double *array_ptr, double *flag_ptr, double *flag_ptr_ptr){
	int i,j;
	double temp,temp1,temp2;
	for (i=0; i<ARRAY_SIZE-1;i++){
	   for (j=i+1;j<ARRAY_SIZE;j++){
		if (*(array_ptr+i) > *(array_ptr+j) ){
			temp=*(array_ptr+i);
			temp1=*(flag_ptr+i);
			temp2=*(flag_ptr_ptr+i);
			*(array_ptr+i)=*(array_ptr+j);
			*(flag_ptr+i)=*(flag_ptr+j);
			*(flag_ptr_ptr+i)=*(flag_ptr_ptr+j);
			*(array_ptr+j)=temp;
			*(flag_ptr+j)=temp1;
			*(flag_ptr_ptr+j)=temp2;}
	    }	
	}
}

