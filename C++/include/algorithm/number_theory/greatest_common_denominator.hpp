/*
    Euclid's greatest common denominator algorithm
    ----------------------------------------------
    The basic Euclidean algorithm is used to find the greatest common denominator of two
    numbers, a and b. The Euclidean algorithm is based on the principle that the greatest
    common divisor of two numbers does not change if the larger number is replaced by its
    difference with the smaller number.

    Time complexity
    ---------------
    O(log10(m)), where m = min(a, b) is the smaller of the input integers a and b

    Space complexity
    ----------------
    O(1)
*/

/*
    greatest_common_denominator
    ---------------------------
    Returns the greatest common denominator of integers a and b.
*/

int greatest_common_denominator(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (a == 0) {
        return b;
    }

    return greatest_common_denominator(b % a, a);
}
