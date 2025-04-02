## Golden Ratio
Continued fraction expansion can be used to find rational approximations of a real number. The precision of the approximation found using convergents will be:

$$\delta= |\alpha-\frac{p_i}{q_i}| \leqslant \frac{1}{q_i^2}$$

Therefore, if it is necessary to find $\alpha$ with an accuracy of up to $n$ digits, the convergents $\frac{p_i}{q_i}$ can be used with the condition ${\log_{10}q_i^2}>n$. In the worst case, the number of iterations will not exceed ${\log_{\varphi}q_i^2}$, where $\varphi=\frac{1+\sqrt{5}}{2}$ is so called «golden ratio». 

Two adjacent terms of the Fibonacci sequence form a convergent what can be used to approximate $\varphi$. The *golden_ratio.c* function presented in this section is an example of the precision that can be achieved using convergents: using it you can find the decimal representation of the golden ratio with an accuracy of tens and even hundreds of thousands.

Use `make` to build executable and run it with `./gr`. Note: `GMP` library is required.
