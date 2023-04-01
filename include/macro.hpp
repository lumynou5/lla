#ifndef LLA_MACRO_HPP
#define LLA_MACRO_HPP

#if __cplusplus >= 202002L
    #define LLA_NODISCARD_PURE [[nodiscard("pure function")]]
#else
    #define LLA_NODISCARD_PURE [[nodiscard]]
#endif

#endif //LLA_MACRO_HPP
