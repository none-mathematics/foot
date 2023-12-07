//!
//! Copyright (c) 2023 none-mathematics
//! Use of this source code is governed by a MIT-style
//! license that can be found in the LICENSE file.
//!
#include "foot.h"
#include <iostream>
///
/// Testing.
///
int main() {
  using std::cout;
  using std::endl;
  using std::ios_base;

  cout.setf(ios_base::dec, ios_base::basefield);
  cout.setf(ios_base::scientific, ios_base::floatfield);
  cout.setf(ios_base::left, ios_base::adjustfield);
  cout.precision(16);
  
  return 0;
}
