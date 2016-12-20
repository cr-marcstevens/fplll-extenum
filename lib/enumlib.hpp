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

#endif
