/* p-value noraml approximation*/

#include <stdio.h>
#include <math.h>

float pnorm(int SAMPLE_SIZE,double T_positive,int n_zero,int n_ties,int cub_ties, int alternative){
	double z_stat,m_stat,c0,c1,c2,stddev,cc,p_value;
	int c3,c4,t;
	double norm(double);
	
	c3=SAMPLE_SIZE*(SAMPLE_SIZE+1)-n_zero*(n_zero+1);
	c0=(double)c3/(double)4;
	z_stat=T_positive-c0;
	m_stat=z_stat;
	c4=SAMPLE_SIZE*(SAMPLE_SIZE+1)*(2*SAMPLE_SIZE+1)-n_zero*(n_zero+1)*(2*n_zero+1);
	c1=(double)c4/(double)24;
	c2=(double)(cub_ties-n_ties)/(double)48;
	stddev=sqrt(c1-c2);
	
	if(alternative==0){
	   if(z_stat==0)
	  	cc=0;
	   else{
	        if (z_stat<0)
	       		z_stat=-z_stat;
	   	cc=m_stat/z_stat*0.5;}}
	else{
	    if(alternative==1)
	    	cc=0.5;
	    else	    	
	    	cc=-0.5;}
	z_stat=(m_stat-cc)/stddev;
	printf("Z= %g ; \n\n", z_stat);
	
	if (alternative==0){
	    if (z_stat<0)
	       z_stat=-z_stat;
	    p_value=2*norm(-z_stat);}
	else
   	    if(alternative==1)
   	       p_value=1-norm(z_stat); 
   	    else  
   	       p_value=norm(z_stat);
   	       
	printf("    p-value = %f;    the sample size is %d\n\n",p_value, SAMPLE_SIZE);
	
}

double PI= 3.141593;
double norm(double VALUE){	
	double i;
	double normal=0.5;
	double c;
	double initial;
	double delta;
	double a=0;
	double p=0;
	double n=10e+4;
	
	if(VALUE<0)
		initial=-VALUE;
	else 
		initial=VALUE;
	c=sqrt((double)2*PI);
	delta=initial/n;
	for(i=0;i<n;i++){
	   	 a=initial-delta*i;
	   	 p=p+delta*exp((-a*a/(double)2))/c;}
	if (VALUE<0)		
		return(normal-p);
	else
		return(normal+p);
}
