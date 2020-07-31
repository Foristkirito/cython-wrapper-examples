This example shows the basics of wrapping C++.

# What's here

There are a number of functions wrapped as well as a class:
- "function" (x2)
- "templated_function"
- "MyCoolClass"

"function" shows how to resolve two C++ functions that are members of the same overload set (same name, different arguments) as well as the basics of getting arguments in, through, and out of Python/Cython/C++ functions.

"templated_function" shows how templates work for functions (classes are similar).

"MyCoolClass" shows how to wrap a class with a non-nullary constructor (has arguments in constructor function).  The unique_ptr memory management method is used to automagically release the memory at the end of the object lifetime.

# Build

The build for this example is self-contained in the setup.py file.  To build the extensions, run from the project root:

    python setup.py build_ext --inplace

The `cythonize` function is used to automatically convert `.pyx` files to `.cpp` files.  Cython knows to create Cpp files for Python 3 because of the directives at the top of the `stuff_wrapper.pyx`.

# Demo

Run the demo script from the project root:

    python run.py
