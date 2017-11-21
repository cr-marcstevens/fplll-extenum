# fplll-extenum
External enumeration library for fplll

## Building

- Install fplll & fpylll in a virtualenv, ensure `$VIRTUAL_ENV` is set to the virtual environment directory

- `make -C lib install`

## Usage

In a C++ program:

```
#include <fplll/enumlib.hpp>

void activate_enumlib()
{
  fplll_register_enumlib();
  // enumlib_set_numthreads(4); // default is to use all logical cores
}
```

In a Python program using fpylll:

```
import ctypes
enumlib = ctypes.cdll.LoadLibrary("libfplll_enumlib.so")
enumlib.fplll_register_enumlib()
#enumlib.enumlib_set_numthreads(4) # default is to use all logical cores
```
