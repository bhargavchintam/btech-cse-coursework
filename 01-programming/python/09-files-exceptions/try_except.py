# try / except basics
try:
    n = int('abc')
except ValueError:
    print('not a number')

try:
    x = 10 / 0
except ZeroDivisionError:
    print('cannot divide by zero')

# grab the error object with 'as'
try:
    lst = [1, 2, 3]
    print(lst[5])
except IndexError as e:
    print('index error:', e)
