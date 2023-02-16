#pragma once

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num) {
  const int pick = 6;
  if (pick == num) {
    return 0;
  } else if (pick > num) {
    return 1;
  } else {
    return -1;
  }
}
