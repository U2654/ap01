import time
import random

# global values
size = 16
lower = 0
upper = 50

# generate array with radom numbers
def make_array():
    numbers = []
    for _ in range(size):
        numbers.append(random.randint(lower, upper));
    return numbers

# remember: numbers is array reference, not copy 
def bubble_sort(numbers):
    n = len(numbers)
    # iteration above all elements
    for i in range(n):
        # last i elements are already sorted
        # move the largest-i to correct position.
        for j in range(0, n-i-1):
            # iterate 0 to n-i-1
            # swap if is greater than the next 
            if numbers[j] > numbers[j+1]:
                tmp = numbers[j]
                numbers[j] = numbers[j+1]
                numbers[j+1] = tmp
                # this way without tmp in python:
                # numbers[j], numbers[j+1] = numbers[j+1], numbers[j]

def insertion_sort(array):
    pass

def merge_sort(array):
    pass

# generate array
numbers = make_array()
print(numbers)

# take start time for time measurement
start_time = time.time()

bubble_sort(numbers)

print(numbers)

# take end time for time measurement
end_time = time.time()
print(f"Execution time: {end_time-start_time} seconds")