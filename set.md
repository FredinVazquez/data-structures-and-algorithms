<h1 align="center">Set</h1>

```c++
#include <set> 
```

<p>
Se debe de saber que existen dos versiones de set:
<br>
<ul>
<li>Set (normal)</li>
<li>Unordered_set</li>
</ul>
<br>
El set, normal, se caracteriza por guardar datos de tal modo una sola vez y en orden, esto 
es debido a que es un árbol binario, entonces se va permitir insertar y eliminar elementos 
de forma eficiente. Mientras que el unordered set no guarda los elementos con un orden, sino que es como caiga.<br><br>
Por otro lado, cuando se tiene varios elementos repetidos y se quiere construir un set 
existe la estructura llamada: multiset < int > ms; la cual va a tener las mismas funciones 
además de que permite guardar elementos repetidos dentro del árbol.<br><br>
No obstante, cuando se tiene que realizar búsquedas dentro del set se puede hacer usando los dos algoritmos conocidos:<br><br>
<ul>
<li>Lower_bound</li>
<li>Upper_bound</li>
</ul>
<br><br>
Método de invocación: 
<br>

```c++
s.lower_bound(elemento buscar)
```


Es necesario saber que no es posible acceder directamente a un valor dentro de un set, 
no obstante es posible realizar el recorrido del mismo por medio de un set y usando los 
iteradores ya conocidos:<br>

```c++
for(auto it: set) 
    cout<<it;
```

<br>
Ahora, volviendo a la búsqueda con lower y upper bound, es necesario tener en cuenta qué es lo que se quiere realizar, debido a que lower bound regresa un iterador el cual estará apuntando a un valor dentro de set y este valor bien puede ser dos posible:<br><br>
<ul>
<li>El valor apuntado es el valor buscado</li>
<li>El valor apuntado es mayor al valor buscado</li>
</ul>
<br><br>
Por otro lado, el upper bound solo es capaz de regresar un iterador que esté apuntando a un valor mayor al valor buscado.
<br><br>
<hr>
Nota: en ambos algoritmos en caso de no encontrar el elemento en cuestión se regresa 
un iterador que esté apuntando al inicio, entonces se debe de hacer esa comprobación.
<hr><br>
El problema es cuando se necesita un valor menor al buscado se debe de tener en cuenta 
qué tipo de estructura usar, debido a que un set normal solo mantiene elementos que no 
están repetidos mientras que un multiset puede mantener elementos repetidos. Entonces, 
se escoge según diga la situación.<br><br>
No obstante existen mucho los casos en donde se debe de realizar la búsqueda y borrar los números dentro de una lista, entonces se emplea un set y si son repetidos se puede  emplear un multiset, la cuestión es que se llega a complicar un poco el tener que encontrar un elemento que sea menor al elementos buscado, debido a que si hay valores repetidos entonces se tendrá un problema debido que al buscar nos va a devolver la primera ocurrencia de dicho valor dentro del set, entonces en este punto al ser repetido el valor no será posible tan solo disminuir el iterador (--it) debido a que no se sabe cuántas veces se encuentra repetido el valor dentro del set.<br><br>
Se puede tener como ejemplo:<br>

```c++
1 2 8 8 8 9
```

<br>
Entonces, si yo quiero el valor dentro del multiset que sea menor a 3 solo hago:<br>

```c++
auto it = multiset.lower_bound(3);
cout<<(*(--it));
```

<br>
El problema es cuando quiero tener el menor a 7 dentro del set:
<br>

```c++
auto it = multiset.lower_bound(3);
cout<<(*(--it));
```

<br>
Si hago este en realidad me encuentro en el segundo 8 encontrado, se ve de derecha a 
izquierda.
Entonces, tendría que realizar 3 disminuciones para llegar al 2 el cual es el valor menor 
más cercano al 7. El problema es que no voy a saber cuántas veces tendré que realizar la 
disminución para diferentes casos.
La solución a esto será reemplazar el multiset con un set de tal modo que no se va a 
poder repetir, entonces para solucionar primero esto se va realizar un set de pares.<br><br>

```c++
set< pair<int,int> > s;
```

