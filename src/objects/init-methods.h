
/*
  General rule: Always initialise values, preferabily in the initalisation list
  of a constructor, especially built-in types

  Member variables in initialisation lists will always be initialised in the
  order they are declared in the header file.

  Tricksy hobbitses arise when:
    '[the] order of initialisation of non-local static objects defined in
    different translation units'

    The above broken down:
    static object - one that exists from the time it's constructed until end of
    the program. Can include:
    - Global objects (non-local)
    - Namespaced objects (non-local)
    - Static class objects (non-local)
    - Static function objects (local static objects)

    translation unit - a single source file plus all it's include files

    Problems arise when the initialisation of a non-local static object in
    one translation unit uses a non-local static object in a different
    translation unit

  The above is basically solved by the 'singleton' pattern

*/