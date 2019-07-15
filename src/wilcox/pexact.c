/* calculate the exact p-value*/

double psignrank (int N, double T, int alternative){
	int x,i,n=1;
	double p_value;
	int combination(int, int);
	
	x=T;
  	for(i=0;i<N;i++)
		 n*=2;
	if (alternative==0)
	    if (x>N*(N+1)/4)
		p_value=2*(1-(double)combination(x-1,N)/(double)n);
	    else 
		p_value=2*(double)combination(x,N)/(double)n;
	else 
		if (alternative==1)
		    if(x==0)
		    	p_value=1;
		    else	
			p_value=1-(double)combination(x-1,N)/(double)n;
		else
		  p_value=(double)combination(x,N)/(double)n;	/* BT 12/11/03 */
	/*   p_value=(double)combination(x-1,N)/(double)n;	*/
	return(p_value);}	    
	
/*subroutine for all kinds of combination*/
int combination(int x,int n){	
	int SUM;
	int temp1,temp2;
	int sum,sum1,max;
 	int index[1000];
 	int flag[1000];
	int *index_ptr, *f_ptr;
	int j,i,l,fac=1,m;
	double temp;
	index_ptr=index;
	f_ptr=flag;

	for (i=0;i<4;i++){
		*(index_ptr+i)=1;
		*(f_ptr+i)=1;}
       
	SUM=n*(n+1)/2;

	for(l=3;l<n+1;l++){
	  sum=l*(l+1)/2;
	  max=sum/2;
	  for(i=0;i<max-l+1;i++){
		temp1=*(f_ptr+l+i);
               	temp2=*(f_ptr+i);
  		*(index_ptr+l+i)=temp1+temp2;}

	  for(j=max+1;j<sum+1;j++){
		*(index_ptr+j)=*(index_ptr+sum-j);}
	  for(j=0;j<sum+1;j++){
   		*(f_ptr+j)=*(index_ptr+j);}
        }
   	 
	for(i=1;i<SUM+1;i++)
		*(index_ptr+i)+=*(index_ptr+i-1);
	
	return(*(index_ptr+x)); 
}
