# Examples of number theory problems
## Requirements
`GCC` and `make` to build executables;
`GMP` library for certain functions.
## Continued fractions
A **continued fraction** $\alpha\in \mathrm{Q}$ is expession of the form
$$
\alpha=a_0+\frac{1}{a_1+\frac{1}{\ldots+\frac{1}{a_n}}}
$$
where $a_0\in \mathrm{Z}$ and $a_i\in \mathrm{N}, i\in[1, n]$. This form is often called expansion (continued fraction representation) of $\alpha$, and notation $\alpha=[a_0; a_1, a_2 \ldots a_n]$ is used for shorthand.
Function *cf_expansion* is designed to find the decomposition of a rational number into a fraction. Restoring initial number using its expansion can be called generalization; function *cf_generalization* is an example.

**Convergents** $\frac{p_0}{q_0}=[a_0], \frac{p_1}{q_1}=[a_0; a_1]   
\ldots\frac{p_n}{q_n}=[a_0; a_1 \ldots a_n]$ are rational approximations of $\alpha$. Convergents can be calculated using modification of extended Euclidean algorithm. Series of convergents can be found using *cf_convergents* function.

To build executables: `make`.
You can run each function manually or use autorun script for preview:

    `chmod +x autorun.sh`
    `./autorun.sh`