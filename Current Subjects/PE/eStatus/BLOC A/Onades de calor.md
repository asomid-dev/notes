**Som a l'any 2050, i el calor és insoportable. Quan comptem el nombre de setmanes que es arriba a temperatures superiors a 40 graus, hem obtingut aquest model probabílistic, expressat com la variable (X) que es distribueix com es mostra a continuació:**

**(poseu almenys tres decimals correctes a totes les respostes)**

![[Onades de calor.png]]

P(X = 4) = 0.341
P(X = 5) = 0.378
P(X = 6) = 0.281

#### 1. Digueu quin és el valor esperat del nombre de setmanes amb temperatura superior a 40 graus. 

> [!check] Solution
> ```R
> x <- c(4, 5, 6)
> p <- c(0.341, 0.378, 0.281)
> expected_value <- sum(x * p)
> print(expected_value) # 4.94
> ```
>
>
> **eStatus:** `4.940`

---
####  2. Calculeu el valor de la desviació tipus de la variable aleatòria X.

$$Var(X) = E[X^2] - E([X])^2$$

> [!check] Solution
> ```R
> x <- c(4, 5, 6)
> p <- c(0.341, 0.378, 0.281)
> mean_X <- sum(x * p)
> var_X <- sum((x^2) * p) - (mean_X^2)
> sd_X <- sqrt(var_X)
> print(sd_X) # 0.786384
> 
> ```
> 
> 
> **eStatus:** `0.786`

---
#### 3. També podem representar el nombre de setmanes amb la funció de distribució. Quina de les següents funcions és la real?
_**Respon amb 1, 2 o 3.**_

|             1              |             2              |             3              |
| :------------------------: | :------------------------: | :------------------------: |
| ![[onades de calor 1.png]] | ![[onades de calor 2.png]] | ![[onades de calor 3.png]] |

**eStatus:** `3` 

---
#### 4. Trobeu la probabilidad que, per a un lloc de la població tractada escollit a l'atzar, el nombre de setmanes amb calor alta estigui entre 6 i 6 (ambdós inclosos) 

> [!check] Solution
> ```R
> # P(6 <= X <= 6) = P(X = 6)
> # P(X = 6) = 0.281
> ```
> 
> 
> **eStatus:** `0.281`

---
#### 5. Apart d'interessar-nos pel nombre de setmanes amb temperatures extremes, estem estudiant la superfície cremada a un incendi forestal durant una onada de calor. La següent funció:
$$f_{s}(x)= 1e^{-1x}$$
pot ser un model adequat per a representar aquesta variable aleatòria que anomenarem S (superfície en milers d'hectàrees).

$$E[S] = \int_{0}^{\infty} x \cdot f_S(x) \, dx = \int_{0}^{\infty} x \cdot 1 e^{-1x} \, dx = \int_{0}^{\infty} x e^{-x} \, dx$$

An exponential distribution looks like:
$$f(x) = \lambda e^{-\lambda x} \quad for \; x \geq 0$$

$$E[S] = \frac{1}{\lambda} \quad \text{where } \lambda = 1$$
$$E[S] = \frac{1}{1} = 1$$

**eStatus:** `1`

---
#### 6. Quina és la probabilitat que, a un incendi qualsevol, la superfície cremada sigui entre 300 i 1700 ha?

$$E[S] = \int^{1.7}_{0.3} 1-e^{-1x}$$
$$(1 - e^{-1.7}) - (1 - e ^ {-0.3}) = -e^{-1.7} + e^{-0.3} = 0.5581346$$
**eStatus:** `0.5581346`

---
#### 7. Una de les següents corbes correspon a la funció de distribució de la variable S. Indica quina és la correcta responent amb el número (1, 2, 3 o 4).

![[onades de calor 7.png]]

$$x = 1 \to F(1) = 1 - e^{-1} = 1 - 0.367879 = 0.6321$$
**eStatus:** `4`
