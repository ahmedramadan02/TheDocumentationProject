long int file01_fact_nonrecursive (unsigned int n){
	if (n < 0)
		return 0;
	
	long factorial = 1;
	
	for(int i=1; i<=n; ++i)
    {
		factorial *= i;
    }
	
	return factorial;
}