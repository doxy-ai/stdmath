%define STDMATH_TYPEMAP(name)

    /* Rename the C++ symbol for the target language */
    %rename("stdmath_" #name) stdmath::name;

    /* Input typemap: target language stdmath_<name> -> C++ std::math::<name> */
    %typemap(in) stdmath::name {
        void* tmp = nullptr;
        auto res = SWIG_ConvertPtr($input, &tmp, SWIGTYPE_p_stdmath_##name,  0 );
        if(!tmp)
            SWIG_exception_fail(SWIG_ArgError(res), "Failed to convert stdmath_" #name " to stdmath::" #name); 
        $1 = *($type*)tmp;
    }

    /* Type check: Checking if the input argument is of the correct type */
    // %typemap(typecheck, precedence=SWIG_TYPECHECK_INTEGER) stdmath::name {
    //     $1 = dynamic_cast<stdmath_##name*>($input) != nullptr;
    // }

    /* Output typemap: C++ std::math::<name> -> target language stdmath_<name> */
    %typemap(out) stdmath::name {
        auto tmp = (stdmath_##name *)&$1;
        $result = SWIG_NewPointerObj(new stdmath_##name(*tmp), SWIGTYPE_p_stdmath_##name, SWIG_POINTER_OWN |  0 );
    }

%enddef