long int file02_fact_recursive (unsigned int n){
	if (n >= 1)
        return n * file02_fact_recursive(n-1);
    else
        return 1;
}