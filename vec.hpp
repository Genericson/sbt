#ifndef vec_HPP_
#define vec_HPP_

/////////////////////////////////////////////////
// vec.hpp
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
//General design comments
//=============================================//
//
//
//
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// \mainpage Sumbeard's Tools (sbt)
///
/// \version    0.1a
///
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// \namespace sbt Sumbeard's Tools
/// \brief Sumbeard's tools
/// Currently only includes a vector template class
/////////////////////////////////////////////////
namespace sbt
{

//=============================================//
// Classes
//=============================================//

/////////////////////////////////////////////////
// Virtual base class for vec<T, L> that includes all methods common to all vec
// classes (e.g., vec<bool, L>, vec<T, L> have the same constructors, so those
// are inherited from vec_base
/////////////////////////////////////////////////
template <typename T, unsigned int L>
class vec_base
{
private:
    // all vec classes have len = length/dimensions/#-components
    //                      d[] = array of data (components)
    const static unsigned int len = L;
    T d[L];
public:
    vec_base ();
    vec_base (const T value);
    vec_base (const vec_base<T, L>& v);
    vec_base (const T v[L]);

    /////////////////////////////////////////////////
    /// \brief Constructor specific to 2-d vectors
    ///
    /// \param component values
    ///
    /////////////////////////////////////////////////
    vec_base (T c0, T c1);

    /////////////////////////////////////////////////
    /// \brief Constructor specific to 3-d vectors
    ///
    /// \param component values
    ///
    /////////////////////////////////////////////////
    vec_base (T c0, T c1, T c2);

    /////////////////////////////////////////////////
    /// \brief Constructor specific to 4-d vectors
    ///
    /// \param component values
    ///
    /////////////////////////////////////////////////
    vec_base (T c0, T c1, T c2, T c3);

    /////////////////////////////////////////////////
    /// \brief Access component directly (via reference).
    /// \param [in] index index of component (starting from 0)
    /// \return Reference to component at index
    /// \warning This method does not check the index to be in bounds
    ///
    /////////////////////////////////////////////////
    T& operator[] (const unsigned int index);

    /////////////////////////////////////////////////
    /// \brief Access component directly (via reference) read-only.
    /// \param [in] index index of component (starting from 0)
    /// \return Reference to component at index
    /// \warning This method does not check the index to be in bounds
    ///
    /////////////////////////////////////////////////
    const T& operator[] (const unsigned int index) const;

    /////////////////////////////////////////////////
    /// \brief Return a copy of component at index.
    /// \param  index index of component (starting from 0)
    ///
    /// \return Copy of component at index
    /// \exception out_of_bounds if index is too large
    ///
    /////////////////////////////////////////////////
    T get (const unsigned int index) const;

    /////////////////////////////////////////////////
    /// \brief Copy vector by component
    /// \param v vector to copy
    /// \return vector with value of v
    ///
    /////////////////////////////////////////////////
    const vec_base& operator= (const vec_base& v);

    /////////////////////////////////////////////////
    /// \brief Copy array to vector by component
    ///
    /// \param v array to copy
    /// \return vector with value of
    ///
    /////////////////////////////////////////////////
    const vec_base& operator= (const T v[L]);

    /////////////////////////////////////////////////
    /// \brief Equals comparison
    ///
    /// \return returns `true` if vectors are equal component-wise
    ///     `false` if any one set of components are not equal
    ///   *   <1, 2, 3> == <1, 2, 3> == true
    /// <2, 1, 3> == <1, 2, 3> == false
    ///
    /// \warning Consider floating-point error when using such types of vectors
    ///
    /////////////////////////////////////////////////
    bool operator== (const vec_base<T, L>& v) const;

    /////////////////////////////////////////////////
    /// Returns the number of components/dimensions of the vector
    /// \return length
    ///
    /////////////////////////////////////////////////
    const unsigned int length () const;
}; // class vec_base


/////////////////////////////////////////////////
/// \brief A vector (as in mathematics and physics) template class
///
/////////////////////////////////////////////////
template <typename T, unsigned int L>
class vec : public vec_base<T, L>
{
public:
    // Inherited constructors (could use this in c++11 to inherit constructors):
    //      using vec_base<T, L>::vec_base;
    // (or something similar) would work
    // otherwise( ! c++11):
    vec() : vec_base<T, L> () {}
    vec(const T value) : vec_base<T, L> (value) {}
    vec(const vec_base<T, L>& v) : vec_base<T, L>(v) {}
    vec(const T v[L]): vec_base<T, L> (v) {}
    vec(T c0, T c1) : vec_base<T, L> (c0, c1) {}
    vec(T c0, T c1, T c2) : vec_base<T, L> (c0, c1, c2) {}
    vec(T c0, T c1, T c2, T c3) : vec_base<T, L> (c0, c1, c2, c3) {}

