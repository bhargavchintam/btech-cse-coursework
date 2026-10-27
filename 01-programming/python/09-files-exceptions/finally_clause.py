# finally always runs, error or not
try:
    print("trying")
    x = 5 / 0
except ZeroDivisionError:
    print("caught error")
finally:
    print("finally block runs")


def check(n):
    try:
        return 100 / n
    except ZeroDivisionError:
        return None
    finally:
        print("done checking", n)


print(check(5))
print(check(0))
