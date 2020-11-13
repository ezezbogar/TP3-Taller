# TP3: Taller-Pages

## Ezequiel Zbogar - 102216

### Taller de Programación I

​	Diagrama de clases del server:

![Class Diagram](https://github.com/ezezbogar/TP3-Taller/blob/main/Images/Diagrama-De-Clases-2.png)

​	El server comienza haciendo un "bind" del socket aceptador seguido de un "listen" para luego con un "accept" dejarlo a la espera de conexiones entrantes. Una vez que aparece un cliente que desea conectarse, se crea una instancia de clase Messenger, la cual hereda de Thread y se lanza un hilo el cual se encarga de procesar la petición del cliente y enviar la correspondiente respuesta. El socket aceptador del server esta constantemente a la espera de conexiones entrantes y por cada una de ellas se lanza un thread que se encarga de procesar la petición HTTP del cliente. Adems, cada vez que llega un nuevo cliente, y por lo tanto se lanza un hilo de ejecución,  se recorre el vector de Threads del servidor revisando cual es el estado de cada uno de ellos. En el caso de los threads que hayan finalizado su ejecución, se liberan los correspondientes recursos.

​	Este proceso se muestra en el siguiente diagrama:

![Class Diagram](https://github.com/ezezbogar/TP3-Taller/blob/main/Images/Diagrama-De-Clases-3.png)

​	Al mismo tiempo, hay un thread que se lanza al inicio de la ejecución del servidor que se encarga de leer la entrada estándar esperando el caracter finalizador el cual es la letra "q" cuando se lee dicho caracter se dejan de aceptar conexiones entrantes de clientes. Se espera a que finalicen los threads que siguen en ejecución para luego liberar sus recursos y dar por concluida la ejecución del server.

​	Ademas, con la llegada de un nuevo petitorio se imprime por pantalla la primer linea del mismo, que contiene información del método del petitorio.



​	Diagrama de clases donde se hace foco en el proceso de resolución de peticiones, donde PetitionSolver es la clase principal:

![Class Diagram](https://github.com/ezezbogar/TP3-Taller/blob/main/Images/Diagrama-De-Clases-1.png)

​	PetitionSolver inicializa su puntero a Petition con una instancia de alguna de sus clases hijas según el método del petitorio, luego aprovechando polimorfismo se llama al método "solve", el cual es implementado por todas sus clases hijas, que se encarga de leer el petitorio y guardar la correspondiente respuesta. 



- Link al repositorio de GitHub: https://github.com/ezezbogar/TP3-Taller