//string input;
//cout<<"Please type something:"<<endl;
//getline (cin,input);



char *reverseAll(char *input)
{
    int size=0;
    char *start=input;
    char temp;
    char *y=input;

    while(*input!='\0')
    {
        input++;
        size++;
    }
    input--;

    for (int i=0;i<size/2;i++)
    {
        temp=*start;
        *start=*input;
        *input=temp;
        start++;
        input--;

    }


    return y;
}

char *reverseEach(char *input)
{
    int size=0;
    char *start=input;
    char temp;
    char *y=input;

    while (*input!='\0')
    //for (int u=0;u<4;u++)
    {
        if (*input==' '){input++;start++;}

        while (*input != ' ' && *input!='\0')
        {
            input++;
            size++;
        }

        //if(*input=='\0'){continue;}

        input--;

        for (int i = 0; i < size / 2; i++)
        {
            temp = *start;
            *start = *input;
            *input = temp;
            start++;
            input--;
        }
        start=start+size/2+1;
        input=start;
        size=0;
    }


    return y;
}