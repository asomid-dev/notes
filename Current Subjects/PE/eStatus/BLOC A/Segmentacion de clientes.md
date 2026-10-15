**Un banco clasifica a sus clientes según si poseen tarjeta de crédito (T: sí; ¬T: no) y si domicilian la nómina (N: sí; ¬N: no).
Interesa estudiar la solvencia de un cliente cuando solicita un crédito. Analizando datos previos, se ha determinado la proporción de clientes solventes (79.6%) e insolventes (20.4%), así como la distribución de las cuatro categorías resultantes de la anterior clasificación (siguiendo el orden de las celdas de arriba abajo, por columnas), según la solvencia del cliente:**

**Solventes:**

|        | N      | ¬N     |
| ------ | ------ | ------ |
| **T**  | 0.3662 | 0.2135 |
| **¬T** | 0.3279 | 0.0924 |

**No solventes:**

|        | N      | ¬N     |
| ------ | ------ | ------ |
| **T**  | 0.1431 | 0.2387 |
| **¬T** | 0.1833 | 0.4349 |

#### 1. En porcentaje: ¿cuántos clientes son de la primera categoría? ($T \cap N$)

> [!check] Solution
> ```R
> P_T_N <- (0.3662 * 0.796) + (0.1431 * 0.204)
> print(P_T_N * 100) # 32.06876
> 
> ```
> 
> 
> **eStatus:** `32.0688` (o `32.07`)

---
#### 2. ¿Cuál es la probabilidad de que un cliente solvente tenga tarjeta? ($P(T \mid S)$)

> [!check] Solution
> ```R
> p_T_given_S <- 0.3662 + 0.2135
> print(p_T_given_S) # 0.5797
> 
> ```
> 
> 
> **eStatus:** `0.5797`

---
#### 3. ¿Cuál es la probabilidad de que un cliente solvente sólo tenga tarjeta? ($P(T \cap \neg N \mid S)$)

> [!check] Solution
> ```R
> p_only_T_S <- 0.2135
> print(p_only_T_S) # 0.2135
> 
> ```
> 
> 
> **eStatus:** `0.2135`

---

#### 4. Ante un cliente, ¿qué probabilidad existe de que fuera insolvente y tuviera la nómina domiciliada? ($P(\neg S \cap N)$)

> [!check] Solution
> ```R
> P_not_S_and_N <- (0.1431 + 0.1833) * 0.204
> print(P_not_S_and_N) # 0.0665856
> 
> ```
> 
> 
> **eStatus:** `0.0666` (o `0.06659`)

---

#### 5. Si analizamos un cliente insolvente, ¿con qué probabilidad éste tendría algún producto (tarjeta o nómina)?

> [!check] Solution
> ```R
> p_at_least_one_given_not_S <- 1 - 0.4349
> print(p_at_least_one_given_not_S) # 0.5651
> 
> ```
> 
> 
> **eStatus:** `0.5651`

---

#### 6. Calcule la probabilidad de que un cliente cualquiera tenga nómina domiciliada y sea solvente. ($P(N \cap S)$)

> [!check] Solution
> ```R
> P_N_and_S <- (0.3662 + 0.3279) * 0.796
> print(P_N_and_S) # 0.5525036
> 
> ```
> 
> 
> **eStatus:** `0.5525` (o `0.552504`)

---

#### 7. De cada 100 clientes: ¿cuántos no tienen tarjeta ni domicilian su nómina?

> [!check] Solution
> ```R
> P_none_total <- (0.0924 * 0.796) + (0.4349 * 0.204)
> print(P_none_total * 100) # 16.227
> 
> ```
> 
> 
> **eStatus:** `16.2` (o `16.23` según decimales)

---

#### 8. Un cliente de la categoría 4) solicita un crédito al banco. ¿Probabilidad de que sea insolvente?

> [!check] Solution
> ```R
> P_not_S_given_cat4 <- (0.4349 * 0.204) / ((0.0924 * 0.796) + (0.4349 * 0.204))
> print(P_not_S_given_cat4) # 0.546741
> 
> ```
> 
> 
> **eStatus:** `0.5467`

---

#### 9. Repita la pregunta anterior para un cliente de la categoría 1).

> [!check] Solution
> ```R
> P_not_S_given_cat1 <- (0.1431 * 0.204) / ((0.3662 * 0.796) + (0.1431 * 0.204))
> print(P_not_S_given_cat1) # 0.091031
> 
> ```
> 
> 
> **eStatus:** `0.0910`

---

#### 10. Si con un cliente solvente el banco tiene un beneficio de 1000 euros al año, y pierde 600 con uno insolvente, ¿qué beneficio promedio por cliente tiene el banco?

> [!check] Solution
> ```R
> avg_profit <- (1000 * 0.796) + (-600 * 0.204)
> print(avg_profit) # 673.6
> 
> ```
> 
> 
> **eStatus:** `673.6` (o `673.60`)
