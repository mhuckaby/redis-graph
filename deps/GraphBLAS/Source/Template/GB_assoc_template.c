//------------------------------------------------------------------------------
// GB_assoc_template.c:
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

// This is a generic body of code for creating hard-coded versions of code for
// 44 combinations of associative operators and built-in types: 10 types (all
// but boolean) with min, max, plus, and times, and one type (boolean) with
// "or", "and" "xor" and "eq"

// If INCLUDE_SECOND_OPERATOR is #define'd, then an additional 11 built-in
// workers for the SECOND operator are also created, and 11 for FIRST,
// for GB_build_factory.

if (typecode != GB_BOOL_code)
{

    //--------------------------------------------------------------------------
    // non-boolean case
    //--------------------------------------------------------------------------

    switch (opcode)
    {
        case GB_MIN_opcode   :

            switch (typecode)
            {
                #define ADD(w,t) w = IMIN (w,t)
                case GB_INT8_code   : WORKER (int8_t)   ; break ;
                case GB_UINT8_code  : WORKER (uint8_t)  ; break ;
                case GB_INT16_code  : WORKER (int16_t)  ; break ;
                case GB_UINT16_code : WORKER (uint16_t) ; break ;
                case GB_INT32_code  : WORKER (int32_t)  ; break ;
                case GB_UINT32_code : WORKER (uint32_t) ; break ;
                case GB_INT64_code  : WORKER (int64_t)  ; break ;
                case GB_UINT64_code : WORKER (uint64_t) ; break ;
                #undef  ADD
                #define ADD(w,t) w = FMIN (w,t)
                case GB_FP32_code   : WORKER (float)    ; break ;
                case GB_FP64_code   : WORKER (double)   ; break ;
                #undef  ADD
                default: ;
            }
            break ;

        case GB_MAX_opcode   :

            switch (typecode)
            {
                #define ADD(w,t) w = IMAX (w,t)
                case GB_INT8_code   : WORKER (int8_t)   ; break ;
                case GB_UINT8_code  : WORKER (uint8_t)  ; break ;
                case GB_INT16_code  : WORKER (int16_t)  ; break ;
                case GB_UINT16_code : WORKER (uint16_t) ; break ;
                case GB_INT32_code  : WORKER (int32_t)  ; break ;
                case GB_UINT32_code : WORKER (uint32_t) ; break ;
                case GB_INT64_code  : WORKER (int64_t)  ; break ;
                case GB_UINT64_code : WORKER (uint64_t) ; break ;
                #undef  ADD
                #define ADD(w,t) w = FMAX (w,t)
                case GB_FP32_code   : WORKER (float)    ; break ;
                case GB_FP64_code   : WORKER (double)   ; break ;
                #undef  ADD
                default: ;
            }
            break ;

        case GB_PLUS_opcode  :

            #define ADD(w,t) w += t
            switch (typecode)
            {
                case GB_INT8_code   : WORKER (int8_t)   ; break ;
                case GB_UINT8_code  : WORKER (uint8_t)  ; break ;
                case GB_INT16_code  : WORKER (int16_t)  ; break ;
                case GB_UINT16_code : WORKER (uint16_t) ; break ;
                case GB_INT32_code  : WORKER (int32_t)  ; break ;
                case GB_UINT32_code : WORKER (uint32_t) ; break ;
                case GB_INT64_code  : WORKER (int64_t)  ; break ;
                case GB_UINT64_code : WORKER (uint64_t) ; break ;
                case GB_FP32_code   : WORKER (float)    ; break ;
                case GB_FP64_code   : WORKER (double)   ; break ;
                default: ;
            }
            break ;
            #undef  ADD

        case GB_TIMES_opcode :

            #define ADD(w,t) w *= t
            switch (typecode)
            {
                case GB_INT8_code   : WORKER (int8_t)   ; break ;
                case GB_UINT8_code  : WORKER (uint8_t)  ; break ;
                case GB_INT16_code  : WORKER (int16_t)  ; break ;
                case GB_UINT16_code : WORKER (uint16_t) ; break ;
                case GB_INT32_code  : WORKER (int32_t)  ; break ;
                case GB_UINT32_code : WORKER (uint32_t) ; break ;
                case GB_INT64_code  : WORKER (int64_t)  ; break ;
                case GB_UINT64_code : WORKER (uint64_t) ; break ;
                case GB_FP32_code   : WORKER (float)    ; break ;
                case GB_FP64_code   : WORKER (double)   ; break ;
                default: ;
            }
            break ;
            #undef  ADD

        //----------------------------------------------------------------------
        // FIRST and SECOND for GB_build_factory
        //----------------------------------------------------------------------

        #ifdef INCLUDE_SECOND_OPERATOR

        case GB_FIRST_opcode :

            #define ADD(w,t) ;      // do nothing; keep the first tuple
            switch (typecode)
            {
                case GB_INT8_code   : WORKER (int8_t)   ; break ;
                case GB_UINT8_code  : WORKER (uint8_t)  ; break ;
                case GB_INT16_code  : WORKER (int16_t)  ; break ;
                case GB_UINT16_code : WORKER (uint16_t) ; break ;
                case GB_INT32_code  : WORKER (int32_t)  ; break ;
                case GB_UINT32_code : WORKER (uint32_t) ; break ;
                case GB_INT64_code  : WORKER (int64_t)  ; break ;
                case GB_UINT64_code : WORKER (uint64_t) ; break ;
                case GB_FP32_code   : WORKER (float)    ; break ;
                case GB_FP64_code   : WORKER (double)   ; break ;
                default: ;
            }
            break ;
            #undef  ADD

        case GB_SECOND_opcode :

            #define ADD(w,t) w = t  // replace with the 2nd tuple
            switch (typecode)
            {
                case GB_INT8_code   : WORKER (int8_t)   ; break ;
                case GB_UINT8_code  : WORKER (uint8_t)  ; break ;
                case GB_INT16_code  : WORKER (int16_t)  ; break ;
                case GB_UINT16_code : WORKER (uint16_t) ; break ;
                case GB_INT32_code  : WORKER (int32_t)  ; break ;
                case GB_UINT32_code : WORKER (uint32_t) ; break ;
                case GB_INT64_code  : WORKER (int64_t)  ; break ;
                case GB_UINT64_code : WORKER (uint64_t) ; break ;
                case GB_FP32_code   : WORKER (float)    ; break ;
                case GB_FP64_code   : WORKER (double)   ; break ;
                default: ;
            }
            break ;
            #undef  ADD

        #endif

        default: ;
    }

}
else
{

    //--------------------------------------------------------------------------
    // boolean case: rename the opcode as needed
    //--------------------------------------------------------------------------

    // non-associatve ops not handled here: *GT, *LT, *GE, *LE.

    // The FIRST and SECOND operators are not associative, but are added for
    // GB_build_factory.  Since FIRST == DIV, the operator is handled too.

    switch (GB_boolean_rename (opcode))
    {

        case GB_LOR_opcode :

            // OR == MAX == PLUS
            #define ADD(w,t) w = (w || t)
            WORKER (bool) ;
            break ;
            #undef  ADD

        case GB_LAND_opcode :

            // AND == MIN == TIMES
            #define ADD(w,t) w = (w && t)
            WORKER (bool) ;
            break ;
            #undef  ADD

        case GB_LXOR_opcode :

            // XOR == NE == MINUS == ISNE
            #define ADD(w,t) w = (w != t)
            WORKER (bool) ;
            break ;
            #undef  ADD

        case GB_EQ_opcode :

            // EQ == ISEQ
            #define ADD(w,t) w = (w == t)
            WORKER (bool) ;
            break ;
            #undef  ADD

        //----------------------------------------------------------------------
        // FIRST and SECOND for GB_build_factory
        //----------------------------------------------------------------------

        #ifdef INCLUDE_SECOND_OPERATOR

        case GB_FIRST_opcode :

            // FIRST == DIV
            #define ADD(w,t) ;      // do nothing; keep the first tuple
            WORKER (bool) ;
            break ;
            #undef  ADD

        case GB_SECOND_opcode :

            // SECOND
            #define ADD(w,t) w = t  // replace with the 2nd tuple
            WORKER (bool) ;
            break ;
            #undef  ADD

        #endif

        default: ;
    }
}

