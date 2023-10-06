# TFG. Francisco Javier Román Cortés. GIERM. ETSI US
## Video recopilatorio defensa:
https://youtu.be/BfQN7Q1lscs

## Video README:
https://github.com/Javirc99/TFG/assets/80626428/457b35c1-9f25-487b-9c81-325b2fe7b015

## Instrucciones básicas de uso/instalación
- Installar módulo pyZMQ:
````
pip install pyzmq
````
- Installar módulo numpy:
````
pip install numpy
````
- Installar módulo matplotlib:
````
pip install matplotlib
````
- Installar módulo OpenCV 4.7.0:
````
pip install opencv-python==4.7.0
````


- Descargar el paquete comprimido desde GitHub y descomprimirlo donde se desee
- Una vez extraído, ir al terminal y cambiar de directorio hasta la carpeta "CoppeliaSim_Edu_V4_5_1_rev2_Ubuntu20_04/". Hay dos formas: \
    -A traves del navegador de archivos, abrir dicha carpeta y pulsar click derecho y darle a "Abrir en Terminal" ó "Open in Terminal"  \
    -Manualmente usando el comando "cd" por ejemplo:
    ````
    cd ~Path_to_Downloads_or_where_the_zip_was_unfolded/CoppeliaSim_Edu_V4_5_1_rev2_Ubuntu20_04/
    ````
- Ejecutar la escena de CoppeliaSIM deseada, se tienen 2 fundamentalmente: \
    -Escena para ejemplos de objetivos con trayectorias elípticas tipo clustering:
    ````
    ./coppeliaSim.sh /home/javier/Desktop/TFG/MOT_4_cameras_movobjScript.ttt 
    ````
    -Escena para ejemplos de objetivos con trayectorias elípticas entrelazadas:
    ````
    ./coppeliaSim.sh /home/javier/Desktop/TFG/MOT_4_cameras_movTrayIndiv.ttt 
    ````
- En otra pestaña del terminal u otra ventana nueva.
    - Ir a la carpeta extraída:
    ````
    cd ~Path_to_Downloads_or_where_the_zip_was_unfolded/
    ````
- Ejecutar el launch deseado con primer argumento el modo de funcionamiento: "individual" o "clustering" y el segundo el número de cámaras orientables: "2" o "4", hay 2 opciones: \
    -Launch que incluye el movimiento de objetivos mediante Script, para escena "tipoCluster": 
    ````
    # Sólo una de las dos
    bash launch.sh individual n_cams_orientables
    bash launch.sh clustering n_cams_orientables 
    ````
    -Launch que incluye el movimiento de objetivos mediante Script, para escena "tipoCluster": 
    ````
    # Sólo una de las dos
    bash launchTrayIndiv.sh individual n_cams_orientables
    bash launchTrayIndiv.sh clustering n_cams_orientables 
    ````




## Enlaces de interés:
- Sensores CoppeliaSim: https://github.com/CoppeliaRobotics/models/tree/master/components/sensors
# Path creation:
- https://www.youtube.com/watch?v=kOjQRYmeX_o&ab_channel=NikolaiK.
- https://www.coppeliarobotics.com/helpFiles/en/paths.htm
# dynamic simulations: 
- https://www.coppeliarobotics.com/helpFiles/en/designingDynamicSimulations.htm
# Modos de operación de Cliente-Servidor CoppeliaSim, python:
- https://www.coppeliarobotics.com/helpFiles/en/remoteApiModusOperandi.htm
# Códigos de parámetros get-set de VisionSensor: 
- https://www.coppeliarobotics.com/helpFiles/en/objectParameterIDs.htm
# Guía de uso de la API de cliente remoto ZMQ (mejor que remoteAPI, ya que esta está deprecada):
- https://www.coppeliarobotics.com/helpFiles/en/zmqRemoteApiOverview.htm
