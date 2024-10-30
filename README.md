# Pasos para comenzar el trabajo en este repositorio.

* Nota: se tiene por entendido que ya se ha clonado este repositorio y se puede ejecutar el main.cpp.

 1- Al momento de haber clonado ejecuta el siguiente comando para 
   compilar el archivo de ejemplo.

```
 g++ main.cpp -o main 
```

y lo ejecutas de la siguiente forma:

``` ./main ``` o si estas en windows ``` .\main ```

2- Una vez que ya todo se pueda ejecutar se deben de cambiar de rama
   ya que la rama por defecto que se usa es la ```Main``` , entonces 
   para evitarse de problemas trabajaran en una rama propia y solo el 
   lider del equipo hara lo que es la union a la rama ```Main```

 ### Ver en que rama estoy:
 ```
  git branch
 ```

 ### Les aparecera un resultado en consola como este :

 ```
* main
 ```

### Luego crean su propia rama con el formato ```nombre/ultimos digitos de carnet```.

```
git branch alejandro37
```
### Aqui no termina, ahora deben de cambiarse de rama, dado que el cambio no se hace en automatico.

```
git checkout alejandro37
```

### una vez cambiado de rama y verificado que estan en su propia rama ya pueden comenzar a trabajar :D