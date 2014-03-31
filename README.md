Sumbeard's Tools (SBT)
======================

SBT includes a mathematical vector template class. SBT is open source (see license in sourcecode). It was created primarily to practice working with C++ templates and meta-programming. If you were looking for something more extensive, take a look at GLM (OpenGL Mathematics). Keep in mind that SBT has not been thoroughly tested and may contain runtime surprises.

Current Features
-----------------

### sbt::vec
A general mathematical vector template class. For use with types that 
implement the mathematical operators.

#### non-static methods:
  - vector addition 
  - vector subtraction
  - vector multiplication
  - scalar multiplication of a vector
  - equals
  - unary negation
  - calculate norm
  - calculate normal (normalize)

#### static methods:
  - dot product
  - cross product for 3D vectors

#### nested namespaces:
  - sbt::fvec - float type
  - sbt::dvec - double type
  - sbt::ivec - signed and unsigned int types
  - sbt::bvec - bool type

#### specializations:
  - boolean specialization of vector class
    + constructors
    + logical negation

#### unimplemented
  - whatever else I'm not thinking of at the moment

Headers
--------
### vec.hpp, vec.inl
  - vec.hpp includes the 'vec' class template prototype, aliases, and
    specializaions
  - vec.inl is the implementation of the 'vec' class template. The template is 
    over two files only for readabilty. Do not build or link the *.inl directly

Other Files
------------
### Doxyfile
  - Configuration for Doxygen
