## 1. Core Mathematical Syntax

| Math Concept               | LaTeX Code                               | Visual Result                                            | Key Notes                                                |
| :------------------------- | :--------------------------------------- | :------------------------------------------------------- | :------------------------------------------------------- |
| **Inline Math**            | `Let $V$ be a vector space.`             | Let $V$ be a vector space.                               | Keeps math inside a sentence.                            |
| **Block Math**             | `$$\mathbf{Ax} = \lambda\mathbf{x}$$`    | $$\mathbf{Ax} = \lambda\mathbf{x}$$                      | Centers math on its own line.                            |
| **Vector Notation**        | `\vec{v}` or `\mathbf{v}`                | $$\vec{v} \;or\;\mathbf{v}$$                             | Bold text is standard in modern textbooks.               |
| **Greek Letters**          | `\lambda, \alpha, \beta, \theta`         | $$\lambda, \alpha, \beta, \theta$$                       | Commonly used for eigenvalues and scalars.               |
| **Set Membership**         | `\in \mathbb{R}^n`                       | $$\in \mathbb{R}^n$$                                     | "Element of the set of Real Numbers in n-dimensions".    |
| **Subscripts**             | `\lambda_1, x_n`                         | $$\lambda_1, x_n$$                                       | Use `_` for subscripts.                                  |
| **Ellipsis (Dots)**        | `\dots` , `\cdots` , `\vdots` , `\ddots` | $$\dots \;,\; \cdots\;,\; \vdots\;\;\text{or}   \ddots$$ | `\dots` sits on the bottom; `\cdots` sits in the center. |
| **Standard Space**         | `\quad` or `\qquad`                      | $$\text{a}\quad \text{or} \qquad\text{a}$$               | Push elements apart horizontally.                        |
| **Text inside Math**       | `\text{for all } i`                      | $$\text{for all } i$$                                    | Keeps font normal and preserves regular spaces.          |
| **For All / There exists** | `\forall` & `\exists`                    | $$\forall \;,\; \exists$$                                | $$\text{-}$$                                             |
| **Spaces**                 | `\;` & `\ `                              | $$Hi, \; my\ name\ is \dots$$                            | First space done with `\;` the other ones with `\ ` .    |


---

## 2. Matrices & Layouts

#### Parentheses Matrix (`pmatrix`)
Use `&` to separate columns, and `\\` to create a new row.

```LaTeX
$$\begin{pmatrix} 
a & b \\ 
c & d 
\end{pmatrix}$$
```
$$\begin{pmatrix} 
a & b \\ 
c & d 
\end{pmatrix}$$
#### Bracket Matrix (`bmatrix`)

```LaTeX
$$\begin{bmatrix} 
a & b \\ 
c & d 
\end{bmatrix}$$
```
$$\begin{bmatrix} 
a & b \\ 
c & d 
\end{bmatrix}$$
#### Determinant (`vmatrix`)

``` LaTeX
$$\begin{vmatrix} 
a & b \\ 
c & d 
\end{vmatrix}$$
```
$$\begin{vmatrix} 
a & b \\ 
c & d 
\end{vmatrix}$$

## 3. Systems & Multi-line Equations
#### Step-by-Step Alignments (`align*`)

```LaTeX
$$\begin{align*}
2x + 5 &= 11 \\
2x &= 6 \\
x &= 3
\end{align*}$$ 
```
$$\begin{align*}
2x + 5 &= 11 \\
2x &= 6 \\
x &= 3
\end{align*}$$
#### Systems of Equations
```LaTeX
$$\left\{
\begin{aligned}
x + y &= 2 \\
2x - y &= 1
\end{aligned}
\right. 
$$
``` 
$$\left\{
\begin{aligned}
x + y &= 2 \\
2x - y &= 1
\end{aligned}
\right.$$
