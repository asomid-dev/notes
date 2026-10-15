# Counting & Colours

**You can see on the right two urns containing cyan and red balls. When a ball is drawn from an urn, it is assumed that it has been chosen randomly. Sometimes the urn is selected before with the aid of a coin (see above the urn). Read and answer the following questions**

Image content:

tails: 2 Cyan, 4 Red
heads: 2 Cyan, 11 Red

#### 1. A ball is picked, it doesn't matter from which urn. What is the probability that you get a cyan ball?

> [!check] Solution
> ```R
> P_C <- (2/6 * 0.5) + (2/13 * 0.5)
> print(P_C) # 0.243590
> 
> ```
> 
> 
> **eStatus:** `0.2436`

---
#### 2. If all the balls were mixed in a single urn, which would be the proportion of cyan balls then?

> [!check] Solution
> ```R
> total_cyan <- 2 + 2 # 4
> total_balls <- (2 + 4) + (2 + 11) # 19
> proportion <- total_cyan / total_balls
> print(proportion) # 0.210526
> 
> ```
> 
> 
> **eStatus:** `0.2105`

---
#### 3. You take one ball from each urn. What is the probability that the balls are of different colors?

> [!check] Solution
> ```R
> prob_diff <- (2/6 * 11/13) + (4/6 * 2/13)
> print(prob_diff) # 0.384615
> 
> ```
> 
> 
> **eStatus:** `0.3846`

---
#### 4. You flip a coin, and you obtain heads. What is the probability of getting a red ball?

> [!check] Solution
> ```R
> p_red_given_heads <- 11 / 13
> print(p_red_given_heads) # 0.846154
> 
> ```
> 
> 
> **eStatus:** `0.8462`

---
#### 5. A different flip of the coin: a red ball was drawn from the selected urn. Find the probability that the coin was heads.

> [!check] Solution
> ```R
> P_Red <- (11/13 * 0.5) + (4/6 * 0.5)
> P_Heads_given_Red <- (11/13 * 0.5) / P_Red
> print(P_Heads_given_Red) # 0.559322
> 
> ```
> 
> 
> **eStatus:** `0.5593`

---
#### 6. You are asked to choose an urn with the coin, and pick two balls (without replacement) from it. The balls happen to be both of cyan color. What is the probability that the coin was tails?

> [!check] Solution
> ```R
> # Using choose() to compute combinations without replacement:
> # Number of ways to choose 2 cyan balls out of available cyan ones, 
> # divided by the total ways to choose 2 balls out of the urn's total.
> p_cc_tails <- choose(2, 2) / choose(6, 2)
> p_cc_heads <- choose(2, 2) / choose(13, 2)
> 
> # Law of Total Probability to find total P(CC)
> p_cc <- (p_cc_tails * 0.5) + (p_cc_heads * 0.5)
> 
> # Bayes' Theorem to find P(Tails | CC)
> p_tails_given_cc <- (p_cc_tails * 0.5) / p_cc
> print(p_tails_given_cc) # 0.838710
> 
> ```
> 
> 
> **eStatus:** `0.8387`
