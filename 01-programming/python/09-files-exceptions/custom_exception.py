# making our own exception
class TooSmall(Exception):
    pass


def check_age(a):
    if a < 18:
        raise TooSmall("age must be 18 or more")
    print("age ok:", a)


check_age(20)

try:
    check_age(15)
except TooSmall as e:
    print("error:", e)
