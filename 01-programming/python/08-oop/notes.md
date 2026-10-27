# OOP (classes and objects)

A class is a blueprint, an object is a thing made from it.

```python
class Student:
    def __init__(self, name):
        self.name = name

    def show(self):
        print(self.name)

s = Student("Ravi")   # s is an object
s.show()
```

`self` is the object itself, always the first parameter of a method. Python passes
it automatically when you call `s.show()`.

## __init__ (constructor)
Runs automatically when you make an object. Good place to set up attributes.

## Inheritance
A class can reuse another class.

```python
class Student(Person):
    def __init__(self, name, age, roll):
        super().__init__(name, age)   # call parent's __init__
        self.roll = roll
```

`super()` calls the parent. With **multiple inheritance** the parents are searched
left to right (the MRO, method resolution order). `Child.__mro__` shows the order.

## Polymorphism
Different classes have a method with the same name (like `area()`), and you can call
it without caring which class the object is. Also covers overriding a parent method.

## Encapsulation
Hide data with a leading `__`. Then it can only be reached through methods.

```python
self.__balance = 1000   # name-mangled, a.__balance from outside fails
```

> One underscore `_x` means "please treat as private". Two underscores `__x` actually
> mangle the name to `_ClassName__x`.

## Class vs static methods

| decorator | first arg | use for |
|-----------|-----------|---------|
| (normal method) | `self` | works on one object |
| `@classmethod` | `cls` | works on the class, can build objects |
| `@staticmethod` | none | just a helper grouped in the class |

## Magic (dunder) methods
Let your objects work with built-in operators.

| method | called by |
|--------|-----------|
| `__init__` | `Thing(...)` |
| `__str__` | `print(obj)`, `str(obj)` |
| `__add__` | `a + b` |
| `__eq__` | `a == b` |
| `__len__` | `len(obj)` |

## Abstract class
`from abc import ABC, abstractmethod`. A class with an `@abstractmethod` can't be
made into an object directly, the child must fill in that method.
