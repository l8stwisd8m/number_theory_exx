## Various sequences 
**Farey series** is the sequence of fractions in range $[0, 1]$ corresponding one-to-one to the positive rational numbers. Farey series can be represented as a binary tree, which is a subtree of the **Stern-Brocot tree** --- the set of all nonegative completely reduced fractions, corresponding to every positive rational number. It can be constucted according to the following rule:

There are two initial fractions --- $\frac{n}{d}$ and $\frac{n'}{d'}$. Next fraction $\frac{n+n'}{d+d'}$, called **mediant**, should be places between two adjacent fractions, considering the inequality $\frac{n}{d}<\frac{n+n'}{d+d'}<\frac{n'}{d'}$.

The entire Farey series array can be constructed if initial fractions are $\frac{n}{d}=\frac{0}{1};\frac{n'}{d'}=\frac{1}{1}$, and $\frac{n}{d}=\frac{0}{1};\frac{n'}{d'}=\frac{1}{0}$ for Stern-Brocot tree array. 
The top level of tree (first node, vertice) will be $\frac{1}{2}$ for Farey series and $\frac{1}{1}$ for Stern-Brocot.

The **Calkin-Wilf tree** is a binary tree similar to the Stern-Brocot. The main difference is its generative rule: on the top layer, first node $\frac{n}{d}$ is equal to $\frac{1}{1}$ and it's descendants are $\frac{n}{n+d}$ and $\frac{n+d}{d}$. 
