def function_a():
    a = 9
    return 1 + function_b()

def function_b():
    b = 8
    return 1

c = 7
print(function_a())

