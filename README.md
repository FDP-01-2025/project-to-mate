[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - [Sivarmon]

## Descripción del Proyecto

Sivarmon es un juego de batallas por turnos al estilo RPG inspirado en la cultura salvadoreña. El jugador asume el rol de un entrenador que elige una bestia legendaria —un Sivarmon, criatura mística basada en elementos culturales y caliches locales— para enfrentarse a una serie de entrenadores en combates estratégicos.

El propósito del juego es derrotar al campeón de la liga y obtener el título de Maestro Sivarmon Salvadoreño. Las mecánicas permiten atacar, defenderse o usar objetos, y se requiere administrar los recursos sabiamente entre batallas consecutivas. Si el jugador descubre ciertas pistas ocultas, podrá desbloquear un jefe secreto y una bestia exclusiva.

La narrativa se desarrolla en un mundo dividido en cuatro repúblicas inspiradas en El Salvador, donde los Sivarmons tienen raíces míticas. Además del combate, el juego incorpora elementos de exploración narrativa y construcción de vínculos con las criaturas legendarias, haciendo del viaje una experiencia tanto táctica como emocional.

**Por ejemplo:**
Este proyecto consiste en un juego de batallas Al inicio de cada partida (run) se debe elegir a un Sivarmon inicial con el que se debe vencer a x cantidad entrenadores, al final se desarrolla una última batalla con el campeón de la liga, para ganar el título de “Maestro Sivarmon Salvadoreño”. A su vez, hay un jefe oculto del que se dan pistas durante la batalla con el campeón actual. Respecto a la aplicación de los temas vistos en clase, se utilizaran las siguientes estructuras:
**If/else, switch:** Estas estructuras nos servirán para poder controlar cada acción que tiene disponible el jugador y anidar cada movimiento de cada bestia de manera estructurada y eficaz. Donde los if y if/else nos servirán para poder comprobar en qué parte del menú estamos o validar que el jugador no trate de romper el juego, mientras que con switch podremos guardar de forma ordenada cada acción que tomaría el jugador.
**For, While/do While:** Con estas estructuras de bucle nos permitirá crear un flujo de turnos en los combates y permitir el eficaz funcionamiento de estos. Un bucle for se encargará de recorrer una lista de ataques disponibles y aplicar modificaciones a las estadísticas, mientras un while mantendrá la batalla activa mientras alguno de los combatientes tenga vida, por otro lado un do while garantiza que cada combate mínimo se ejecute una vez antes de verificar condiciones de victoria o derrota.
**Vectores, Arreglos/Arrays:** Estas estructuras de datos nos servirán para poder crear los sprites/diseños de las bestias en la terminal. Guardando dentro de un array o vector los caracteres ordenados que al ser mostrados en consola nos otorguen un sprite del diseño de la bestia.
**Funciones:** Estas nos permitirán estructurar y separar el código del juego en base a diferentes categorías ya sean funciones sobre el combate, funciones sobre diálogos o sprites de personajes o etc.
**Strings:** Con ellas podremos almacenar los diálogos del juego y información importante. Con cada string podremos guardar gran parte de la sección de diálogos del juego, permitiéndonos más orden en el código y a su vez podremos guardar información en este tipo de variable como el nombre del jugador, de las bestias o ataques.
**Clases/Uniones:** Con el uso de clases podemos asignar movimientos, estadísticas, características especiales y demás datos personalizables a cada especie de Sivarmon. Así podremos administrar diferentes atributos de manera estructurada que podrán brindar mayor profundidad a cada batalla, y habilidades o estrategias al jugador y su bestia.
Archivos en el Disco: Se utilizaran archivos para almacenar las diferentes sprites de Sivarmons que serán utilizados según las elecciones del jugador, estos están formados de caracteres ASCII que permitirán mostrar diversas criaturas con símbolos.
**Acceso secuencial/aleatorio de un archivo:** Tendremos almacenada la información de cada especie de Sivarmon en archivos externos que nos darán código más legible y la capacidad acceder a información según las necesidades del momento, sin sobrecargar la memoria del juego.
## Equipo

- **Nombre del equipo:** [To->mate]

### Integrantes del equipo

1. **Nombre completo:** [Diego Armando Mata Cortez]  
   **Carnet:** [00115025]

2. **Nombre completo:** [Manuel Tobar García]  
   **Carnet:** [00067423]

3. **Nombre completo:** [Andy Samuel Ochoa González]  
   **Carnet:** [00064825]

4. **Nombre completo:** [Claudia Sofía Pocasangre Peralta]  
   **Carnet:** [00005225]



## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [https://github.com/FDP-01-2025/project-to-mate.git]
