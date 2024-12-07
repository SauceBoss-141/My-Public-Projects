import random


def isSorted(mylist:list):
    for i in range(len(mylist)-1):
        if mylist[i]>mylist[i+1]:
            return False
        
    return True


def bubblesort(mylist, index1=None, index2 =None):
    if isSorted(mylist)== False:
        if index1 == None and index2 == None:

            n= len(mylist)
            swapped = False
            for i in range(n-1):

                for j in range(0,n-i-1):

                    if mylist[j]> mylist[j+1]:
                        swapped = True
                        mylist[j], mylist[j+1]= mylist[j+1], mylist[j]

                if not swapped:
                    return
        else:
            n = index2
            swapped = False
            for i in range(n-1):
                for j in range(index1, n -i-1):
                    if mylist[j]> mylist[j+1]:
                        swapped = True
                        mylist[j], mylist[j+1]= mylist[j+1], mylist[j]
                if not swapped:
                    return       




def inserstionsort(mylist):

    for i in range(1, len(mylist)):

        target = mylist[i]

        j = i-1
        while j >=0 and target < mylist[j]:
            mylist[j+1]= mylist[j]
            j-=1
        mylist[j+1] = target



def merge(mylist, left, middle, right):
    n1 = middle - left +1
    n2 = right - middle

    L= [0]* n1
    R= [0]*n2
    for i in range(0,n1):
        L[i]= mylist[left+i]
    for j in range(0, n2):
        R[j]= mylist[middle +1 + j]


    i=0
    j=0
    k=left
    while i < n1 and j <n2:
        if L[i] <= R[j]:
            mylist[k]= L[i]
            i+=1
        else:
            mylist[k]= R[j]
            j+=1
        k +=1
    while i <n1:
        mylist[k] = L[i]
        i+=1
        k+=1
    while j < n2:
        mylist[k] = R[j]
        j+=1
        k+=1

def mergeSort(mylist, left, right):
    
    if( left < right):
        middle = (left+(right-1))//2

        mergeSort(mylist, left,middle)
        mergeSort(mylist, middle+1, right)
        merge(mylist, left, middle,right)





def _quick_sort(mylist, low, high):
        if low < high:
            pivot_index = partition(mylist, low, high)
            _quick_sort(mylist, low, pivot_index-1)
            _quick_sort(mylist, pivot_index+1, high)
        

def partition(mylist, low, high):
        # Find the median of the first, middle, and last elements
        mid = (high + low) // 2
        if mylist[low] < mylist[mid]:
            if mylist[mid] < mylist[high]:
                pivot_value = mid
                
            elif mylist[low] < mylist[high]:
                pivot_value = high
                
            else:
                pivot_value = low
                
        else:
            if mylist[low] < mylist[high]:
                pivot_value = low
                
            elif mylist[mid] < mylist[high]:
                pivot_value = high
                
            else:
                pivot_value = mid
                
        #pivot_index = mylist.index(pivot_value)
        # Swap pivot with the last element
        mylist[pivot_value], mylist[high] = mylist[high], mylist[pivot_value]
        pivot = mylist[high]
        
        i = low - 1
        for j in range(low, high):
            if mylist[j] <= pivot:
                i += 1
                mylist[i], mylist[j] = mylist[j], mylist[i]
        # Swap back the pivot to the correct position
        mylist[i+1], mylist[high] = mylist[high], mylist[i+1]
        return i+1



def shellSort(mylist, length):
    gap = length//2
    while gap >0:
        j = gap
        while j< length:
            i = j - gap
            while i >=0:
                if mylist[i+gap]> mylist[i]:
                    break
                else:
                    mylist[i + gap], mylist[i]= mylist[i], mylist[i+gap]
                i = i-gap
            j +=1
        gap = gap//2



