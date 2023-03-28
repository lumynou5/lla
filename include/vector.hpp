#ifndef LLA_VECTOR_HPP
#define LLA_VECTOR_HPP

#include <array>
#include <stdexcept>

namespace lla {
    template<typename T, std::size_t N>
    class Vec {
    public:
        Vec() {
            arr.fill(T());
        }

        template<typename First, typename... Args>
        explicit Vec(const First& first, const Args&... args)
            : arr{first, args...}
        {}

        Vec(const Vec<T, N>&) = default;
        Vec<T, N>& operator=(const Vec<T, N>&) = default;

        Vec(Vec<T, N>&& that) noexcept = default;
        Vec<T, N>& operator=(Vec<T, N>&& that) noexcept = default;

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 1 && Dummy == N, int> = 0>
        const T& x() const {
            return arr[0];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 2 && Dummy == N, int> = 0>
        const T& y() const {
            return arr[1];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 3 && Dummy == N, int> = 0>
        const T& z() const {
            return arr[2];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 4 && Dummy == N, int> = 0>
        const T& w() const {
            return arr[3];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 1 && Dummy == N, int> = 0>
        T& x() {
            return arr[0];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 2 && Dummy == N, int> = 0>
        T& y() {
            return arr[1];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 3 && Dummy == N, int> = 0>
        T& z() {
            return arr[2];
        }

        template<std::size_t Dummy = N, std::enable_if_t<Dummy >= 4 && Dummy == N, int> = 0>
        T& w() {
            return arr[3];
        }

        const T& operator[](std::size_t i) const {
            return arr[i];
        }

        T& operator[](std::size_t i) {
            return arr[i];
        }

        bool operator==(const Vec<T, N>& rhs) const {
            return arr == rhs.arr;
        }

        bool operator!=(const Vec<T, N>& rhs) const {
            return arr != rhs.arr;
        }

        Vec<T, N> operator+() const {
            return *this;
        }

        Vec<T, N> operator-() const {
            Vec<T, N> result = *this;
            for (auto& x : result.arr) {
                x = -x;
            }
            return result;
        }

        Vec<T, N> operator+(const Vec<T, N>& rhs) const {
            Vec<T, N> result = *this;
            for (std::size_t i = 0; i < N; ++i) {
                result.arr[i] += rhs.arr[i];
            }
            return result;
        }

        inline Vec<T, N>& operator+=(const Vec<T, N>& rhs) {
            return *this = *this + rhs;
        }

        Vec<T, N> operator-(const Vec<T, N>& rhs) const {
            Vec<T, N> result = *this;
            for (std::size_t i = 0; i < N; ++i) {
                result.arr[i] -= rhs.arr[i];
            }
            return result;
        }

        inline Vec<T, N>& operator-=(const Vec<T, N>& rhs) {
            return *this = *this - rhs;
        }

        T dot(const Vec<T, N>& rhs) const {
            T result = 0;
            for (std::size_t i = 0; i < N; ++i) {
                result += arr[i] * rhs.arr[i];
            }
            return result;
        }

    private:
        std::array<T, N> arr;
    };

    using Vec2f = Vec<float, 2>;
    using Vec2d = Vec<double, 2>;
    using Vec2ld = Vec<long double, 2>;
    using Vec2s = Vec<short, 2>;
    using Vec2i = Vec<int, 2>;
    using Vec2l = Vec<long, 2>;
    using Vec2ll = Vec<long long, 2>;

    using Vec3f = Vec<float, 3>;
    using Vec3d = Vec<double, 3>;
    using Vec3ld = Vec<long double, 3>;
    using Vec3s = Vec<short, 3>;
    using Vec3i = Vec<int, 3>;
    using Vec3l = Vec<long, 3>;
    using Vec3ll = Vec<long long, 3>;
}

#endif //LLA_VECTOR_HPP
