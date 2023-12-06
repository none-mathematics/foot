//!
//! Copyrignt (c) 2023 none-mathematics
//! Use of this source code is governed by a MIT-style
//! license that can be found in the LICENSE file.
//!
#ifndef FOOT_H_
#define FOOT_H_
#include <cstddef>
#include <cstdint>
#include <limits>
#include <version>
#define INT_C(value) INT64_C(value)
#define UINT_C(value) UINT64_C(value)
#define FLOAT32_C(value) value##F
#define FLOAT64_C(value) value
namespace foot {
using int_t = ptrdiff_t;
using uint_t = size_t;
using float32_t = float;
using float64_t = double;
///
/// Class math provides basic constants and mathematical functions.
///
/// This class does not guarantee bit-identical results across architectures.
///
class math {
public:
  ///
  /// Mathematical constants.
  ///
  static constexpr float64_t e = FLOAT64_C(
      2.7182818'28459045'23536028'74713526'62497757'24709369'99595749'6696763); // https://oeis.org/A001113
  static constexpr float64_t pi = FLOAT64_C(
      3.1415926'53589793'23846264'33832795'02884197'16939937'51058209'7494459); // https://oeis.org/A000796
  static constexpr float64_t phi = FLOAT64_C(
      1.6180339'88749894'84820458'68343656'38117720'30917980'57628621'3544862); // https://oeis.org/A001622
  static constexpr float64_t sqrt_2 = FLOAT64_C(
      1.4142135'62373095'04880168'87242096'98078569'67187537'69480731'7667974); // https://oeis.org/A002193
  static constexpr float64_t sqrt_e = FLOAT64_C(
      1.6487212'70700128'14684865'07878141'63571653'77610071'01480115'7507931); // https://oeis.org/A019774
  static constexpr float64_t sqrt_pi = FLOAT64_C(
      1.7724538'50905516'02729816'74833411'45182797'54945612'23871282'1380779); // https://oeis.org/A002161
  static constexpr float64_t sqrt_phi = FLOAT64_C(
      1.2720196'49514068'96425242'24617374'91491715'60804184'00962486'1664038); // https://oeis.org/A139339
  static constexpr float64_t log_e_2 = FLOAT64_C(
      0.6931471'80559945'30941723'21214581'76568075'50013436'02552541'20680009); // https://oeis.org/A002162
  static constexpr float64_t log_2_e = 1.0 / log_e_2;
  static constexpr float64_t log_e_10 = FLOAT64_C(
      2.3025850'92994045'68401799'14546843'64207601'10148862'87729760'3332790); // https://oeis.org/A002392
  static constexpr float64_t log_10_e = 1.0 / log_e_10;
  ///
  /// Floating-point limit values.
  /// The `max` is the largest finite value representable by the type.
  /// The `smallest_nonzero` is the smallest positive, non-zero value
  /// representable by the type.
  ///
  static constexpr float32_t max_float32 =
      FLOAT32_C(0x1.0p+127) *
      (FLOAT32_C(1.0) +
       (FLOAT32_C(1.0) -
        FLOAT32_C(0x1.0p-23))); // 3.40282346638528859811704183484516925440e+38F
  static constexpr float32_t smallest_nonzero_float32 =
      FLOAT32_C(0x1.0p-126) *
      FLOAT32_C(0X1.0P-23); // 1.401298464324817070923729583289916131280e-45F
  static constexpr float64_t max_float64 =
      FLOAT64_C(0x1.0p+1023) *
      (FLOAT64_C(1.0) +
       (FLOAT64_C(1.0) -
        FLOAT64_C(
            0x1.0p-52))); // 1.79769313486231570814527423731704356798070e+308
  static constexpr float64_t smallest_nonzero_float64 =
      FLOAT64_C(0x1.0p-1022) *
      FLOAT64_C(
          0x1.0p-52); // 4.9406564584124654417656879286822137236505980e-324
  ///
  /// Integer limit values.
  ///
  static constexpr int_t max_int =
      std::numeric_limits<int_t>::max(); // max_int32 or max_int64 depending on
                                         // int size
  static constexpr int_t min_int =
      std::numeric_limits<int_t>::min(); // min_int32 or min_int64 depending on
                                         // int size
  static constexpr int8_t max_int8 = std::numeric_limits<int8_t>::max(); // 127
  static constexpr int8_t min_int8 = std::numeric_limits<int8_t>::min(); // -128
  static constexpr int16_t max_int16 =
      std::numeric_limits<int16_t>::max(); // 32767
  static constexpr int16_t min_int16 =
      std::numeric_limits<int16_t>::min(); // -32768
  static constexpr int32_t max_int32 =
      std::numeric_limits<int32_t>::max(); // 2147483647
  static constexpr int32_t min_int32 =
      std::numeric_limits<int32_t>::min(); // -2147483648
  static constexpr int64_t max_int64 =
      std::numeric_limits<int64_t>::max(); // 9223372036854775807
  static constexpr int64_t min_int64 =
      std::numeric_limits<int64_t>::min(); // -9223372036854775808
  static constexpr uint_t max_uint =
      std::numeric_limits<uint_t>::max(); // max_int32 or max_int64 depending on
                                          // int size
  static constexpr uint8_t max_uint8 =
      std::numeric_limits<uint8_t>::max(); // 255
  static constexpr uint16_t max_uint16 =
      std::numeric_limits<uint16_t>::max(); // 65535
  static constexpr uint32_t max_uint32 =
      std::numeric_limits<uint32_t>::max(); // 4294967295
  static constexpr uint64_t max_uint64 =
      std::numeric_limits<uint64_t>::max(); // 18446744073709551615
  ///
  /// Make sure the class is an lib class.
  ///
  constexpr math() noexcept;
  constexpr float64_t abs(float64_t value) const noexcept;
  constexpr float64_t acos(float64_t value) const noexcept;
  constexpr float64_t acosh(float64_t value) const noexcept;
  constexpr float64_t asin(float64_t value) const noexcept;
  constexpr float64_t asinh(float64_t value) const noexcept;
  constexpr float64_t atan(float64_t value) const noexcept;
  constexpr float64_t atan2(float64_t value0, float64_t value1) const noexcept;
  constexpr float64_t atanh(float64_t value) const noexcept;
  constexpr float64_t cbrt(float64_t value) const noexcept;
  constexpr float64_t ceil(float64_t value) const noexcept;
  constexpr float64_t copysign(float64_t value0,
                               float64_t value1) const noexcept;
  constexpr float64_t cos(float64_t value) const noexcept;
  constexpr float64_t cosh(float64_t value) const noexcept;
  constexpr float64_t dim(float64_t value0, float64_t value1) const noexcept;
  constexpr float64_t erf(float64_t value) const noexcept;
  constexpr float64_t erfc(float64_t value) const noexcept;
  constexpr float64_t erfc_inv(float64_t value) const noexcept;
  constexpr float64_t erf_inv(float64_t value) const noexcept;
  constexpr float64_t exp(float64_t value) const noexcept;
  constexpr float64_t exp2(float64_t value) const noexcept;
  constexpr float64_t expm1(float64_t value) const noexcept;
  constexpr float64_t fma(float64_t value0, float64_t value1,
                          float64_t value2) const noexcept;
  constexpr uint32_t floating_bits(float32_t value) const noexcept;
  constexpr float32_t floating_from_bits(uint32_t value) const noexcept;
  constexpr uint64_t floating_bits(float64_t value) const noexcept;
  constexpr float64_t floating_from_bits(uint64_t value) const noexcept;
  constexpr float64_t floor(float64_t value) const noexcept;
  struct frexp_result {
    float64_t frac;
    int_t exp;
  };
  constexpr frexp_result frexp(float64_t value) const noexcept;
  constexpr float64_t gamma(float64_t value) const noexcept;
  constexpr float64_t hypot(float64_t value0, float64_t value1) const noexcept;
  constexpr int64_t ilogb(float64_t value) const noexcept;
  constexpr float64_t inf(int_t sign) const noexcept;
  constexpr bool isinf(float64_t value, int_t sign) const noexcept;
  constexpr bool isnan(float64_t value) const noexcept;
  constexpr float64_t j0(float64_t value) const noexcept;
  constexpr float64_t j1(float64_t value) const noexcept;
  constexpr float64_t jn(int_t n, float64_t value) const noexcept;
  constexpr float64_t ldexp(float64_t frac, int_t exp) const noexcept;
  struct lgamma_result {
    float64_t lgamma;
    int_t sign;
  };
  constexpr lgamma_result lgamma(float64_t value) const noexcept;
  constexpr float64_t log(float64_t value) const noexcept;
  constexpr float64_t log10(float64_t value) const noexcept;
  constexpr float64_t log1p(float64_t value) const noexcept;
  constexpr float64_t log2(float64_t value) const noexcept;
  constexpr float64_t logb(float64_t value) const noexcept;
  constexpr float64_t max(float64_t value0, float64_t value1) const noexcept;
  constexpr float64_t min(float64_t value0, float64_t value1) const noexcept;
  constexpr float64_t mod(float64_t value0, float64_t value1) const noexcept;
  struct modf_result {
    float64_t integer;
    float64_t frac;
  };
  constexpr modf_result modf(float64_t value) const noexcept;
  constexpr float64_t nan() const noexcept;
  constexpr float64_t nextafter(float64_t value0,
                                float64_t value1) const noexcept;
  constexpr float32_t nextafter(float32_t value0,
                                float32_t value1) const noexcept;
  constexpr float64_t pow(float64_t value0, float64_t value1) const noexcept;
  constexpr float64_t pow10(int_t value) const noexcept;
  constexpr float64_t remainder(float64_t value0,
                                float64_t value1) const noexcept;
  constexpr float64_t round(float64_t value) const noexcept;
  constexpr float64_t round_to_even(float64_t value) const noexcept;
  constexpr bool signbit(float64_t value) const noexcept;
  constexpr float64_t sin(float64_t value) const noexcept;
  struct sincos_result {
    float64_t sin;
    float64_t cos;
  };
  constexpr sincos_result sincos(float64_t value) const noexcept;
  constexpr float64_t sinh(float64_t value) const noexcept;
  constexpr float64_t sqrt(float64_t value) const noexcept;
  constexpr float64_t tan(float64_t value) const noexcept;
  constexpr float64_t tanh(float64_t value) const noexcept;
  constexpr float64_t trunc(float64_t value) const noexcept;
  constexpr float64_t y0(float64_t value) const noexcept;
  constexpr float64_t y1(float64_t value) const noexcept;
  constexpr float64_t yn(int_t n, float64_t value) const noexcept;
};
} // namespace foot
#endif
