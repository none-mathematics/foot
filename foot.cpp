//!
//! Copyright (c) 2023 none-mathematics
//! Use of this source code is governed by a MIT-style
//! license that can be found in the LICENSE file.
//!
#include "foot.h"
#include <iostream>
///
/// Testing class `foot::math`.
///
int main() {
  using foot::math;
  using std::cout;
  using std::endl;
  using std::ios_base;

  cout.setf(ios_base::dec, ios_base::basefield);
  cout.setf(ios_base::scientific, ios_base::floatfield);
  cout.setf(ios_base::left, ios_base::adjustfield);
  cout.precision(16);

  const math math{};
  cout << "\n\nMathematical constants.\n";
  cout << math.e << endl;
  cout << math.pi << endl;
  cout << math.phi << endl;
  cout << math.sqrt_2 << endl;
  cout << math.sqrt_e << endl;
  cout << math.sqrt_pi << endl;
  cout << math.sqrt_phi << endl;
  cout << math.log_e_2 << endl;
  cout << math.log_2_e << endl;
  cout << math.log_e_10 << endl;
  cout << math.log_10_e << endl;
  cout << "\n\nFloating-point limit values.\n";
  cout << math.max_float32 << endl;
  cout << math.smallest_nonzero_float32 << endl;
  cout << math.max_float64 << endl;
  cout << math.smallest_nonzero_float64 << endl;
  cout << "\n\nInteger limit values.\n";
  cout << math.max_int << endl;
  cout << math.min_int << endl;
  cout << static_cast<foot::int_t>(math.max_int8) << endl;
  cout << static_cast<foot::int_t>(math.min_int8) << endl;
  cout << math.max_int16 << endl;
  cout << math.min_int16 << endl;
  cout << math.max_int32 << endl;
  cout << math.min_int32 << endl;
  cout << math.max_int64 << endl;
  cout << math.max_uint << endl;
  cout << static_cast<foot::uint_t>(math.max_uint8) << endl;
  cout << math.max_uint16 << endl;
  cout << math.max_uint32 << endl;
  cout << math.max_uint64 << endl;

  return 0;
}
namespace foot {
constexpr math::math() noexcept {}
} // namespace foot
