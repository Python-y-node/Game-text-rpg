# Comandos utiles de git y sus descripciones.

### 1) inicializar un repositorio git local.

``` 
git init
```
- Nota: Se le dice repositorio ( carpeta ) a el directorio al cual git rastrea los cambios.

### 2) Agregar archivos para que git los rastree.

```
git add <nombre del archivo> o git add . 
```
- Nota: El (.) es un caracter que le indica al comando de git que incluya lo que este en el repositorio inmediato, si ustedes ejecutaran: ```git add ..``` o ```git add ...```, git incluiria archivos de el repositorio anterior o el anterior a este.

### 3) Hacer commit o confirmar cambios en la version.

```
git commit -m "" // m indica la opcion de mensaje
```

- Nota: si quisiera hacer el git add y git commit de una vez podrias hacerlo con: 

```
git commit -am ""
```
 - solo recalcar que este comando funciona en archivos que anteriormente hayan sido incluidos en algun commit anterior, si lo haces y creaste archivos que no habian sido ratreados, git no los incluira.

### 4) ver commits anteriores

```
git log
```

### 5) Agregar un repositorio remoto
```
git remote add origin <url>
```

- ```origin``` es el nombre o alias que le ponemos al repositorio remoto, es una identificacion, por convencion se usa ese, pero pueden usar el que quieran media vez no afecte su flujo de trabajo y el de los demas.

### 6) Agregar cambios a un repositorio remoto.

- Nota: tomar en cuenta que antes de actualizar el repositorio remoto deben de hacer commit.

```
git push origin main
```

- ```main``` es el nombre de la rama a la que le estan empujando o mandando los cambios que han hecho, por ejemplo si su rama fuera diferente como: alejandra27 ustedes lo harian asi:

```
git push origin alejandra27
```

### 7) Ver los archivos que se van a rastrear antes del commit.

- Nota: este comando sirve tanto para antes, trasncurso y final de un commit, al final este nos dice el estado de nuestro repositorio.

```
git status
```

- Este es muy util ya que nos dice si el repositorio tiene trabajo no guardado, o si esta actualizado, etc.

### 8) Cambiar de rama.

```
git checkout <nombre de la rama>
```

- Este cambiara de rama si es que la rama existe.

### 9) Borrar alguna rama.

```
git branch -D <nombre de la rama>
```

- Esta borrara la rama solo si te encuentras en una rama diferente y si eres el creador de la misma, de lo contrario no lo hara.
