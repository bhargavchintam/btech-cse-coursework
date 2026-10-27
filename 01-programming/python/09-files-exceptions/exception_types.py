# a few common exception types
try:
    print(10 / 0)
except ZeroDivisionError:
    print('ZeroDivisionError')

try:
    print(int('x'))
except ValueError:
    print('ValueError')

try:
    print([1, 2][9])
except IndexError:
    print('IndexError')

try:
    d = {'a': 1}
    print(d['b'])
except KeyError:
    print('KeyError')

try:
    print('a' + 1)
except TypeError:
    print('TypeError')
