int count(int arr[], int n, int x)
    {
        int j;
        int i = binary(arr, 0, n - 1, x);

        if (i == -1)
        {
            return 0;
        }
        else
        {
            int left = 0;

            if ((i - 1) > 0)
            {
                for ( j = i - 1; j >= 0; j--)
                {
                    if (arr[j] == x)
                    {
                        left++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            int right = 0;

            if ((i + 1) < n)
            {
                for (j = i + 1; j <= n; j++)
                {
                    if (arr[j] == x)
                    {
                        right++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return left+1+right;
        }
    }

    int binary(int a[], int low, int high, int k)
    {
        if (high >= low)
        {
            int mid = (low + high) / 2;

            if (a[mid] == k)
            {
                return mid;
            }
            else if (a[mid] < k)
            {
                return binary(a, mid + 1, high, k);
            }
            else
            {
                return binary(a, low, mid - 1, k);
            }
        }

        return -1;
    }

 main()
    {
        int n,i,x;
    printf("enter array size : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("enter the element to refer : ");
         scanf("%d",&x);
        printf("%d",count(arr, n, x));
    }
