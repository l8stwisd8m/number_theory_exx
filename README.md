# Examples of number theory problems

## Overview
The topics covered are listed below. Each topic is accompanied by a brief entroduction, more detailed information is provided in the relevant section.
1. [Continued fractions](#continued-fractions-1)
2. [Golden Ratio](#golden-ratio-2)
3. [Various sequences](#various-sequences-3)

## Requirements
`GCC` and `make` to build executables;
`GMP` library for certain functions.

## Continued fractions
A **continued fraction** $\alpha\in \mathrm{Q}$ is expession of the form

$$\alpha=a_0+\frac{1}{a_1+\frac{1}{\ldots+\frac{1}{a_n}}}$$

where $a_0\in \mathrm{Z}$ and $a_i\in \mathrm{N}, i\in[1, n]$. This form is often called expansion (continued fraction representation) of $\alpha$, and notation $\alpha=[a_0; a_1, a_2 \ldots a_n]$ is used for shorthand.
Function *cf_expansion* is designed to find the decomposition of a rational number into a fraction. Restoring initial number using its expansion can be called generalization; function *cf_generalization* is an example.

**Convergents** $\frac{p_0}{q_0}=[a_0], \frac{p_1}{q_1}=[a_0; a_1] \ldots \frac{p_n}{q_n}=[a_0; a_1 \ldots a_n]$ are rational approximations of $\alpha$. Series of convergents can be found using *cf_convergents* function (it applies a modification of extended Euclidean algorithm).

To build executables: `make`.
You can run each function manually or use autorun script for preview:

    chmod +x autorun.sh
    ./autorun.sh

## Golden Ratio
Continued fraction expansion can be used to find rational approximations of a real number. The precision of the approximation found using convergents will be:

$$\delta= |\alpha-\frac{p_i}{q_i}| \leqslant \frac{1}{q_i^2}$$

Therefore, if it is necessary to find $\alpha$ with an accuracy of up to $n$ digits, the convergents $\frac{p_i}{q_i}$ can be used with the condition ${\log_{10}q_i^2}>n$. In the worst case, the number of iterations will not exceed ${\log_{\varphi}q_i^2}$, where $\varphi=\frac{1+\sqrt{5}}{2}$ is so called «golden ratio». 

Two adjacent terms of the Fibonacci sequence form a convergent what can be used to approximate $\varphi$. The *golden_ratio.c* function presented in this section is an example of the precision that can be achieved using convergents: using it you can find the decimal representation of the golden ratio with an accuracy of tens and even hundreds of thousands.

Use `make` to build executable and run it with `./gr`. Note: `GMP` library is required.

## Various sequences 
**Farey series** is the sequence of fractions in range $[0, 1]$ corresponding one-to-one to the positive rational numbers. Farey series can be represented as a binary tree, which is a subtree of the **Stern-Brocot tree** --- the set of all nonegative completely reduced fractions, corresponding to every positive rational number. It can be constucted according to the following rule:

There are two initial fractions --- $\frac{n}{d}$ and $\frac{n'}{d'}$. Next fraction $\frac{n+n'}{d+d'}$, called **mediant**, should be places between two adjacent fractions, considering the inequality $\frac{n}{d}<\frac{n+n'}{d+d'}<\frac{n'}{d'}$.

The entire Farey series array can be constructed if initial fractions are $\frac{n}{d}=\frac{0}{1};\frac{n'}{d'}=\frac{1}{1}$, and $\frac{n}{d}=\frac{0}{1};\frac{n'}{d'}=\frac{1}{0}$ for Stern-Brocot tree array. 
The top level of tree (first node, vertice) will be $\frac{1}{2}$ for Farey series and $\frac{1}{1}$ for Stern-Brocot.

The **Calkin-Wilf tree** is a binary tree similar to the Stern-Brocot. The main difference is its generative rule: on the top layer, first node $\frac{n}{d}$ is equal to $\frac{1}{1}$ and it's descendants are $\frac{n}{n+d}$ and $\frac{n+d}{d}$. 
