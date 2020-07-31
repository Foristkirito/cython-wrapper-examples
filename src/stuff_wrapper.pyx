# distutils: language = c++
# cython: language_level=3

from libcpp.vector cimport vector
from libcpp.complex cimport complex
from libcpp.set cimport set as cppset
from libcpp.string cimport string
from libcpp cimport bool
from libcpp.memory cimport unique_ptr, make_unique

cimport numpy as np

ctypedef complex[float] complex64

cdef extern from "stuff.hpp" namespace "my::cool::Namespace" nogil:
    int function(double var1, vector[complex64] ofThis, int* uce, size_t len_uce)

    int function_overload "my::cool::Namespace::function" (cppset[int] overLoadSet)


cdef extern from "stuff.hpp" namespace "my::other" nogil:
    bool templated_function[T](bool toBe, T myThing)


cdef extern from "stuff.hpp" namespace "" nogil:
    cdef cppclass _MyCoolClass "MyCoolClass":
        _MyCoolClass(bool notNullary) except +
        void loremIpsum()
        int step()
        float publicProp


def function_wrapper(double var1, np.ndarray[np.complex64_t, ndim=1] ofThis, int[::1] uce):
    return function(var1, ofThis, &uce[0], len(uce))

def overload_function_wrapper(cppset[int] overLoadSet):
    return function_overload(overLoadSet)

def templated_function_wrapper(bool toBe, string myThing):
    return templated_function[string](toBe, myThing)

cdef class MyCoolClass:
    cdef unique_ptr[_MyCoolClass] _ptr

    def __init__(self, bool notNullary):
        self._ptr = make_unique[_MyCoolClass](notNullary)

    def loremIpsum(self):
        self._ptr.get().loremIpsum()

    def step(self):
        return self._ptr.get().step()

    @property
    def publicProp(self):
        return self._ptr.get().publicProp

    @publicProp.setter
    def publicProp(self, val):
        self._ptr.get().publicProp = val
