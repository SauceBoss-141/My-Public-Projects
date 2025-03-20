
import random
import sys

from matplotlib import pyplot as plt
import sort
from ast import Lambda
import timeit

sys.setrecursionlimit(100000000)
sorts = ["bubbleSort", "insertionSort", "mergeSort", "quickSort", "shellSort"]
def partially_randomized_list(n, percent_sorted):
    # Determine the number of elements to keep sorted
    num_sorted = int(n * percent_sorted)
    
    # Generate a sorted sublist
    sorted_sublist = list(range(1, num_sorted + 1))
    
    # Generate a randomized sublist
    randomized_sublist = [random.randint(1, n) for _ in range(num_sorted, n)]
    
    # Concatenate the sorted and randomized sublists
    partially_randomized = sorted_sublist + randomized_sublist
    
    # Shuffle the entire list
    random.shuffle(partially_randomized)
    
    return partially_randomized



"""
Sorter
Takes in a string whihc is the name of the sort, defined in a list above^
Needs the length of the array youd like to test,
Needs a string 'print' to print, other wise leave None
Needs a true for unoreded to have you array be unordered, leave None if you want it oreder
Needs a true for reveresed to have you array reversed, leave a None if you dont want it reversed
This method, if given the correct information will create an list and pass it into the appropriate sort
and return the average time taken to sort it. 
"""
def sorter(Sort: str, length: None, print_:None, unordered: None, reversed: None, partial: None):
    
    copylist = list(range(0,length))
    newlength = len(copylist)
    #mylist = copylist
    if(unordered == True):
         #mylist = copylist.copy()
         random.shuffle(copylist)
    if(reversed == True):
         copylist.reverse()
    if( partial == True):
         copylist = partially_randomized_list(length,0.5)
    
    timetaken = None
    if print_ == None:

        if Sort == sorts[0]:
                timetaken = timeit.timeit(lambda: sort.bubblesort(copylist), number =10)
                return timetaken/10
        elif Sort == sorts[1]:
             timetaken = timeit.timeit(lambda: sort.inserstionsort(copylist), number =10)
             return timetaken/10
        elif Sort == sorts[2]:
             timetaken = timeit.timeit(lambda: sort.mergeSort(copylist, 0 , len(copylist)-1), number =10)
             return timetaken/10
        elif Sort == sorts[3]:
             timetaken = timeit.timeit(lambda: sort._quick_sort(copylist,0,len(copylist)-1), number =10)
             return timetaken/10
        elif Sort == sorts[4]:
              timetaken = timeit.timeit(lambda: sort.shellSort(copylist, len(copylist)-1), number =10)
              
              return timetaken/10
             
    else:
         print("List before " +str(Sort)+":"+ str(copylist))
         if Sort == sorts[0]:
            timetaken = timeit.timeit(lambda: sort.bubblesort(copylist), number =10)
            print("List after sort:"+ str(copylist))
            return timetaken/10
         elif Sort == sorts[1]:
             timetaken = timeit.timeit(lambda: sort.inserstionsort(copylist), number =10)
             print("List after sort:"+ str(copylist))
             return timetaken/10
         elif Sort == sorts[2]:
             timetaken = timeit.timeit(lambda: sort.mergeSort(copylist, 0, len(copylist)-1), number =10)
             print("List after sort:"+ str(copylist))
             return timetaken/10
         elif Sort == sorts[3]:
             timetaken = timeit.timeit(lambda: sort._quick_sort(copylist,0,len(copylist)-1), number =10)
             print("List after sort:"+ str(copylist))
             return timetaken/10
         elif Sort == sorts[4]:
              timetaken = timeit.timeit(lambda: sort.shellSort(copylist, len(copylist)), number =10)
              print("List after sort:"+ str(copylist))
              return timetaken/10





"""
Inital grpahing and testing. 
Disregard, I used this in my desgin and creation.
Thank you -Jacob 

"""
def graphIt(typeSort, print_:None):
    datax=[None,None,None]
    datay=[None,None,None]
    for i in range(0,3):
         my_arr = list(range(1,300*(i+1)))
         random.shuffle(my_arr)
         datay[i]= sorter('bubbleSort', None, print_, my_arr)
         datax[i]= len(my_arr)
   

    
    plt.figure()
    plt.plot(datax,datay, c ='red', label=''+ ''+str(typeSort)+'')
   
    plt.title(str(typeSort))
    plt.xlabel("Size of list ")
    plt.ylabel("Time ")
    plt.show()




