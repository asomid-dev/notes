# Software Aging

_**"Programs, like people, get old. We can’t prevent aging, but we can understand its causes, take steps to limit its effects, temporarily reverse some of the damage it has caused, and prepare for the day when the software is no longer viable."**_

Para investigar alrededor de esta cuestión, tienes que crear un modelo destinado a representar una variable que representa el número de fallos que semanalmente presenta un servidor web de determinada arquitectura.

En esta ocasión, este dato no te lo dará la aplicación, sino que lo tienes que introducir tú.  
En la primera de las preguntas que vienen a continuación has de poner los valores que se pueden observar en tu variable "nº de fallos"  
(los valores han de ser enteros entre 0 y 20, pero no necesariamente todos ellos).  
En la segunda pregunta definirás las probabilidades correspondientes a cada resultado.  
Es aconsejable ir respondiendo las preguntas y corrigiendo una a una.

#### 1. En primer lugar, introduce la lista X de los diferentes valores que toma la variable que vas a crear. Para que el problema sea más interesante, debe haber más de cuatro.

*Nota: deben ser números distintos, separados por espacios, por ejemplo: 2 4 6 8 10.*

> [!check] Solution
> ```R
> X <- c(1, 2, 3, 4, 5)
> 
> ```
> 
> 
> **eStatus:** `1 2 3 4 5`

---
#### 2. ¿Qué función de probabilidad asignamos a la variable en cuestión, relacionada con los valores anteriores? Atención: aquí debes utilizar forzosamente el valor 0.04, en alguna posición.

> [!check] Solution
> ```R
> p <- c(0.04, 0.20, 0.30, 0.26, 0.20)
> sum(p) == 1 # TRUE
> 
> ```
> 
> 
> **eStatus:** `0.04 0.20 0.30 0.26 0.20`

---
#### 3. Calcula la esperanza del número de fallos para la distribución que has creado.

> [!check] Solution
> ```R
> x <- c(1, 2, 3, 4, 5)
> p <- c(0.04, 0.20, 0.30, 0.26, 0.20)
> E_X <- sum(x * p)
> print(E_X) # 3.38
> 
> ```
> 
> 
> **eStatus:** `3.38`

---
#### 4. Halla a continuación la desviación típica del número de fallos del servidor web.

> [!check] Solution
> ```R
> E_X2 <- sum((x^2) * p)
> var_X <- E_X2 - (E_X)^2
> sd_X <- sqrt(var_X)
> print(sd_X) # 1.1294
> 
> ```
> 
> 
> **eStatus:** `1.1294` (or `1.13`)

---
#### 5. Invéntate un modelo distinto para la misma variable, aunque en una situación en la que hipotéticamente hay menos variabilidad. Utiliza los mismos valores para X, una media similar (±5%) pero reduce la variancia al menos un 50%.

> [!check] Solution
> ```R
> p_new <- c(0, 0.03, 0.71, 0.26, 0)
> # Mean = 3.23 (within ±5% of 3.38)
> # Variance = 0.2371 (>50% reduction from 1.2756)
> 
> ```
> 
> 
> **eStatus:** `0 0.03 0.71 0.26 0`

---
#### 6. En una semana concreta, se ha observado un número de fallos en el servidor menor que la esperanza. Considerando esta información, ¿cuál sería entonces la expresión de la función de probabilidad de tu variable (la de las preguntas 1 y 2)? *(contesta usando porcentajes, redondeando al entero más próximo)*

> [!check] Solution
> ```R
> # Conditional probabilities for X < 3.38 (X = 1, 2, 3):
> # P(X = 1) = 0.04 / 0.54 = 7.41% -> 7
> # P(X = 2) = 0.20 / 0.54 = 37.04% -> 37
> # P(X = 3) = 0.30 / 0.54 = 55.56% -> 56
> # P(X = 4) = 0% -> 0
> # P(X = 5) = 0% -> 0
> 
> ```
> 
> 
> **eStatus:** `7 37 56 0 0`
