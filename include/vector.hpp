#ifndef LLA_VECTOR_HPP
#define LLA_VECTOR_HPP

#include <array>
#include <stdexcept>
#include "macro.hpp"

namespace lla {
    template<typename T, std::size_t N>
    class Vec {
    public:
        [[maybe_unused]] Vec() {
            arr.fill(T());
        }

        template<typename First, typename... Args>
        [[maybe_unused]] explicit Vec(const First& first, const Args&... args)
            : arr{first, args...}
        {}

        [[maybe_unused]] Vec(const Vec<T, N>&) = default;
        [[maybe_unused]] Vec<T, N>& operator=(const Vec<T, N>&) = default;

        [[maybe_unused]] Vec(Vec<T, N>&& that) noexcept = default;
        [[maybe_unused]] Vec<T, N>& operator=(Vec<T, N>&& that) noexcept = default;

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 1 && Dummy == N, int> = 0>
        [[maybe_unused]] LLA_PURE_FN const T& x() const {
            return arr[0];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 2 && Dummy == N, int> = 0>
        [[maybe_unused]] LLA_PURE_FN const T& y() const {
            return arr[1];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 3 && Dummy == N, int> = 0>
        [[maybe_unused]] LLA_PURE_FN const T& z() const {
            return arr[2];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 4 && Dummy == N, int> = 0>
        [[maybe_unused]] LLA_PURE_FN const T& w() const {
            return arr[3];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 1 && Dummy == N, int> = 0>
        [[maybe_unused]] LLA_PURE_FN T& x() {
            return arr[0];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 2 && Dummy == N, int> = 0>
        [[maybe_unused]] LLA_PURE_FN T& y() {
            return arr[1];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 3 && Dummy == N, int> = 0>
        [[maybe_unused]] LLA_PURE_FN T& z() {
            return arr[2];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 4 && Dummy == N, int> = 0>
        [[maybe_unused]] LLA_PURE_FN T& w() {
            return arr[3];
        }

        [[maybe_unused]] LLA_PURE_FN T& operator[](std::size_t i) const {
            return arr[i];
        }

        [[maybe_unused]] LLA_PURE_FN T& operator[](std::size_t i) {
            return arr[i];
        }

        [[maybe_unused]] LLA_PURE_FN bool operator==(const Vec<T, N>& rhs) const {
            return arr == rhs.arr;
        }

        [[maybe_unused]] LLA_PURE_FN bool operator!=(const Vec<T, N>& rhs) const {
            return arr != rhs.arr;
        }

        [[maybe_unused]] LLA_PURE_FN Vec<T, N> operator+() const {
            return *this;
        }

        [[maybe_unused]] LLA_PURE_FN Vec<T, N> operator-() const {
            Vec<T, N> result = *this;
            for (auto& x : result.arr) {
                x = -x;
            }
            return result;
        }

        [[maybe_unused]] LLA_PURE_FN Vec<T, N> operator+(const Vec<T, N>& rhs) const {
            Vec<T, N> result = *this;
            for (std::size_t i = 0; i < N; ++i) {
                result.arr[i] += rhs.arr[i];
            }
            return result;
        }

        [[maybe_unused]] Vec<T, N>& operator+=(const Vec<T, N>& rhs) {
            return *this = *this + rhs;
        }

        [[maybe_unused]] LLA_PURE_FN Vec<T, N> operator-(const Vec<T, N>& rhs) const {
            Vec<T, N> result = *this;
            for (std::size_t i = 0; i < N; ++i) {
                result.arr[i] -= rhs.arr[i];
            }
            return result;
        }

        [[maybe_unused]] Vec<T, N>& operator-=(const Vec<T, N>& rhs) {
            return *this = *this - rhs;
        }

        [[maybe_unused]] LLA_PURE_FN T dot(const Vec<T, N>& rhs) const {
            T result = 0;
            for (std::size_t i = 0; i < N; ++i) {
                result += arr[i] * rhs.arr[i];
            }
            return result;
        }

    private:
        std::array<T, N> arr;
    };

    using Vec2f  [[maybe_unused]] = Vec<float, 2>;
    using Vec2d  [[maybe_unused]] = Vec<double, 2>;
    using Vec2ld [[maybe_unused]] = Vec<long double, 2>;
    using Vec2s  [[maybe_unused]] = Vec<short, 2>;
    using Vec2i  [[maybe_unused]] = Vec<int, 2>;
    using Vec2l  [[maybe_unused]] = Vec<long, 2>;
    using Vec2ll [[maybe_unused]] = Vec<long long, 2>;

    using Vec3f  [[maybe_unused]] = Vec<float, 3>;
    using Vec3d  [[maybe_unused]] = Vec<double, 3>;
    using Vec3ld [[maybe_unused]] = Vec<long double, 3>;
    using Vec3s  [[maybe_unused]] = Vec<short, 3>;
    using Vec3i  [[maybe_unused]] = Vec<int, 3>;
    using Vec3l  [[maybe_unused]] = Vec<long, 3>;
    using Vec3ll [[maybe_unused]] = Vec<long long, 3>;
}

#endif //LLA_VECTOR_HPP
