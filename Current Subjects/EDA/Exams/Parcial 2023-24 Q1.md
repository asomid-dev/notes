# EDA PARCIAL 2023/24 Q1
#eda #examen #PARCIAL1 

## Problema 1 (3.5 pts.)
Respon a les següents preguntes:
**(a) (1 pt.)** Cada fila de la següent taula representa una certa etapa de l'execució d'un algorisme d'ordenació conegut (selecció, inserció, quicksort i mergesort) sobre el vector 10 2 5 3 7 13 1 6 . Escriviu al costat de cada fila a quin d’aquests algorismes correspon. Cada algorisme ha d'aparèixer exactament una vegada. 1 o cap resposta correcta puntuarà 0 punts i 2 respostes correctes, 0.5 punts. Si repetiu algun algorisme, us atorgarem 0 punts. No cal que justifiqueu la vostra resposta.

2 3 5 10 1 6 7 13 $\to$ MergeSort
2 3 5 10 7 13 1 6 $\to$ InsertionSort
6 2 5 3 7 1 13 10 $\to$ QuickSort 
1 2 3 5 6 13 10 7 $\to$ SelectionSort

**(b) (1 pt.)** Ordena les funcions $(\log_{2} \log_{2} n)^{2}$ i $\log_{2} n$ segons el seu creixement asimptòtic. Recorda que cal justificar la resposta.

**(c) (1.5 pts.)** Sigui T un arbre binari de cerca que implementa un diccionari, on les claus són nombres enters. Donades dues claus diferents $x, y$, que apareixen a T, definim el _menor ancestre comú de x i y_ com l'ancestre comú de $x$ i $y$ que té major distància respecte l'arrel. Per exemple, en el següent arbre el menor ancestre comú de 7 i 17 és el 15, el de 42 i 73 és el 70, i el de 15 i 17 és 15.