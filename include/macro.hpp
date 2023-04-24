#ifndef LLA_MACRO_HPP
#define LLA_MACRO_HPP

#if __cplusplus >= 202002L
    #define LLA_NODISCARD_PURE [[nodiscard("pure function")]] [[gnu::pure]]
#else
    #define LLA_NODISCARD_PURE [[nodiscard]] [[gnu::pure]]
#endif

#endif //LLA_MACRO_HPP
