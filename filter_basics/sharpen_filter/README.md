# Realçando uma Imagem (Sharpening)

Para realçar a imagem devemos recordar que a operação de **Blur** retira as altas frequências de uma imagem, ou seja, após esta operação teremos uma imagem com frequências mais baixas.
<p align="center">
<img src='images/blur_diagram.png' width='350'>
</p>

A seguir mostramos a matemática envolvida no processo de **_realce da imagem_** .
* **_I_** - imagem original
* **_I<sub> b</sub>_** - imagem blured: contém as baixas frequências da imagem original

Seja **_M_** definada por $$\begin{eqnarray}M =I-I_b\end{eqnarray}$$ 

como estamos retirando as baixas frequências presentes em **_I<sub>b</sub>_**, então **_M_** é uma imagem quem contém as altas frequências da imagem original **_I_**.

  Deste modo podemos criar uma cópia mais nítida **_H_** da nossa imagem aplicando a seguinte estratégia   
$$\begin{eqnarray} H=I+kM \text{ }:k \in \mathbb{R} \end{eqnarray}$$

Arrumando a equação temos:
$$\begin{aligned} 
  H&=I+k(I-I_b)\\ 
  H&=(k+1)I-I_b\\
  \end{aligned}$$
 
```
  cv::addWeighted(src, k + 1, current_blur_filter, -k, 0, result);
```
### Resultados:


Imagem Original          |  Box Filter (5x5)  | Gaussian Filter(5x5) sigma= 5.5 | Median Filter(7x7) kernel=5
:-------------------------:|:-------------------------:|:-------------------------:|:-------------------------:
<img src='images/original.png' width='250'>   |  <img src='images/box_sharpen.png' width='250'> | <img src='images/gauss_sharpen.png' width='250'> |<img src='images/median_sharpen.png' width='250'>


