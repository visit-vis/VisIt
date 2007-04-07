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

#ifndef BL_USECOUNT_H
#define BL_USECOUNT_H
//
// $Id: UseCount.H,v 1.13 2001/07/31 22:43:19 lijewski Exp $
//
#include <BLassert.H>
#include <BoxLib.H>

//
//@Man:
//@Memo: A Class Encapsulating Reference Counts
/*@Doc:

  This class encapsulates reference counts.
*/

class UseCount
{
public:
    //
    //@ManDoc: Construct a UseCount initialized to one.
    //
    UseCount ();
    //
    //@ManDoc: The copy constructor -- bumps reference count.
    //
    UseCount (const UseCount& rhs);
 
    /*@ManDoc: The assignment operator.  Increments the reference count on
               rhs, decrements the reference count on this, and then makes
               this and rhs point to the same reference count.
    */
    UseCount& operator= (const UseCount& rhs);
    //
    //@ManDoc: The destructor -- decrements the reference count.
    //
    ~UseCount ();
    //
    //@ManDoc: The UseCount is unique if the reference count == 1.
    //
    bool unique () const;
    //
    //@ManDoc: Returns the reference count.
    //
    int linkCount () const;

private:
    //
    // A pointer to the reference count.
    //
    unsigned int* cnt;
    //
    // Decrement the reference count and delete the reference
    // counter if there are no more references.
    //
    void decrement ();
};

inline
bool
UseCount::unique () const
{
    return *cnt == 1;
}

inline
int
UseCount::linkCount () const
{
    return *cnt;
}

#endif /*BL_USECOUNT_H*/
