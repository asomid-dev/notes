# Sorolls Alarmants

**En una botiga amb sistema de seguretat, la probabilitat que una nit qualsevol hi hagi un intent de robatori és 0.118. Si hi ha intent de robatori, l’alarma es dispara amb probabilitat 0.842 però, encara que no n’hi hagi, l'alarma es pot disparar amb probabilitat 0.041. Es demana que calculeu (amb quatre decimals exactes, almenys):** 

#### 1. Escollim a l'atzar un dia de l'any. Calculeu la probabilitat que l'alarma soni la nit del dia escollit.

> [!check] Solution
> ```R
> P_R <- 0.118
> P_not_R <- 1 - P_R
> P_A_given_R <- 0.842
> P_A_given_not_R <- 0.041
> 
> P_A <- (P_A_given_R * P_R) + (P_A_given_not_R * P_not_R)
> print(P_A) # 0.135518
> 
> ```
> 
> 
> **eStatus:** `0.1355`

---

#### 2. Altra vegada hem seleccionat una nit qualsevol. Quina és la probabilitat que en aquesta ocasió hi hagi un intent de robatori i l’alarma soni?

> [!check] Solution
> ```R
> P_R <- 0.118
> P_A_given_R <- 0.842
> P_R_and_A <- P_A_given_R * P_R
> print(P_R_and_A) # 0.099356
> 
> ```
> 
> 
> **eStatus:** `0.0994`

---

#### 3. Trobeu ara la probabilitat d'un intent de robatori si l’alarma sona.

> [!check] Solution
> ```R
> P_R_given_A <- P_R_and_A / P_A
> print(P_R_given_A) # 0.733157
> 
> ```
> 
> 
> **eStatus:** `0.7332`

---

#### 4. Una certa nit l’alarma no ha sonat. Probabilitat que efectivament no hi hagi hagut un intent de robatori?

> [!check] Solution
> ```R
> P_not_A <- 1 - P_A
> P_not_A_given_not_R <- 1 - P_A_given_not_R
> P_not_R_given_not_A <- (P_not_A_given_not_R * P_not_R) / P_not_A
> print(P_not_R_given_not_A) # 0.978433
> 
> ```
> 
> 
> **eStatus:** `0.9784`

---

#### 5. Una altra botiga, en un carrer diferent, porta el mateix sistema d’alarma (que es dispara d’acord amb les probabilitats especificades a dalt). Aquesta alarma sona el 29.8% de les nits, amb motiu o no. Es tracta de trobar la probabilitat d’intent de robatori per a aquesta segona botiga.

> [!check] Solution
> ```R
> P_A_store2 <- 0.298
> P_R_store2 <- (P_A_store2 - P_A_given_not_R) / (P_A_given_R - P_A_given_not_R)
> print(P_R_store2) # 0.320849
> 
> ```
> 
> 
> **eStatus:** `0.3208`
