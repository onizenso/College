
void SortAscending (int *target, int count)
{   
    int *temp = new int[count];

    for(int loop2=0; loop2<count; loop2++)
    {
    	for(int loop1=0; loop1<count-1; loop1++)
    	{
		if(*(target+loop1)>*(target+loop1+1))
		{
  		LOGFILE << POS_IN_PROGRAM << "swapping positions "
	    	<< loop1 << " and " << loop1+1 << endl;
	    	swap(*(temp+loop1),*(target+loop1));
	    	swap(*(target+loop1),*(target+loop1+1));
	    	swap(*(target+loop1+1),*(temp+loop1));
		}
    	}
    }
}
