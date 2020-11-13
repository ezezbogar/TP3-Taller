# TP3-Taller

## Ezequiel Zbogar - 102216

### Taller de Programación I

​	Diagrama de clases del server:

![Class Diagram](https://github.com/ezezbogar/TP3-Taller/blob/main/Images/Diagrama-De-Clases-2.png)

​	El server comienza haciendo un "bind" del socket aceptador seguido de un "listen" para luego con un "accept" dejarlo a la espera de conexiones entrantes. Una vez que aparece un cliente que desea conectarse, se lanza un thread el cual se encarga de procesar la petición del cliente y enviar una respuesta. El socket aceptador del cliente esta constantemente a la espera de conexiones entrantes y por cada una de ellas se lanza un thread que se encarga de procesar la peticion HTTP del cliente. Ademas, cada vez que llega un nuevo cliente, y por lo tanto se lanza un hilo de ejecución,  se recorre el vector de threads del servidor revisando cual es el estado de cada uno de los "Messenger", encargados de procesar los petitorios y enviar la correspondiente respuesta. En el caso de los que hayan finalizado se liberan los correspondientes recursos.

Al mismo tiempo, hay un thread que se lanza al inicio de la ejecucion del servidor que se encarga de leer la entrada estandar esperando el "caracter finalizador" con el se deja de aceptar clientes, se espera a que finalicen los que siguen en ejecucion para luego liberar sus recursos y dar por concluida la ejecucuon del server 

Ademas se imprime por pantalla la primer linea del petitorio que contiene informacion del metodo del petitorio

​	Diagrama de clases donde se hace foco en el proceso de resolucion de peticiones, donde PetitionSolver es la clase principal:

![Class Diagram](https://github.com/ezezbogar/TP3-Taller/blob/main/Images/Diagrama-De-Clases-1.png)

- Link al repositorio de GitHub: https://github.com/ezezbogar/TP3-Taller