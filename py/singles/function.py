# function definition, takes parameters a and b
def second_binomial(a, b):
    twice_a_b = 2*a*b           # variable only in function's scope
    return a*a+ twice_a_b + b*b # return value

# main, calls function
r = second_binomial(4, 3)
print(r)
