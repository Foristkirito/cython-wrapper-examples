
from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

import numpy as np

setup(
    ext_modules=cythonize([
        Extension(
            'ExampleExtension',
            sources=[
                'src/stuff_wrapper.pyx',
                'src/stuff.cpp',
            ],
            include_dirs=[
                'src/',
                np.get_include(),
            ],
            extra_compile_args=['-std=c++14'],
            define_macros=[
                ('NPY_NO_DEPRECATED_API', 'NPY_1_7_API_VERSION'),
            ],
        )
    ]),
)
