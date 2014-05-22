void centerstring(char *s){
    int len = strlen(s);
    int pos = (int)((50-len)/2);
    for(int i = 0; i < pos; i++)
        cout<< " ";

    cout<< s << endl;
return;
}

