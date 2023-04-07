def quicksort(arr):
    # If the array is empty or has only one element, it's already sorted
    if len(arr) < 2:
        return arr
    
    # Choose a pivot element (in this case, the last element)
    pivot = arr[-1]
    
    # Create empty lists to hold the elements smaller and larger than the pivot
    smaller = []
    larger = []
    
    # Iterate through the array, adding each element to the appropriate list
    for i in range(len(arr) - 1):
        if arr[i] < pivot:
            smaller.append(arr[i])
        else:
            larger.append(arr[i])
    
    # Recursively sort the smaller and larger lists, and then combine them with the pivot
    return quicksort(smaller) + [pivot] + quicksort(larger)