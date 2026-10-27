import sys
import platform


def main():
    print("py-app running inside docker")
    print("python version:", platform.python_version())

    nums = [1, 2, 3, 4, 5]
    print("sum of", nums, "=", sum(nums))

    if len(sys.argv) > 1:
        print("args passed:", sys.argv[1:])


if __name__ == "__main__":
    main()
