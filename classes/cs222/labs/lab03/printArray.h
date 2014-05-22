void PrintArray(int *array, int count)
{
  LOGFILE << POS_IN_PROGRAM << "starting PrintArray();" << endl;

    for (int i=0; i<count; i++)
    {
       LOGFILE << POS_IN_PROGRAM << "printing position "<< i << endl;
        cout<< "position >" << setw(2) << setfill('0') << right << i 
	    << "< variable size >" << sizeof(*(array+i)) << "< sizeof(pointer)>" 
	    << sizeof(array) << "< address >" << array+i << "< value >" 
	    << setw(2) << setfill('0') << right << *(array+i) << "<" << endl;
    }
    cout<< "" << endl;

  LOGFILE << POS_IN_PROGRAM << "ending PrintArray();" << endl;
}
