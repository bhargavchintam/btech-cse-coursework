# main program that pulls in the other modules
import mymath
import calculator_module as calc


def run():
    print("using mymath:")
    print(" add:", mymath.add(10, 20))
    print(" factorial:", mymath.factorial(6))

    print("using calculator_module:")
    print(" mul:", calc.mul(4, 5))
    print(" div:", calc.div(9, 3))


# calculator_module's self test does not run on import, only run() does here
if __name__ == "__main__":
    run()
