# Realçando uma Imagem (Sharpening)

Para realçar a imagem devemos recordar que a operação de **Blur** retira as altas frequências de uma imagem, ou seja, após esta operação teremos uma imagem com frequências mais baixas.
<p align="center">
<img src='images/blur_diagram.png' width='350'>
</p>

A seguir mostramos a matemática envolvida no processo de **_realce da imagem_** .
* **_I_** - imagem original
* **_I<sub> b</sub>_** - imagem blured: contém as baixas frequencias da imagem original

Portanto 
$$
m=I-I_b \text{ (imagem com as altas frequencias da imagem original)}
$$
Deste modo, tomando atenuamos nossa imagem aplicando um fator $$k \in \mathbb{R}$$ e criamos a imagem  
$$\begin{eqnarray} H=I+km  \end{eqnarray}$$

Observe que agora **_H_** trata-se de uma imagem mais nítida pois somamos à imagem original **_I_** uma imagem contendo suas altas frequencias ampliadas por um fator **_k_**. Temos então que:

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


