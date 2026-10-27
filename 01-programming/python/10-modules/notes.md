# Modules

A module is just a `.py` file. Import it to use its functions in another file.

## importing

```python
import mymath              # use as mymath.add(2, 3)
import calculator_module as calc   # nickname
from mymath import sub     # bring in one name, call sub(10, 3)
from mymath import *       # bring in everything (avoid, gets messy)
```

The file must be in the same folder (or on the path) to import it.

## __name__
When you run a file directly, its `__name__` is `"__main__"`. When it gets imported,
`__name__` is the module's name instead. So this trick lets a file be both runnable
and importable:

```python
if __name__ == "__main__":
    run()      # only happens on `python3 file.py`, not on import
```

That is why `calculator_module` has a self test at the bottom but importing it from
`main_demo` does not print that test.

## useful built-ins on a module

| thing | shows |
|-------|-------|
| `dir(mymath)` | list of names inside it |
| `mymath.__name__` | the module's name |
| `help(mymath)` | its docs |

> First import compiles the module and caches it in `__pycache__/`. Later imports
> reuse the cached version. Nothing to worry about, it just speeds things up.