"""
This method graphs all of our sorts
Takes in a perameter for log, leave None if you dont want it log
Your multiple, so you can have your array be multiples of 100, 1000, or what have you 
A permater for if you want it to print, 'print' for print, leave None for no print
Unordered put as true or Leave as None
Reveresed put as True or Leave as None
"""
def graphThemAll(log: None ,multiple : int, printme: None, unordered: None, Reversed: None, partial: None):
    bubbledatax=[None,None,None,None,None]
    bubbledatay=[None,None,None,None,None]
    for i in range(0,5):
         
         bubbledatay[i]= sorter('bubbleSort', (i+1)*multiple, printme, unordered,Reversed, partial)
         bubbledatax[i]= multiple*(i+1)


    insertiondatax=[None,None,None,None,None]
    insertiondatay=[None,None,None,None,None]
    for i in range(0,5):
         insertiondatay[i]= sorter('insertionSort', (i+1)*multiple, printme,unordered ,Reversed, partial)
         insertiondatax[i]= multiple*(i+1)
    mergedatax=[None,None,None,None,None]
    mergedatay=[None,None,None,None,None]
    for i in range(0,5):
         
         mergedatay[i]= sorter('mergeSort', (i+1)*multiple, printme, unordered,Reversed, partial)
         mergedatax[i]= multiple*(i+1)
    quickdatax=[None,None,None,None,None]
    quickdatay=[None,None,None,None,None]
    for i in range(0,5):
         
         quickdatay[i]= sorter('quickSort', (i+1)*multiple ,printme, unordered,Reversed, partial)
         quickdatax[i]= multiple*(i+1)
    Shelldatax=[None,None,None,None,None]
    Shelldatay=[None,None,None,None,None]
    for i in range(0,5):
         
         Shelldatay[i]= sorter('shellSort', (i+1)*multiple, printme, unordered, Reversed, partial)
         Shelldatax[i]= multiple*(i+1)

    if(log != None):
          plt.figure()
          plt.loglog(bubbledatax,bubbledatay, c ='red', label=''+ 'BubbleSort')
          plt.loglog(insertiondatax,insertiondatay, c ='blue', label=''+ 'InsertionSort')
          plt.loglog(mergedatax,mergedatay, c = 'black', label = ''+ 'MergeSort')
          plt.loglog(quickdatax,quickdatay, c = 'green', label = ''+ 'QuickSort')
          plt.loglog(Shelldatax,Shelldatay, c = 'yellow', label = ''+ 'ShellSort')
          plt.xlabel("Size of list in Log: ")
          plt.ylabel("Time in Log:")
    else:
     plt.figure()
     plt.plot(bubbledatax,bubbledatay, c ='red', label=''+ 'BubbleSort')
     plt.plot(insertiondatax,insertiondatay, c ='blue', label=''+ 'InsertionSort')
     plt.plot(mergedatax,mergedatay, c = 'black', label = ''+ 'MergeSort')
     plt.plot(quickdatax,quickdatay, c = 'green', label = ''+ 'QuickSort')
     plt.plot(Shelldatax,Shelldatay, c = 'yellow', label = ''+ 'ShellSort')
     plt.xlabel("Size of list: ")
     plt.ylabel("Time:")
    if(unordered == True):
         
          plt.title('All of the Sorts: Unordered ')
    if( Reversed == True):
         plt.title('All of the Sorts: Reversed ')
    if(partial == True):
         plt.title('All the Sorts: Partialy Ordered')
    if( Reversed == None and unordered == None and partial == None):
         plt.title('All of the Sorts: ordered ')
    
         
    plt.legend(['Red: BubbleSort', 'Blue: InsertionSort','Black: MergeSort' ,'Green: QuickSort', 'Yellow: ShellSort'])
    plt.show()
graphThemAll(None, 5000,None, True, None, None)
    

"""
This method was for individual testing of eahc sort just to make sure they worked properly
"""
def individualTest():
     print("--------------------------------")
     print("Individual Sort Testing")
     print("--------------------------------")
     for i in range(0,5):
          sorter(str(sorts[i]), 1000, 'print', None, None, True)

#individualTest()

