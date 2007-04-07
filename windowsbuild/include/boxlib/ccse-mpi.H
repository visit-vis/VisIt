/*
** (c) 1996-2003 The Regents of the University of California (through
** E.O. Lawrence Berkeley National Laboratory), subject to approval by
** the U.S. Department of Energy.  Your use of this software is under
** license -- the license agreement is attached and included in the
** directory as license.txt or you may contact Berkeley Lab's Technology
** Transfer Department at TTD@lbl.gov.  NOTICE OF U.S. GOVERNMENT RIGHTS.
** The Software was developed under funding from the U.S. Government
** which consequently retains certain rights as follows: the
** U.S. Government has been granted for itself and others acting on its
** behalf a paid-up, nonexclusive, irrevocable, worldwide license in the
** Software to reproduce, prepare derivative works, and perform publicly
** and display publicly.  Beginning five (5) years after the date
** permission to assert copyright is obtained from the U.S. Department of
** Energy, and subject to any subsequent five (5) year renewals, the
** U.S. Government is granted for itself and others acting on its behalf
** a paid-up, nonexclusive, irrevocable, worldwide license in the
** Software to reproduce, prepare derivative works, distribute copies to
** the public, perform publicly and display publicly, and to permit
** others to do so.
*/

#ifndef BL_CCSE_MPP
#define BL_CCSE_MPP

//
// $Id: ccse-mpi.H,v 1.14 2001/12/03 22:24:54 lijewski Exp $
//

//
// This header encapsulates the MPI header.
//
// By placing <mpi.h> here we make it easier to recompile with or w/o MPI.
//

#ifdef BL_USE_MPI
#include <winstd.H>

#include <mpi.h>

namespace ParallelDescriptor
{
    template <class T>
    struct Mpi_typemap
    {
	static MPI_Datatype type();
    };
    //
    // Template functions to return MPI_Datatype depending on argument type.
    //
    template <> MPI_Datatype Mpi_typemap<char>::type();
    template <> MPI_Datatype Mpi_typemap<short>::type();
    template <> MPI_Datatype Mpi_typemap<int>::type();
    template <> MPI_Datatype Mpi_typemap<long>::type();
    template <> MPI_Datatype Mpi_typemap<unsigned char>::type();
    template <> MPI_Datatype Mpi_typemap<unsigned short>::type();
    template <> MPI_Datatype Mpi_typemap<unsigned int>::type();
    template <> MPI_Datatype Mpi_typemap<unsigned long>::type();
    template <> MPI_Datatype Mpi_typemap<float>::type();
    template <> MPI_Datatype Mpi_typemap<double>::type();

    struct Max         { static MPI_Op op(); };
    struct Min         { static MPI_Op op(); };
    struct Sum         { static MPI_Op op(); };
    struct Prod        { static MPI_Op op(); };
    struct Logical_And { static MPI_Op op(); };
    struct Boolean_And { static MPI_Op op(); };
    struct Logical_Or  { static MPI_Op op(); };
    struct Boolean_Or  { static MPI_Op op(); };
    struct Logical_XOr { static MPI_Op op(); };
    struct Boolean_XOr { static MPI_Op op(); };
}


#else

typedef int MPI_Op;
typedef int MPI_Comm;
typedef int MPI_Datatype;
struct MPI_Status {};
typedef int MPI_Request;
const int MPI_REQUEST_NULL = 0;
const int MPI_COMM_WORLD   = 0;

namespace ParallelDescriptor
{
    template <class T>
    struct Mpi_typemap
    {
	static MPI_Datatype type();
    };
}

#endif /*BL_USE_MPI*/

#endif /*BL_CCSE_MPP*/
