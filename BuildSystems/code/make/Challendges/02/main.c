#include <stdio.h>
#include "file01.h"
#include "file02.h"

int main(int argc, char** argv){
	
	long int result_nonrecursion = file01_fact_nonrecursive(10);
	long int result_recursion    = file02_fact_recursive(10);
	
	return 0;
}