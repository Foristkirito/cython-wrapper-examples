
import numpy as np
from ExampleExtension import (
    function_wrapper,
    overload_function_wrapper,
    templated_function_wrapper,
    MyCoolClass,
)

if __name__ == '__main__':

    ofThis = np.array([1+1j, 2+2j, 3+3j], dtype=np.csingle)
    uce = np.arange(1, 5).astype(np.int32)
    ret = function_wrapper(np.pi, ofThis, uce)
    print('function returned:', ret)

    overLoadSet = set(list(range(10)))
    ret = overload_function_wrapper(overLoadSet)
    print('function returned:', ret)

    ret = templated_function_wrapper(True, b"Hello")
    print('Templated function returned:', ret)

    mCC = MyCoolClass(False)
    mCC.loremIpsum()
    print('orig publicProp val:', mCC.publicProp)
    mCC.publicProp += 1
    print(' new publicProp val:', mCC.publicProp)
    print('step is:', mCC.step())
    print('next step is:', mCC.step())
