/*
MIT License

Copyright (c) 2016 Marc Stevens

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef ENUMLIB_EXTENUM_HPP
#define ENUMLIB_EXTENUM_HPP

#include "fplll_types.hpp"

/* -1=quiet, 0=normal, 1=verbose, 2=very verbose*/
void enumlib_set_loglevel(int level);

/* (th<=0)=auto=#cores */
void enumlib_set_numthreads(int th);

uint64_t enumlib_enumerate(int dim, fplll_float maxdist,
    std::function<extenum_cb_set_config> cbfunc,
    std::function<extenum_cb_process_sol> cbsol,
    std::function<extenum_cb_process_subsol> cbsubsol,
    bool dual, bool findsubsols
    );

extern "C" {

void fplll_register_enumlib();

}

#endif