De tal forma que mientras los valores secundarios de los pares sean diferentes entre ellos 
no habrá problema y no importará que se repitan valores en el primer espacio del par. <br><br>
Esto mismo se puede hacer para los segundos, se generaliza que mientras uno, el segundo o el primero, sean diferentes entre ellos el restantes podrá ser iguales y se 
guardarán en el set normal entonces ya no se tendría que ocupar un multiset.<br><br>
Entonces, como conclusión en la primera posición se guardan los valores de interés y 
será capaz de contener a os valores de interés que estén repetidos. Pero el segundo valor debe ser siempre diferente.<br><br>
Ahora, para realizar una búsqueda se debe de tomar en cuenta que ahora se estará haciendo sobre pares, entonces se debe de tener en cuenta ciertas cosas.<br><br>
Inserción de pares:

```c++
for(int i=0;i<n;i++)
 {
 cin>>aux; // Valores de interés
 s.insert({aux,i});
 }
```

<br>
Mientras que en el lower bound se debe de tener lo siguiente que es importante para poder obtener valores iguales o menores a al valor buscado.<br>

```c++
#define INF_N -1e18
… // Resto del código
auto it= s.lower_bound({v[i],INF_N});
```

<br>
<hr>
Nota: se recuerda que se debe de hacer la comprobación de que no sea el iterador begin().<hr><br>

El valor que estará apuntando el iterador será un número que sea menor o igual al valor 
buscado.<br><br>

Entonces, ya se puede hacer las comprobaciones:<br><br>

```c++
if(it == s.begin() && (*it).first != v[i]) printf("Valor no encontrado\n");
 else
    {
    if((*it).first == v[i]) // Se comprueba si el valor dado es igual al buscado
        {
        cout<<((*it).first)<<” el valor regresado es el buscado”<<endl;
        }
    else // en caso contrario, el valor regresado es menor al buscado
        {
        
        --it;
        cout<<((*(it)).first)<<” el valor regresado es menor al buscado”<<endl;
        
        }
 }
```

<br>
<h3>¿Por qué funciona esto?</h3>
<br>
Bien, el criterio que sigue el algoritmo de lower bound es finalmente una comparación, no quiero decir que su funcionamiento sea completamente basado en comparaciones debido a que se estaría teniendo una complejidad igual o similar al algoritmo de búsqueda lineal, pero finalmente llega un momento donde el lower bound debe de realizar comparaciones para poder seguir avanzando y dar una solución. Debido a lo anterior, se puede pensar qué es lo que sucede cuando encuentra que en la búsqueda se está realizando sobre pares, bien ahí el valor usado para realizar estas comparaciones será el primer valor: FIRST.<br><br>
No obstante, en caso que se encuentre que dos elementos son los mismos se tiene el caso actual, valores repetidos por lo tanto si no hubiera un elementos secundario simplemente el valor a tomar será la primera ocurrencia visto anteriormente, pero como en este caso se tiene un segundo valor el algoritmo se hará valer usando ese segundo valor.<br><br>
Entonces, si los valores first son iguales procede a realizar la comparación con los valores secundarios, second, y gracias a ellos sabrá cuál va antes y cuál va después. Entonces al 
nosotros colocar en la búsqueda.<br><br>

```c++
lower_bound({v[i],INF_N});
```
<br>
Estoy pidiendo que me encuentra el valor más cercano (mayor o superior) al primero y segundo. Entonces, cuando se encuentre el siguiente caso.<br><br>

```c++
[0] [1]
4-0 4-1
```

<br>
El iterador estará apuntando al primer par debido a que el valor más cercano de infinito negativo no es 1 sino que es 0, 0 se acerca más al negativo entonces me regresa ese par.<br><br>
Es por esto último que el algoritmo al tener pares en esa configuración me estará regresando un iterador que apunte al menor o al par igual que se está buscando.<br><br>
<hr>
Nota: INF_N puede ser -1e18 o simplemente 0.
<hr><br>

Para más información consultar:
<ol>
<li><a href="https://cplusplus.com/reference/set/set/" >set</a></li>
</ol>

</p>
