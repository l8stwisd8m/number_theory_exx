## Greatest common divisor
**GCD** (greatest common divisor) of two integers is the largest natural integer is a divisor of these two integers.  

Let $a$ and $b$ be to non-negative integers not equal to zero at the same time.  The equality

$$ax+by=gcd(a, b)$$

called Bezout's identity can be used for modulo inversion: if $a$ and $b$ are coprime (i.e. $gcd(a, b) = 1$) there is only coefficient $x$ in range $(0, b)$ such that $ax \cong 1\:mod\:b$ since $by \cong 0\:mod\:b$.  
Greatest common divisor can be calculated using **Euclidean algorithm** (*gcd* function), and Bezout's coefficients can be obtained by applying **extended Euclidean algorithm** (*extended_gcd*). There are also **binary** forms of both mentioned algorithms: *binary_gcd* and *binary_extended_gcd*.

To build the executables: `make`.
You can run each function manually or use autorun script for preview:

    chmod +x autorun.sh
    ./autorun.sh

