//You must enter a number set in each line individually, after the number in the file data.txt
//A record from the last program operation will exist in the results.txt file

#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

int l, k;
int algorithmSelection(int [], int , ofstream&);

int mergeT(int arr[], int left, int pivot, int right, int tempArr1[], int &counter)
{
    for(int i = left; i <= right; i++)
    {
        tempArr1[i] = arr[i];
        counter++;
    }
    int leftIndex = left;
    int rightIndex = pivot+1;
    int index = left;
    while(leftIndex <= pivot && rightIndex <= right)
    {
        if(tempArr1[leftIndex]<=tempArr1[rightIndex])
        {
            arr[index] = tempArr1[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[index] = tempArr1[rightIndex];
            rightIndex++;
        }
        index++;
        counter++;
    }
    while(leftIndex <= pivot)
    {
        arr[index] = tempArr1[leftIndex];
        index++;
        leftIndex++;
        counter++;
    }
    return counter;
}

int mergeSort(int arr[], int l, ofstream& fileWithResults, int left, int right, int tempArr1[], int counter)
{
    if(left < right)
    {
        int pivot = (left+right)/2;
        mergeSort(arr,l,fileWithResults,left,pivot,tempArr1,counter);
        mergeSort(arr,l,fileWithResults,pivot+1,right,tempArr1,counter);
        counter += mergeT(arr,left,pivot,right,tempArr1,counter);
    }
    return counter;
}

int quickSort(int arr[], int l, ofstream& fileWithResults, int left, int right, int &counter)
{
    int pivot = arr[right];
    int index = left;
    int borderline = left - 1;
    if(left >= right)
        return 0;
    while(index < right)
    {
        if(arr[index] < pivot)
        {
            borderline++;
            swap(arr[borderline],arr[index]);
        }
        index++;
        counter++;
    }
    borderline++;
    if(borderline != right)
        swap(arr[borderline],arr[right]);
    quickSort(arr,l,fileWithResults,left,borderline-1,counter);
    quickSort(arr,l,fileWithResults,borderline+1,right,counter);
    return counter;
}

int maxElement(int arr[], int l)
{
    int maxi = arr[0];
    for(int i = 1; i < l; i++)
    {
        if(maxi < arr[i])
            maxi = arr[i];
    }
    return maxi;
}

int bucketSort(int arr[], int l, ofstream& fileWithResults)
{
    int tempArr2[l];
    for(int i = 0; i < l; i++)
        tempArr2[i] = arr[i];
    clock_t start;
    double duration;
    start = clock();
    int counter = 0;
    string s = "";
    int maxi = maxElement(tempArr2, l);
    int tempArr1[maxi+1];
    for(int i = 0; i <= maxi; i++)
    {
        tempArr1[i] = 0;
        counter++;
    }
    for(int i = 0; i < l; i++)
    {
        int y = tempArr2[i];
        tempArr1[y] = tempArr1[y] + 1;
        counter++;
    }
    int index = 0;
    for(int i = 0; i <= maxi; i++)
    {
        if(tempArr1[i] > 0)
        {
            for(int j = 0; j < tempArr1[i]; j++)
            {
                tempArr2[index] = i;
                index++;
                counter++;
            }
        }
        else
            counter++;
    }
    duration = (clock() - start) / (CLOCKS_PER_SEC/1000);
    cout << "==============================================================================" << endl;
    cout << "Spins of loop: " << counter << endl;
    if(duration < 1)
        cout << "Execution time was under 1 s" << endl;
    else
        cout << "Execution time: " << duration << " s" << endl;
    fileWithResults << "Sorting by bucketSort:" << endl;
    fileWithResults << "Spins of loop: " << counter << endl;
    if(duration < 1)
        fileWithResults << "Execution time was under 1 s" << endl;
    else
        fileWithResults << "Execution time: " << duration << " s" << endl;
    fileWithResults << "===============================" << endl;
    while(s != "yes" && s != "no")
    {
        cout << "==============================================================================" << endl;
        cout << "Do you want to try a different algorithm(yes, no): ";
        cin >> s;
        if(s == "yes")
            algorithmSelection(arr, l, fileWithResults);
        else if(s == "no")
        {
            cout << "==============================================================================" << endl;
            cout << "Thank you for using this program" << endl;
            cout << "==============================================================================" << endl;
            return 0;
        }
        else
        {
            cout << "==============================================================================" << endl;
            cout << s << " is not a proper command" << endl;
            cout << "==============================================================================" << endl;
        }
    }
    return 0;
}

int bubbleSort(int arr[], int l, ofstream& fileWithResults)
{
    int tempArr2[l];
    for(int i = 0; i < l; i++)
        tempArr2[i] = arr[i];
    clock_t start;
    double duration;
    start = clock();
    int counter = 0;
    string s = "";
    for(int i = 0; i < l-1; i++)
    {
        for(int j = 0 ; j < l-1; j++)
        {
            if(tempArr2[j] > tempArr2[j+1])
                swap(tempArr2[j],tempArr2[j+1]);
            counter++;
        }
    }
    duration = (clock() - start) / (CLOCKS_PER_SEC/1000);
    cout << "==============================================================================" << endl;
    cout << "Spins of loop: " << counter << endl;
    if(duration < 1)
        cout << "Execution time was under 1 s" << endl;
    else
        cout << "Execution time: " << duration << " s" << endl;
    fileWithResults << "Sorting by bubbleSort:" << endl;
    fileWithResults << "Spins of loop: " << counter << endl;
    if(duration < 1)
        fileWithResults << "Execution time was under 1 s" << endl;
    else
        fileWithResults << "Execution time: " << duration << " s" << endl;
    fileWithResults << "===============================" << endl;
    while(s != "yes" && s != "no")
    {
        cout << "==============================================================================" << endl;
        cout << "Do you want to try a different algorithm(yes, no): ";
        cin >> s;
        if(s == "yes")
            algorithmSelection(arr, l, fileWithResults);
        else if(s == "no")
        {
            cout << "==============================================================================" << endl;
            cout << "Thank you for using this program" << endl;
            cout << "==============================================================================" << endl;
            return 0;
        }
        else
        {
            cout << "==============================================================================" << endl;
            cout << s << " is not a proper command" << endl;
            cout << "==============================================================================" << endl;
        }
    }
    return 0;
}

int insertSort(int arr[], int l, ofstream& fileWithResults)
{
    int tempArr2[l];
    for(int i = 0; i < l; i++)
        tempArr2[i] = arr[i];
    clock_t start;
    double duration;
    start = clock();
    int counter = 0;
    string s = "";
    for(int i = 1; i < l; i++)
    {
        int insertThis = tempArr2[i];
        int replaceThis = i-1;
        while(replaceThis >= 0 && tempArr2[replaceThis] > insertThis)
        {
            tempArr2[replaceThis + 1] = tempArr2[replaceThis];
            replaceThis--;
            counter++;
        }
        tempArr2[replaceThis+1] = insertThis;
    }
    duration = (clock() - start) / (CLOCKS_PER_SEC/1000);
    cout << "==============================================================================" << endl;
    cout << "Spins of loop: " << counter << endl;
    if(duration < 1)
        cout << "Execution time was under 1 s" << endl;
    else
        cout << "Execution time: " << duration << " s" << endl;
    fileWithResults << "Sorting by insertSort:" << endl;
    fileWithResults << "Spins of loop: " << counter << endl;
    if(duration < 1)
        fileWithResults << "Execution time was under 1 s" << endl;
    else
        fileWithResults << "Execution time: " << duration << " s" << endl;
    fileWithResults << "===============================" << endl;
    while(s != "yes" && s != "no")
    {
        cout << "==============================================================================" << endl;
        cout << "Do you want to try a different algorithm(yes, no): ";
        cin >> s;
        if(s == "yes")
            algorithmSelection(arr, l, fileWithResults);
        else if(s == "no")
        {
            cout << "==============================================================================" << endl;
            cout << "Thank you for using this program" << endl;
            cout << "==============================================================================" << endl;
            return 0;
        }
        else
        {
            cout << "==============================================================================" << endl;
            cout << s << " is not a proper command" << endl;
            cout << "==============================================================================" << endl;
        }
    }
    return 0;
}

int algorithmSelection(int arr[], int l, ofstream& fileWithResults)
{
    string s = "";
    int left = 0;
    int right = l-1;
    int tempArr1[l];
    int counter = 0;
    int tempArr2[l];
    for(int i = 0; i < l; i++)
        tempArr2[i] = arr[i];
    cout << "==============================================================================" << endl;
    cout << "What kind of sort algorithm would you like to use?" << endl;
    cout << "You can choose from mergeSort, quickSort, bucketSort, bubbleSort and insertSort: ";
    cin >> s;
    cout << "==============================================================================" << endl;
    if(s == "mergeSort")
    {
        clock_t start;
        double duration;
        start = clock();
        counter = mergeSort(tempArr2,l,fileWithResults,left,right,tempArr1,counter);
        duration = (clock() - start) / (CLOCKS_PER_SEC/1000);
        cout << "==============================================================================" << endl;
        cout << "Spins of loop: " << counter << endl;
        fileWithResults << "Sorting by mergeSort:" << endl;
        fileWithResults << "Spins of loop: " << counter << endl;
        if(duration < 1)
            cout << "Execution time was under 1 s" << endl;
        else
            cout << "Execution time: " << duration << " s" << endl;
        if(duration < 1)
            fileWithResults << "Execution time was under 1 s" << endl;
        else
            fileWithResults << "Execution time: " << duration << " s" << endl;
        fileWithResults << "===============================" << endl;
        while(s != "yes" && s != "no")
        {
            cout << "==============================================================================" << endl;
            cout << "Do you want to try a different algorithm(yes, no): ";
            cin >> s;
            if(s == "yes")
                algorithmSelection(arr, l, fileWithResults);
            else if(s == "no")
            {
                cout << "==============================================================================" << endl;
                cout << "Thank you for using this program" << endl;
                cout << "==============================================================================" << endl;
                return 0;
            }
            else
            {
                cout << "==============================================================================" << endl;
                cout << s << " is not a proper command" << endl;
                cout << "==============================================================================" << endl;
            }
        }
    }
    else if(s == "quickSort")
    {
        clock_t start;
        double duration;
        start = clock();
        counter = quickSort(tempArr2, l, fileWithResults, left, right, counter);
        duration = (clock() - start) / (CLOCKS_PER_SEC/1000);
        cout << "==============================================================================" << endl;
        cout << "Spins of loop: " << counter << endl;
        fileWithResults << "Sorting by quickSort:" << endl;
        fileWithResults << "Spins of loop: " << counter << endl;
        if(duration < 1)
            cout << "Execution time was under 1 s" << endl;
        else
            cout << "Execution time: " << duration << " s" << endl;
        if(duration < 1)
            fileWithResults << "Execution time was under 1 s" << endl;
        else
            fileWithResults << "Execution time: " << duration << " s" << endl;
        fileWithResults << "===============================" << endl;
        while(s != "yes" && s != "no")
        {
            cout << "==============================================================================" << endl;
            cout << "Do you want to try a different algorithm(yes, no): ";
            cin >> s;
            if(s == "yes")
                algorithmSelection(arr, l, fileWithResults);
            else if(s == "no")
            {
                cout << "==============================================================================" << endl;
                cout << "Thank you for using this program" << endl;
                cout << "==============================================================================" << endl;
                return 0;
            }
            else
            {
                cout << "==============================================================================" << endl;
                cout << s << " is not a proper command" << endl;
                cout << "==============================================================================" << endl;
            }
        }
    }
    else if(s == "bucketSort")
        bucketSort(arr, l, fileWithResults);
    else if(s == "bubbleSort")
        bubbleSort(arr, l, fileWithResults);
    else if(s == "insertSort")
        insertSort(arr, l, fileWithResults);
    else
    {
        cout << s << " is not a proper algorithm" << endl;
        algorithmSelection(arr, l, fileWithResults);
    }
    return 0;
}

main()
{
    ifstream fileWithData1;
    fileWithData1.open("data.txt");
    ofstream fileWithResults;
    fileWithResults.open("results.txt");
    while(!fileWithData1.eof())
    {
        fileWithData1 >> k;
        l++;
        if(fileWithData1.fail())
            break;
    }
    fileWithData1.close();
    int arr[l];
    ifstream fileWithData;
    fileWithData.open("data.txt");
    for(int i = 0; i < l; i++)
    {
        fileWithData >> arr[i];
    }
    fileWithData.close();
    algorithmSelection(arr, l, fileWithResults);
    fileWithResults.close();
}