    /////////////////////////////////////////////////
    /// \brief Vector addition
    ///
    /// \param vec to add
    /// \return sum vector
    ///
    /////////////////////////////////////////////////
    vec operator+ (const vec<T, L>& v) const;

     /////////////////////////////////////////////////
    /// \brief Vector substraction
    ///
    /// \param vec to subtract
    /// \return difference vector
    ///
    /////////////////////////////////////////////////
    vec operator- (const vec<T, L>& v) const;

    /////////////////////////////////////////////////
    /// \brief vector multiplication
    ///
    /// \param v vec to multiply
    /// \return product vector
    ///
    /////////////////////////////////////////////////
    vec operator* (const vec<T, L>& v) const;

    /////////////////////////////////////////////////
    /// \brief Multiply vector by scalar
    ///
    /// \param scalar
    /// \return product vector
    ///
    /////////////////////////////////////////////////
    vec operator* (const T& s) const;

    /////////////////////////////////////////////////
    /// \brief Vector negation
    ///
    /// \return negated vector
    ///
    /////////////////////////////////////////////////
    vec operator- () const;

    /////////////////////////////////////////////////
    /// \brief Calculates the norm/magnitude of the vector
    ///
    /// \return norm of vector
    ///
    /////////////////////////////////////////////////
    T norm() const;

    /////////////////////////////////////////////////
    /// \brief Calculates a unit vector in the direction of v
    ///
    /// \return unit normal vector
    ///
    /////////////////////////////////////////////////
    vec<T, L> normalize() const;
	
	/////////////////////////////////////////////////
	/// \brief Calculates a vector that is the difference of vectors `this` and `b`
	///
	/// \return difference vector
	/////////////////////////////////////////////////
	vec<T, L> diff( vec<T, L> b) const;
	
	/////////////////////////////////////////////////
	/// \brief Calculates a vector that spans half-way from `this` to `b`
	/// (B - A) * 0.5 
	///
	/// \return midpoint
	/////////////////////////////////////////////////
	vec<T, L> mid( vec<T, L> b) const;
	
    /////////////////////////////////////////////////
    /// \brief Destructor
    ///
    /////////////////////////////////////////////////
    ~vec();

    //=============================================//
    // STATIC FUNCTIONS
    //=============================================//

    /////////////////////////////////////////////////
    /// \brief Dot product
    ///
    /// \param a left vec argument
    /// \param b right vec argument
    /// \return dot product
    ///
    /////////////////////////////////////////////////
    static T dot(const vec<T, L>& a, const vec<T, L>& b);

    /////////////////////////////////////////////////
    /// \brief Cross product
    ///
    /// \param a left vec<T, 3u> argument
    /// \param b right vec<T, 3u> argument
    /// \return vec<T, 3u> orthogonal to a and b
    ///
    /////////////////////////////////////////////////
    static vec<T, 3u> cross(const vec<T, 3u>& a, const vec<T, 3u>& b);

}; //class vec

//=============================================//
// Class Specializations
//=============================================//

template <unsigned int L>
class vec<bool, L> :  public vec_base<bool, L>
{
    // Inherited constructors (could use this in c++11 to inherit constructors):
    //      using vec_base<bool, L>::vec_base;
    // (or something similar) would work.
    // Otherwise:
    vec() : vec_base<bool, L> () {}
    vec(const bool value) : vec_base<bool, L> (value) {}
    vec(const vec_base<bool, L>& v) : vec_base<bool, L>(v) {}
    vec(const bool v[L]): vec_base<bool, L> (v) {}
    vec(bool c0, bool c1) : vec_base<bool, L> (c0, c1) {}
    vec(bool c0, bool c1, bool c2) : vec_base<bool, L> (c0, c1, c2) {}
    vec(bool c0, bool c1, bool c2, bool c3) : vec_base<bool, L> (c0, c1, c2, c3) {}

    /////////////////////////////////////////////////
    /// \brief logical negation
    ///
    /// \return component-wise negated boolean vector
    ///
    /////////////////////////////////////////////////
    vec<bool, L> operator! () const;
};


} //namespace sbt

#endif //vec_HPP_
