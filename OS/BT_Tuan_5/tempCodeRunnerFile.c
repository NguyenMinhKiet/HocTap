 FILE* input;
    input = fopen("D:\\Code\\BT_Tuan_5\\data.txt","r");
    if (!input) return 2;
    int n = 0, dem;
    while (fscanf(input,"%d",&dem) > 0)   n++;
    int *a =(int *) malloc(n*sizeof(int));
    if (!a) return 3;