/*****************************************************************************
*
* Copyright (c) 2000 - 2015, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#define MAX_QUANT_VECTORS 226

const float quant_vector_lookup[226][3] = {
// Bin 0 starts at index 0
    {0, 0, 1},
    {0.207912, 0, 0.978148},
    {0.406737, 0, 0.913545},
    {0.587785, 0, 0.809017},
    {0.743145, 0, 0.669131},
    {0.866025, 0, 0.5},
    {0.951057, 0, 0.309017},
    {0.994522, 0, 0.104528},
    {0.192085, 0.0795644, 0.978148},
    {0.375776, 0.155651, 0.913545},
    {0.543043, 0.224936, 0.809017},
    {0.686576, 0.284389, 0.669131},
    {0.800103, 0.331414, 0.5},
    {0.878662, 0.363954, 0.309017},
    {0.918818, 0.380587, 0.104528},
    {0.147016, 0.147016, 0.978148},
    {0.287606, 0.287606, 0.913545},
    {0.415627, 0.415627, 0.809017},
    {0.525483, 0.525483, 0.669131},
    {0.612372, 0.612372, 0.5},
    {0.672499, 0.672499, 0.309017},
    {0.703233, 0.703233, 0.104528},
    {0.0795644, 0.192085, 0.978148},
    {0.155651, 0.375776, 0.913545},
    {0.224936, 0.543043, 0.809017},
    {0.284389, 0.686576, 0.669131},
    {0.331414, 0.800103, 0.5},
    {0.363954, 0.878662, 0.309017},
    {0.380587, 0.918818, 0.104528},
// Bin 1 starts at index 29
    {-9.08811e-09, 0.207912, 0.978148},
    {-1.7779e-08, 0.406737, 0.913545},
    {-2.56929e-08, 0.587785, 0.809017},
    {-3.24839e-08, 0.743145, 0.669131},
    {-3.78552e-08, 0.866025, 0.5},
    {-4.1572e-08, 0.951057, 0.309017},
    {-4.34719e-08, 0.994522, 0.104528},
    {-0.0795644, 0.192085, 0.978148},
    {-0.155651, 0.375776, 0.913545},
    {-0.224936, 0.543043, 0.809017},
    {-0.284389, 0.686576, 0.669131},
    {-0.331414, 0.800103, 0.5},
    {-0.363954, 0.878662, 0.309017},
    {-0.380587, 0.918818, 0.104528},
    {-0.147016, 0.147016, 0.978148},
    {-0.287606, 0.287606, 0.913545},
    {-0.415627, 0.415627, 0.809017},
    {-0.525483, 0.525483, 0.669131},
    {-0.612372, 0.612372, 0.5},
    {-0.672499, 0.672499, 0.309017},
    {-0.703233, 0.703233, 0.104528},
    {-0.192085, 0.0795643, 0.978148},
    {-0.375776, 0.155651, 0.913545},
    {-0.543043, 0.224936, 0.809017},
    {-0.686576, 0.284389, 0.669131},
    {-0.800103, 0.331413, 0.5},
    {-0.878662, 0.363953, 0.309017},
    {-0.918819, 0.380587, 0.104528},
// Bin 2 starts at index 57
    {2.47932e-09, -0.207912, 0.978148},
    {4.85029e-09, -0.406737, 0.913545},
    {7.00927e-09, -0.587785, 0.809017},
    {8.86191e-09, -0.743145, 0.669131},
    {1.03273e-08, -0.866025, 0.5},
    {1.13412e-08, -0.951057, 0.309017},
    {1.18596e-08, -0.994522, 0.104528},
    {0.0795644, -0.192085, 0.978148},
    {0.155651, -0.375776, 0.913545},
    {0.224936, -0.543043, 0.809017},
    {0.284389, -0.686576, 0.669131},
    {0.331414, -0.800103, 0.5},
    {0.363954, -0.878662, 0.309017},
    {0.380587, -0.918818, 0.104528},
    {0.147016, -0.147016, 0.978148},
    {0.287606, -0.287606, 0.913545},
    {0.415627, -0.415627, 0.809017},
    {0.525483, -0.525483, 0.669131},
    {0.612373, -0.612372, 0.5},
    {0.672499, -0.672498, 0.309017},
    {0.703233, -0.703233, 0.104528},
    {0.192085, -0.0795644, 0.978148},
    {0.375776, -0.155651, 0.913545},
    {0.543043, -0.224936, 0.809017},
    {0.686576, -0.284389, 0.669131},
    {0.800103, -0.331414, 0.5},
    {0.878662, -0.363954, 0.309017},
    {0.918818, -0.380587, 0.104528},
// Bin 3 starts at index 85
    {-0.207912, -1.81762e-08, 0.978148},
    {-0.406737, -3.5558e-08, 0.913545},
    {-0.587785, -5.13858e-08, 0.809017},
    {-0.743145, -6.49678e-08, 0.669131},
    {-0.866025, -7.57104e-08, 0.5},
    {-0.951057, -8.3144e-08, 0.309017},
    {-0.994522, -8.69439e-08, 0.104528},
    {-0.192085, -0.0795644, 0.978148},
    {-0.375776, -0.155651, 0.913545},
    {-0.543043, -0.224936, 0.809017},
    {-0.686576, -0.284389, 0.669131},
    {-0.800103, -0.331414, 0.5},
    {-0.878662, -0.363954, 0.309017},
    {-0.918818, -0.380587, 0.104528},
    {-0.147016, -0.147016, 0.978148},
    {-0.287606, -0.287606, 0.913545},
    {-0.415627, -0.415627, 0.809017},
    {-0.525483, -0.525483, 0.669131},
    {-0.612372, -0.612373, 0.5},
    {-0.672498, -0.672499, 0.309017},
    {-0.703233, -0.703233, 0.104528},
    {-0.0795643, -0.192085, 0.978148},
    {-0.155651, -0.375776, 0.913545},
    {-0.224936, -0.543043, 0.809017},
    {-0.284389, -0.686576, 0.669131},
    {-0.331413, -0.800103, 0.5},
    {-0.363953, -0.878662, 0.309017},
    {-0.380587, -0.918819, 0.104528},
// Bin 4 starts at index 113
    {0, 0, -1},
    {0.994522, 0, -0.104529},
    {0.951056, 0, -0.309017},
    {0.866025, 0, -0.5},
    {0.743145, 0, -0.669131},
    {0.587785, 0, -0.809017},
    {0.406737, 0, -0.913545},
    {0.207912, 0, -0.978148},
    {0.918818, 0.380587, -0.104529},
    {0.878662, 0.363954, -0.309017},
    {0.800103, 0.331414, -0.5},
    {0.686576, 0.284389, -0.669131},
    {0.543043, 0.224936, -0.809017},
    {0.375776, 0.155651, -0.913545},
    {0.192085, 0.0795643, -0.978148},
    {0.703233, 0.703233, -0.104529},
    {0.672498, 0.672499, -0.309017},
    {0.612372, 0.612372, -0.5},
    {0.525483, 0.525483, -0.669131},
    {0.415627, 0.415627, -0.809017},
    {0.287606, 0.287606, -0.913545},
    {0.147016, 0.147016, -0.978148},
    {0.380587, 0.918818, -0.104529},
    {0.363954, 0.878662, -0.309017},
    {0.331414, 0.800103, -0.5},
    {0.284389, 0.686576, -0.669131},
    {0.224936, 0.543043, -0.809017},
    {0.155651, 0.375776, -0.913545},
    {0.0795643, 0.192085, -0.978148},
// Bin 5 starts at index 142
    {-4.34719e-08, 0.994522, -0.104529},
    {-4.1572e-08, 0.951056, -0.309017},
    {-3.78552e-08, 0.866025, -0.5},
    {-3.24839e-08, 0.743145, -0.669131},
    {-2.56929e-08, 0.587785, -0.809017},
    {-1.7779e-08, 0.406737, -0.913545},
    {-9.08811e-09, 0.207912, -0.978148},
    {-0.380587, 0.918818, -0.104529},
    {-0.363954, 0.878662, -0.309017},
    {-0.331414, 0.800103, -0.5},
    {-0.284389, 0.686576, -0.669131},
    {-0.224936, 0.543043, -0.809017},
    {-0.155651, 0.375776, -0.913545},
    {-0.0795643, 0.192085, -0.978148},
    {-0.703233, 0.703233, -0.104529},
    {-0.672498, 0.672498, -0.309017},
    {-0.612372, 0.612372, -0.5},
    {-0.525483, 0.525483, -0.669131},
    {-0.415627, 0.415627, -0.809017},
    {-0.287606, 0.287606, -0.913545},
    {-0.147016, 0.147016, -0.978148},
    {-0.918819, 0.380587, -0.104529},
    {-0.878662, 0.363953, -0.309017},
    {-0.800103, 0.331413, -0.5},
    {-0.686576, 0.284389, -0.669131},
    {-0.543043, 0.224936, -0.809017},
    {-0.375776, 0.155651, -0.913545},
    {-0.192085, 0.0795643, -0.978148},
// Bin 6 starts at index 170
    {1.18596e-08, -0.994522, -0.104529},
    {1.13412e-08, -0.951056, -0.309017},
    {1.03272e-08, -0.866025, -0.5},
    {8.86191e-09, -0.743145, -0.669131},
    {7.00927e-09, -0.587785, -0.809017},
    {4.85029e-09, -0.406737, -0.913545},
    {2.47932e-09, -0.207912, -0.978148},
    {0.380587, -0.918818, -0.104529},
    {0.363954, -0.878662, -0.309017},
    {0.331414, -0.800103, -0.5},
    {0.284389, -0.686576, -0.669131},
    {0.224936, -0.543043, -0.809017},
    {0.155651, -0.375776, -0.913545},
    {0.0795644, -0.192085, -0.978148},
    {0.703233, -0.703233, -0.104529},
    {0.672499, -0.672498, -0.309017},
    {0.612373, -0.612372, -0.5},
    {0.525483, -0.525483, -0.669131},
    {0.415627, -0.415627, -0.809017},
    {0.287606, -0.287606, -0.913545},
    {0.147016, -0.147016, -0.978148},
    {0.918818, -0.380587, -0.104529},
    {0.878662, -0.363954, -0.309017},
    {0.800103, -0.331414, -0.5},
    {0.686576, -0.284389, -0.669131},
    {0.543043, -0.224936, -0.809017},
    {0.375776, -0.155651, -0.913545},
    {0.192085, -0.0795643, -0.978148},
// Bin 7 starts at index 198
    {-0.994522, -8.69439e-08, -0.104529},
    {-0.951056, -8.3144e-08, -0.309017},
    {-0.866025, -7.57103e-08, -0.5},
    {-0.743145, -6.49678e-08, -0.669131},
    {-0.587785, -5.13858e-08, -0.809017},
    {-0.406737, -3.5558e-08, -0.913545},
    {-0.207912, -1.81762e-08, -0.978148},
    {-0.918818, -0.380587, -0.104529},
    {-0.878662, -0.363954, -0.309017},
    {-0.800103, -0.331414, -0.5},
    {-0.686576, -0.284389, -0.669131},
    {-0.543043, -0.224936, -0.809017},
    {-0.375776, -0.155651, -0.913545},
    {-0.192085, -0.0795643, -0.978148},
    {-0.703233, -0.703233, -0.104529},
    {-0.672498, -0.672499, -0.309017},
    {-0.612372, -0.612373, -0.5},
    {-0.525483, -0.525483, -0.669131},
    {-0.415627, -0.415627, -0.809017},
    {-0.287606, -0.287606, -0.913545},
    {-0.147016, -0.147016, -0.978148},
    {-0.380587, -0.918819, -0.104529},
    {-0.363953, -0.878662, -0.309017},
    {-0.331413, -0.800103, -0.5},
    {-0.284389, -0.686576, -0.669131},
    {-0.224935, -0.543043, -0.809017},
    {-0.155651, -0.375776, -0.913545},
    {-0.0795643, -0.192085, -0.978148}
};

const unsigned char quant_vector_lookup_binbounds[] = {
    0, 29, 57, 85, 113, 142, 170, 198, 226
};
