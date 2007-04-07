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

#ifndef BL_TUPLE_H
#define BL_TUPLE_H

//
// $Id: Tuple.H,v 1.13 2001/07/31 22:43:19 lijewski Exp $
//

#include <cstdlib>

#include <BLassert.H>

//
//@Man:
//@Memo: Ordered Tuples for Types T
/*@Doc:

  This class represents ordered tuples of some user-specified concrete
  type T for N > 0. The type T must have a default constructor.  If the
  non-default constructor, copy constructor, or copy assignment operator
  are used, T must also have a copy constructor.
*/

template <class T, size_t N>
class Tuple
{
public:
 
    /*@ManDoc: The default constructor.  For user-defined types T, the
               default constructor for T will be run on each of the N
               objects in the Tuple.  For builtin (intrinsic) types,
               the values in the Tuple will be garbage.
    */
    Tuple ();

    /*@ManDoc: Constructs a Tuple, initializing the elements in the Tuple
               with the corresponding elements in the vector v.  This assumes
               that v contains at least N elements of type T -- an assumption
               that is NOT checked.  For user-defined types, T must have a
               well-defined and accessible copy constructor.
    */
    explicit Tuple (const T* v);
    //
    // The copy constructor.
    //
    Tuple (const Tuple& rhs);
    //
    // The copy assignment operator.
    //
    Tuple& operator= (const Tuple& rhs);
 
    /*@ManDoc: Returns a reference to the i'th element in the Tuple,
               counting from zero.  Performs range checking when the library
               is compiled in debug mode.
    */
    T& operator[] (int i);
 
    /*@ManDoc: Returns a constant reference to the i'th element in the Tuple,
               counting from zero.  Performs range checking when the library
               is compiled in debug mode.
    */
    const T& operator[] (int i) const;
 
    /*@ManDoc: Returns the address of the underlying vector of T
               representation.  This should ONLY be used when interfacing
               to Fortran as it breaks the encapsulation of the class.
    */
    operator const T* () const;

protected:
    //
    // The underlying vector of T representing the Tuple.
    //
    T vect[N];
};

template <class T, size_t N>
inline
Tuple<T,N>::Tuple()
{}

template <class T, size_t N>
inline
T&
Tuple<T,N>::operator[] (int i)
{
    BL_ASSERT(0 <= i && i < N);
    return vect[i];
}

template <class T, size_t N>
inline
const T&
Tuple<T,N>::operator[] (int i) const
{
    BL_ASSERT(0 <= i && i < N);
    return vect[i];
}

template <class T, size_t N>
inline
Tuple<T,N>::operator const T* () const
{
    return &vect[0];
}

template <class T, size_t N>
Tuple<T,N>::Tuple (const T* v)
{
    BL_ASSERT(v != 0);
    for (size_t i = 0; i < N; ++i)
        vect[i] = v[i];
}

template <class T, size_t N>
Tuple<T,N>::Tuple (const Tuple<T,N>& rhs)
{
    for (size_t i = 0; i < N; ++i)
        vect[i] = rhs.vect[i];
}

template <class T, size_t N>
Tuple<T,N>&
Tuple<T,N>::operator= (const Tuple<T,N>& rhs)
{
    for (size_t i = 0; i < N; ++i)
        vect[i] = rhs.vect[i];
    return *this;
}

#endif /*BL_TUPLE_H*/
