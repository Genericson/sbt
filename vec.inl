/////////////////////////////////////////////////
//vec.inl
// Note: do not include this file directly, include vec.hpp
/////////////////////////////////////////////////
// Copyright (c) 2013, Harrison Leadlay
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  1) Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//  2) Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
/////////////////////////////////////////////////
// General implementation comments
//=============================================//
// Loops were used to generalize various methods (and that with minimal
// effort on my part).
//
// I did it this way(as opposed to hard-coding it in for each element for the
// common 2-4D vectors) because I didn't think it would make a difference
// with most compilers which will likely unroll those loops anyway.
//
/////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <stdexcept>

namespace sbt
{

//=============================================//
// Class vec_base
//=============================================//
template <typename T, unsigned int L>
vec_base<T, L>::vec_base ()
{
    for(unsigned int i; i < length(); i++)
        d[i] = 0;
} //vec()

template <typename T, unsigned int L>
vec_base<T, L>::vec_base (const T value)
{
    for(unsigned int i = 0u; i < length(); i++)
        d[i] =  value;
} //vec(T)

template <typename T, unsigned int L>
vec_base<T, L>::vec_base (const vec_base<T, L>& v)
{
    for(unsigned int i = 0u; i < length(); i++)
        d[i] = v[i];
} //vec(vec)

template <typename T, unsigned int L>
vec_base<T, L>::vec_base (const T v[L])
{
    for(unsigned int i = 0; i < length(); i++)
        d[i] = v[i];
} //vec(T[L])

template <typename T, unsigned int L>
vec_base<T, L>::vec_base (T c0, T c1)
{
    //if this constructor is specific for non-2D vector,
    //then compilation is aborted
    static_assert( L == 2,
                  "Template class must be Vec<T, 2u> to use vec(a, b)");

    //else, assignment
    d[0] = c0;
    d[1] = c1;
}

template <typename T, unsigned int L>
vec_base<T, L>::vec_base (T c0, T c1, T c2)
{
    //if this constructor is specific for non-3D vector,
    //then compilation is aborted
    static_assert( L == 3,
                   "Template class must be Vec<T, 3u> to use vec(a, b, c)");

    //else, assignment
    d[0] = c0;
    d[1] = c1;
    d[2] = c2;
}

template <typename T, unsigned int L>
vec_base<T, L>::vec_base (T c0, T c1, T c2, T c3)
{
    //if this constructor is specific for non-4D vector,
    //then compilation is aborted
    static_assert( L == 4,
                  "Template class must be Vec<T, 4u> to use vec(a, b, c, d)");

    //else, assignment
    d[0] = c0;
    d[1] = c1;
    d[2] = c2;
    d[3] = c3;
}

template <typename T, unsigned int L>
T& vec_base<T, L>::operator[] (const unsigned int index)
{
    return d[index];
} //operator[](uint)

template <typename T, unsigned int L>
const T& vec_base<T, L>::operator[] (const unsigned int index) const
{
    return d[index];
} //operator[](uint)

template <typename T, unsigned int L>
T vec_base<T, L>::get (const unsigned int index) const
{
    if( index < this->length())
        return d[index];
    else
        throw std::out_of_range("index too large"); //uint ensures not too small
    std::cerr<<"Could not throw out_of_range exception!\n";
} //get(uint)

template <typename T, unsigned int L>
const vec_base<T, L>& vec_base<T, L>::operator= (const vec_base<T, L>& v)
{
    for(unsigned int i = 0; i < L; i++)
        (*this)[i] = v[i];
    return *this;
} //operator=(vec)

template <typename T, unsigned int L>
const vec_base<T, L>& vec_base<T, L>::operator= (const T v[L])
{
    for(unsigned int i = 0; i < L; i++)
        (*this)[i] = v[i];
    return *this;
} //operator=(T[L])

template <typename T, unsigned int L>
bool vec_base<T, L>::operator== (const vec_base<T, L>& v) const
{
    unsigned int i = 0;
    // uses loop conditional to check if each set of components are equal
    for(; i < L && (*this)[i] == v[i]; i++)
        ;
    // returns true if loop completed (i < length() terminated loop,
    //     all component comparisons equal)
    // returns false if loop terminated (d[i] == v[i] terminated the loop,
    //     at least one set of components not equal)
    return i == L;
} //operator==(vec)

template <typename T, unsigned int L>
const unsigned int vec_base<T, L>::length() const
{
    return this->len;
} //length()


//=============================================//
// Class vec
//=============================================//

template <typename T, unsigned int L>
vec<T, L> vec<T, L>::operator+ (const vec<T, L>& v) const
{
    vec<T, L> temp;
    for(int i = 0; i < L; i++)
        temp[i] = (*this)[i] + v;
    return temp;
} //operator+(vec)

template <typename T, unsigned int L>
vec<T, L> vec<T, L>::operator- (const vec<T, L>& v) const
{
    vec<T, L> temp;
    for(int i = 0; i < L; i++)
        temp[i] = (*this)[i] - v;
    return temp;
} //operator-(vec)

template <typename T, unsigned int L>
vec<T, L> vec<T, L>::operator* (const vec<T, L>& v) const
{
    vec<T, L> temp;
    for(unsigned int i = 0; i < L; i++)
        temp[i] = v[i] * (*this)[i];
    return temp;
} //operator*(vec)

template <typename T, unsigned int L>
vec<T, L> vec<T, L>::operator* (const T& s) const
{
    vec<T, L> temp;
    for(unsigned int i = 0; i < L; i++)
        temp[i] = (*this)[i] * s;
    return temp;
} //operator*(T)

template <typename T, unsigned int L>
vec<T, L> vec<T, L>:: operator- () const
{
    vec<T, L> temp;
    for(unsigned int i = 0; i < L; i++)
    {
        temp[i] = -((*this)[i]); // works if negation is implemented for T
    }
    return temp;
} //operator-()

template <typename T, unsigned int L>
T vec<T, L>::norm() const
{
    T result = 0;
    for(unsigned int i = 0; i < L; i++)
    {
        result = ((*this)[i])*((*this)[i]) + result;
        std::cerr<<"result: "<<result<<std::endl;
    }
    return std::sqrt(result);
} //norm()

template <typename T, unsigned int L>
vec<T, L>  vec<T, L>::normalize() const
{
    T n = this->norm();
    vec<T, L> result = *this;
    for(unsigned int i = 0; i < L; i++)
    {
        result[i] = result[i] / n;
    }
    return result;
} //normalize()

template <typename T, unsigned int L>
vec<T, L>::~vec()
{

} //~vec()

//=============================================//
// STATIC FUNCTIONS
//=============================================//

template <typename T, unsigned int L>
T dot(const vec<T, L>& a, const vec<T, L>& b)
{
    T result = 0;
    for(unsigned int i = 0; i < L; i++)
    {
        result += a[i] * b[i];
    }
    return result;
} //dot(vec, vec)

template <typename T, unsigned int L>
vec<T, 3u> cross(const vec<T, 3u>& a, const vec<T, 3u>& b)
{
    vec<T, L> r;
    r[0] = a[1]*b[2] - a[2]*b[1];
    r[1] = a[2]*b[0] - a[0]*b[2];
    r[2] = a[0]*b[1] - a[1]*b[0];
    return r;
} //cross(vec3, vec3)

//=============================================//
// Bool Specialization
//=============================================//




} //namespace sbt
