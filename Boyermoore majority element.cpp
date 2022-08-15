//step 1 . find the candidate 
int maj_index = 0, count = 1; 
	for (int i = 1; i < size; i++) 
	{ 
		if (a[maj_index] == a[i]) 
			count++; 
		else
			count--; 
		if (count == 0) 
		{ 
			maj_index = i; 
			count = 1; 
		} 
	} 
int candidate = a[maj_indexx]

//step 2 , verify if its > N/2
int count = 0; 
	for (int i = 0; i < size; i++) 
  {
	  if (a[i] == cand) 
	  count++; 
  }
	if (count > size/2) 
	return 1;
	else
	return 0; 
