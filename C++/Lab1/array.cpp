int greaterThan(int *arr, int n, int k)
{
    int nGreater = 0;
    for(int i = 0;i < n; i++)
    {
        if(arr[i] > k)
        nGreater++;
    }
    return nGreater;
}

bool member(int *arr, int n, int k)
{
    for(int i = 0;i < n;i++)
    {
        if(arr[i] == k)
        return true;
    }
    return false;
}

int largest(int *arr, int n, int &index)
{
    if(n <= 0)
        return 0;

    int max = arr[0];
    index = 0;
    for(int i = 1;i < n;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }

    return max; 
}

void remove(int *arr,int n, int k)
{
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == k)
        {
            for(int j = i;j < n-1;j++)
            {
                arr[j] = arr[j+1];
            }
            arr[n-1] = 0;
            break;
        }
    }
}

enum Order{
    ASCENDING,
    DESCENDING,
    CONSTANT,
    UNORDERED
};

Order ordering(int *arr, int n)
{
    if (n <= 1)
        return CONSTANT;

    bool hasIncreasing = false;
    bool hasDecreasing = false;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i-1])
            hasIncreasing = true;
        else if (arr[i] < arr[i-1])
            hasDecreasing = true;
    }

    if (hasIncreasing && hasDecreasing)
        return UNORDERED;
    if (hasIncreasing)
        return ASCENDING;
    if (hasDecreasing)
        return DESCENDING;
    
    return CONSTANT;
}

void swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void reverse(int *arr, int n)
{
    for(int i = 0;i < n/2; i++)
    {
        swap(arr[i], arr[n-1-i]);
    }
}