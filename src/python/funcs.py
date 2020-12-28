def foo(a, b, *args, **kwargs):
    print(a, b)
    for arg in args:
        print(arg)
    
    for key in kwargs:
        print(key, kwargs[key])

def foo2(a, b, *args, c, d):
    print(a, b, c, d)

foo(1, 2, 3, 4, 5, 6, seven = 7, nine = 9)
foo2(1, 2, c = 3, d = 5)