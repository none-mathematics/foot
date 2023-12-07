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
///
/// Namespace math provides basic constants and mathematical functions.
///
/// This namespace does not guarantee bit-identical results 
/// across architectures.
///
namespace math {
  using int_t = ptrdiff_t;
  using uint_t = size_t;
  using float32_t = float;
  using float64_t = double;

  struct FrexpResult {
    float64_t frac_;
    int_t exp_;
  };
  struct LgammaResult {
    float64_t lgamma_;
    int_t sign_;
  };
  struct ModfResult {
    float64_t integer_;
    float64_t frac_;
  };
  struct SincosResult {
    float64_t sin_;
    float64_t cos_;
  };
  ///
  /// Mathematical constants.
  ///
  constexpr float64_t e = FLOAT64_C(
      2.7182818'28459045'23536028'74713526'62497757'24709369'99595749'6696763); // https://oeis.org/A001113
  constexpr float64_t pi = FLOAT64_C(
      3.1415926'53589793'23846264'33832795'02884197'16939937'51058209'7494459); // https://oeis.org/A000796
  constexpr float64_t phi = FLOAT64_C(
      1.6180339'88749894'84820458'68343656'38117720'30917980'57628621'3544862); // https://oeis.org/A001622
  constexpr float64_t sqrt_2 = FLOAT64_C(
      1.4142135'62373095'04880168'87242096'98078569'67187537'69480731'7667974); // https://oeis.org/A002193
  constexpr float64_t sqrt_e = FLOAT64_C(
      1.6487212'70700128'14684865'07878141'63571653'77610071'01480115'7507931); // https://oeis.org/A019774
  constexpr float64_t sqrt_pi = FLOAT64_C(
      1.7724538'50905516'02729816'74833411'45182797'54945612'23871282'1380779); // https://oeis.org/A002161
  constexpr float64_t sqrt_phi = FLOAT64_C(
      1.2720196'49514068'96425242'24617374'91491715'60804184'00962486'1664038); // https://oeis.org/A139339
  constexpr float64_t log_e_2 = FLOAT64_C(
      0.6931471'80559945'30941723'21214581'76568075'50013436'02552541'20680009); // https://oeis.org/A002162
  constexpr float64_t log_2_e = 1.0 / log_e_2;
  constexpr float64_t log_e_10 = FLOAT64_C(
      2.3025850'92994045'68401799'14546843'64207601'10148862'87729760'3332790); // https://oeis.org/A002392
  constexpr float64_t log_10_e = 1.0 / log_e_10;
  ///
  /// Floating-point limit values.
  /// The `max` is the largest finite value representable by the type.
  /// The `smallest_nonzero` is the smallest positive, non-zero value
  /// representable by the type.
  ///
  constexpr float32_t max_float32 =
      FLOAT32_C(0x1.0p+127) *
      (FLOAT32_C(1.0) +
       (FLOAT32_C(1.0) -
        FLOAT32_C(0x1.0p-23))); // 3.40282346638528859811704183484516925440e+38F
  constexpr float32_t smallest_nonzero_float32 =
      FLOAT32_C(0x1.0p-126) *
      FLOAT32_C(0X1.0P-23); // 1.401298464324817070923729583289916131280e-45F
  constexpr float64_t max_float64 =
      FLOAT64_C(0x1.0p+1023) *
      (FLOAT64_C(1.0) +
       (FLOAT64_C(1.0) -
        FLOAT64_C(
            0x1.0p-52))); // 1.79769313486231570814527423731704356798070e+308
  constexpr float64_t smallest_nonzero_float64 =
      FLOAT64_C(0x1.0p-1022) *
      FLOAT64_C(
          0x1.0p-52); // 4.9406564584124654417656879286822137236505980e-324
  ///
  /// Integer limit values.
  ///
  constexpr int_t max_int =
      std::numeric_limits<int_t>::max(); // max_int32 or max_int64 depending on
                                         // int size
  constexpr int_t min_int =
      std::numeric_limits<int_t>::min(); // min_int32 or min_int64 depending on
                                         // int size
  constexpr int8_t max_int8 = std::numeric_limits<int8_t>::max(); // 127
  constexpr int8_t min_int8 = std::numeric_limits<int8_t>::min(); // -128
  constexpr int16_t max_int16 =
      std::numeric_limits<int16_t>::max(); // 32767
  constexpr int16_t min_int16 =
      std::numeric_limits<int16_t>::min(); // -32768
  constexpr int32_t max_int32 =
      std::numeric_limits<int32_t>::max(); // 2147483647
  constexpr int32_t min_int32 =
      std::numeric_limits<int32_t>::min(); // -2147483648
  constexpr int64_t max_int64 =
      std::numeric_limits<int64_t>::max(); // 9223372036854775807
  constexpr int64_t min_int64 =
      std::numeric_limits<int64_t>::min(); // -9223372036854775808
  constexpr uint_t max_uint =
      std::numeric_limits<uint_t>::max(); // max_int32 or max_int64 depending on
                                          // int size
  constexpr uint8_t max_uint8 =
      std::numeric_limits<uint8_t>::max(); // 255
  constexpr uint16_t max_uint16 =
      std::numeric_limits<uint16_t>::max(); // 65535
  constexpr uint32_t max_uint32 =
      std::numeric_limits<uint32_t>::max(); // 4294967295
  constexpr uint64_t max_uint64 =
      std::numeric_limits<uint64_t>::max(); // 18446744073709551615
  ///
  /// Function abs returns 
  /// the absolute value of x.
  ///
  constexpr float64_t abs(float64_t x) noexcept;
  ///
  /// Function acos returns 
  /// the arccosine, in radians, of x.
  ///
  constexpr float64_t acos(float64_t x) noexcept;
  ///
  /// Function acosh returns 
  /// the inverse hyperbolic cosine of x.
  ///
  constexpr float64_t acosh(float64_t x) noexcept;
  ///
  /// Function asin returns 
  /// the arcsine, in radians, of x.
  ///
  constexpr float64_t asin(float64_t x) noexcept;
  ///
  /// Function asinh returns 
  /// the inverse hyperbolic sine of x.
  ///
  constexpr float64_t asinh(float64_t x) noexcept;
  ///
  /// Function atan returns 
  /// the arctangent, in radians, of x.
  ///
  constexpr float64_t atan(float64_t x) noexcept;
  ///
  /// Function atan2 returns 
  /// the arc tangent of x / y, 
  /// using the signs of 
  /// the two to determine the quadrant of 
  /// the return value.
  /// 
  constexpr float64_t atan2(float64_t x, float64_t y) noexcept;
  ///
  /// Function atanh returns 
  /// the inverse hyperbolic 
  /// tangent of x.
  ///
  constexpr float64_t atanh(float64_t x) noexcept;
  ///
  /// Function cbrt returns 
  /// the cube root of x.
  ///
  constexpr float64_t cbrt(float64_t x) noexcept;
  ///
  /// Function ceil returns 
  /// the least integer value 
  /// greater than or equal to x.
  ///
  constexpr float64_t ceil(float64_t x) noexcept;
  ///
  /// Function copysign returns 
  /// a value with the magnitude of x and 
  /// the sign of y.
  ///
  constexpr float64_t copysign(float64_t x, float64_t y) noexcept;
  ///
  /// Function cos returns 
  /// the cosine of 
  /// the radian argument of x.
  ///
  constexpr float64_t cos(float64_t x) noexcept;
  ///
  /// Function cosh returns 
  /// the hyperbolic cosine of x.
  ///
  constexpr float64_t cosh(float64_t x) noexcept;
  ///
  /// Function dim returns 
  /// the maximum of x - y or 0.
  ///
  constexpr float64_t dim(float64_t x, float64_t y) noexcept;
  ///
  /// Function erf returns 
  /// the error function of x.
  ///
  constexpr float64_t erf(float64_t x) noexcept;
  /// 
  /// Function erfc returns 
  /// the complementary 
  /// error function of x.
  ///
  constexpr float64_t erfc(float64_t x) noexcept;
  /// 
  /// Function erfc_inv returns 
  /// the inverse of erfc(x).  
  ///
  constexpr float64_t erfc_inv(float64_t x) noexcept;
  ///
  /// Function erf_inv returns 
  /// the inverse error function of x.
  ///
  constexpr float64_t erf_inv(float64_t x) noexcept;
  ///
  /// Function exp returns e**x, 
  /// the base-e exponential of x.
  ///
  constexpr float64_t exp(float64_t x) noexcept;
  ///
  /// Function exp2 returns 2**x, 
  /// the base-2 exponential of x.
  ///
  constexpr float64_t exp2(float64_t x) noexcept;
  ///
  /// Function expm1 returns 
  /// e**x - 1, the base-e 
  /// exponential of x minus 1 .
  /// It is more accurate than 
  /// exp(x) - 1 when x is near zero.
  ///
  constexpr float64_t expm1(float64_t x) noexcept;
  ///
  /// Function fma returns x * y + z, computed with 
  /// only one rounding. (That is, Function fma returns 
  /// the fused multiply-add of x, y, and z.)
  ///
  constexpr float64_t fma(float64_t x, float64_t y, float64_t z) noexcept;
  ///
  /// Function float32_bits returns 
  /// the IEEE 754 binary representation of x,
  /// with the sign bit of x and 
  /// the result in the same bit position.
  /// float32_bits(float32_from_bits(x)) == x.
  ///
  constexpr uint32_t float32_bits(float32_t x) noexcept;
  ///
  /// Function float32_from_bits returns 
  /// the floating-point number 
  /// corresponding to the IEEE 754 binary 
  /// representation b, with the sign bit of b and 
  /// the result in the same bit position.
  /// float32_from_bits(float32_bits(x)) == x.
  ///
  constexpr float32_t float32_from_bits(uint32_t b) noexcept;
  ///
  /// Function float64_bits returns 
  /// the IEEE 754 binary represention of x,
  /// with the sign bit of x and 
  /// the result in the same bit position, and
  /// float64_bits(float64_from_bits(x)) == x.
  ///
  constexpr uint64_t float64_bits(float64_t x) noexcept;
  ///
  /// Function float64_from_bits returns 
  /// the floating-point number 
  /// corresponding to the IEEE 754 binary 
  /// representation b, with the sign bit of b and 
  /// the result in the same bit position.
  /// float64_from_bits(float64_bits(x)) == x.
  ///
  constexpr float64_t float64_from_bits(uint64_t bits) noexcept;
  ///
  /// Function floor returns 
  /// the greatest integer value 
  /// less than or equal to x.
  ///
  constexpr float64_t floor(float64_t x) noexcept;
  ///
  /// Function frexp breaks x into 
  /// a normalized fraction and 
  /// an integral power of two.
  /// It returns frac and exp 
  /// satisfying x == frac * 2**exp,
  /// with the absolute value of 
  /// frac in the interval [0.5, 1.0).
  ///
  constexpr FrexpResult frexp(float64_t x) noexcept;
  ///
  /// Function gamma returns 
  /// the gamma function of x.
  ///
  constexpr float64_t gamma(float64_t x) noexcept;
  ///
  /// Function hypot returns sqrt(x*x + y*y),
  /// taking care to avoid unnecessary 
  /// overflow and underflow.
  ///
  constexpr float64_t hypot(float64_t x, float64_t y) noexcept;
  ///
  /// Function ilogb returns 
  /// the binary exponent of x 
  /// as an integer.
  ///
  constexpr int64_t ilogb(float64_t x) noexcept;
  ///
  /// Function inf returns 
  /// positive infinity if sign >= 0,
  /// negative infinity if sign < 0 .
  ///
  constexpr float64_t inf(int_t sign) noexcept;
  ///
  /// Function isinf reports 
  /// whether x is an infinity, 
  /// according to sign.
  /// If sign > 0, Function isinf reports
  /// whether x is positive infinity.
  /// If sign < 0, Function isinf reports 
  /// whether x is negative infinity.
  /// If sign == 0, Function isinf reports
  /// whether x is either infinity.
  ///
  constexpr bool isinf(float64_t x, int_t sign) noexcept;
  ///
  /// Function isnan reports 
  /// whether x is an IEEE 754 
  /// "not-a-number" value.
  ///
  constexpr bool isnan(float64_t x) noexcept;
  ///
  /// Function j0 returns 
  /// the order-zero Bessel function 
  /// of the first kind.
  ///
  constexpr float64_t j0(float64_t x) noexcept;
  ///
  /// Function j1 returns 
  /// the order-one Bessel function 
  /// of the first kind.
  ///
  constexpr float64_t j1(float64_t x) noexcept;
  ///
  /// Function jn returns 
  /// the order-n Bessel function 
  /// of the first kind.
  ///
  constexpr float64_t jn(int_t n, float64_t x) noexcept;
  ///
  /// Function ldexp is the inverse of frexp.
  /// It returns frac * 2**exp.
  ///
  constexpr float64_t ldexp(float64_t frac, int_t exp) noexcept;
  ///
  /// Function lgamma returns 
  /// the natural logarithm and 
  /// sign (-1 or +1) of gamma(x).
  ///
  constexpr LgammaResult lgamma(float64_t x) noexcept;
  ///
  /// Function log returns 
  /// the natural logarithm of x.
  ///
  constexpr float64_t log(float64_t x) noexcept;
  ///
  /// Function log10 returns 
  /// the decimal logarithm of x.
  ///
  constexpr float64_t log10(float64_t x) noexcept;
  ///
  /// Function log1p returns the 
  /// natural logarithm of 1.0 plus its 
  /// argument x. It is more accurate than 
  /// log(1.0 + x) when x is near zero.
  ///
  constexpr float64_t log1p(float64_t x) noexcept;
  ///
  /// Function log2 returns 
  /// the binary logarithm of x.
  ///
  constexpr float64_t log2(float64_t x) noexcept;
  ///
  /// Function logb returns 
  /// the binary exponent of x.
  ///
  constexpr float64_t logb(float64_t x) noexcept;
  ///
  /// Function max returns 
  /// the larger of x or y.
  ///
  constexpr float64_t max(float64_t x, float64_t y) noexcept;
  ///
  /// Function min returns 
  /// the smaller of x or y.
  ///
  constexpr float64_t min(float64_t x, float64_t y) noexcept;
  ///
  /// Function mod returns the floating-point 
  /// remainder of x / y.
  /// The magnitude of the result is less than y 
  /// and its sign agrees with that of x.
  ///
  constexpr float64_t mod(float64_t x, float64_t y) noexcept;
  ///
  /// Function modf returns integer and 
  /// fractional floating-point numbers
  /// that sum to x. Both values have 
  /// the same sign as x.
  ///
  constexpr ModfResult modf(float64_t x) noexcept;
  ///
  /// Function nan returns 
  /// an IEEE 754 
  /// "not-a-number" value.
  ///
  constexpr float64_t nan() noexcept;
  ///
  /// Function nextafter returns 
  /// the next representable float64 value after 
  /// x towards y.
  ///
  constexpr float64_t nextafter(float64_t x, float64_t y) noexcept;
  ///
  /// Function nestafter returns 
  /// the next representable float32 value after 
  /// x towards y.
  ///
  constexpr float32_t nextafter(float32_t x, float32_t y) noexcept;
  ///
  /// Function pow returns x**y, 
  /// the base-x exponential of y.
  ///
  constexpr float64_t pow(float64_t x, float64_t y) noexcept;
  ///
  /// Function pow10 returns 10**n, 
  /// the base-10 exponential of n.
  ///
  constexpr float64_t pow10(int_t n) noexcept;
  ///
  /// Function remainder returns 
  /// the IEEE 754 floating-point remainder of x / y.
  ///
  constexpr float64_t remainder(float64_t x, float64_t y) noexcept;
  ///
  /// Function round returns
  /// the nearest integer, rounding 
  /// half away from zero.
  ///
  constexpr float64_t round(float64_t x) noexcept;
  ///
  /// Function round_to_even returns
  /// the nearest integer, rounding 
  /// ties to even.
  ///
  constexpr float64_t round_to_even(float64_t x) noexcept;
  ///
  /// Function signbit reports
  /// whether x is negative or 
  /// negative zero.
  ///
  constexpr bool signbit(float64_t x) noexcept;
  ///
  /// Function sin returns the sine of 
  /// the radian argument x.
  ///
  constexpr float64_t sin(float64_t x) noexcept;
  ///
  /// Function sincos returns sin(x), cos(x).
  ///
  constexpr SincosResult sincos(float64_t x) noexcept;
  ///
  /// Function sinh returns
  /// the hyperbolic sine of x.
  ///
  constexpr float64_t sinh(float64_t x) noexcept;
  ///
  /// Function sqrt returns
  /// the square root of x.
  ///
  constexpr float64_t sqrt(float64_t x) noexcept;
  ///
  /// Function tan returns
  /// the tangent of
  /// the radian argument x.
  ///
  constexpr float64_t tan(float64_t x) noexcept;
  ///
  /// Function tanh returns
  /// the hyperbolic 
  /// tangent of x.
  ///
  constexpr float64_t tanh(float64_t x) noexcept;
  ///
  /// Function trunc returns
  /// the integer value of x.
  ///
  constexpr float64_t trunc(float64_t x) noexcept;
  ///
  /// Function y0 returns
  /// the order-zero Bessel function of
  /// the second kind.
  ///
  constexpr float64_t y0(float64_t x) noexcept;
  ///
  /// Function y1 returns
  /// the order-one Bessel function of
  /// the second kind.
  ///
  constexpr float64_t y1(float64_t x) noexcept;
  ///
  /// Function yn returns
  /// the order-n Bessel function of
  /// the second kind.
  ///
  constexpr float64_t yn(int_t n, float64_t x) noexcept;
} // namespace math
} // namespace foot
#endif
