DROP DATABASE IF EXISTS DarkSouls;

CREATE DATABASE DarkSouls;

USE DarkSouls;

#Creacion de tablas
#TABLAS PRINCIPALES

CREATE TABLE ZONA (
    nombre VARCHAR(100) NOT NULL,
    juego VARCHAR(100) NOT NULL,
    descripcion TEXT,
    PRIMARY KEY(nombre,juego)
);

CREATE TABLE PNJS (
    codigo INT NOT NULL PRIMARY KEY,
    rol ENUM('Mercader','Herrero','Guía','Hostil','Aliado') NOT NULL,
    nombre VARCHAR(100) NOT NULL,
    nombre_completo VARCHAR(150),
    titulo VARCHAR(100),
    raza VARCHAR(50),
    dialogos TEXT
);

/* En el modelo relacional me pusiste en la correcion que la tabla personaje estaba duplicada (PNJS y PERSONAJE), no son los mejores nombres
   y por eso es un poco lioso pero PNJS serían los NPCs del juego, es decir personajes estáticos que te venden cosas o te hablan por ejemplo
   y PERSONAJE se refiere al personaje del jugador que guarda la zona de spawn que tiene en el juego. Tambien tiene un id porque el jugador puede
   tener varios personajes en un mismo juego.*/

CREATE TABLE CLASE_INIC (
    nombre VARCHAR(100) NOT NULL PRIMARY KEY,
    descripcion TEXT,
    fuerza_base INT UNSIGNED NOT NULL,
    destreza_base INT UNSIGNED NOT NULL,
    vigor_base INT UNSIGNED NOT NULL
);

CREATE TABLE PERSONAJE (
    id INT NOT NULL PRIMARY KEY,
    zona_nombre VARCHAR(100) NOT NULL,
    zona_juego VARCHAR(100) NOT NULL,
    nombre_clase VARCHAR(100) NOT NULL,
    fecha_creacion DATE NOT NULL,
    FOREIGN KEY (nombre_clase) 
		REFERENCES CLASE_INIC(nombre),
    FOREIGN KEY (zona_nombre, zona_juego) 
		REFERENCES ZONA(nombre, juego)
);

#ENEMIGOS

CREATE TABLE ENEMIGO (
    codigo INT NOT NULL PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    hp_base SMALLINT UNSIGNED NOT NULL,
    almas INT UNSIGNED NOT NULL
);

CREATE TABLE JEFE (
    codigo INT NOT NULL PRIMARY KEY,
    debilidades TEXT,
    alma_jefe BOOLEAN NOT NULL,
    FOREIGN KEY (codigo) REFERENCES ENEMIGO(codigo)
);

#ITEMS

CREATE TABLE ITEM (
    nombre VARCHAR(100) NOT NULL PRIMARY KEY
);

CREATE TABLE ARMAS (
    nombre VARCHAR(100) NOT NULL PRIMARY KEY,
    peso DECIMAL(5,2) UNSIGNED NOT NULL,
    tipo_dano ENUM('Físico','Fuego','Rayo','Magia','Oscuro') NOT NULL,
    durabilidad INT UNSIGNED NOT NULL,
    dano_total INT UNSIGNED NOT NULL,
    requisitos TEXT,
    FOREIGN KEY (nombre) REFERENCES ITEM(nombre)
);

CREATE TABLE ARMADURA (
    nombre VARCHAR(100) NOT NULL PRIMARY KEY,
    peso DECIMAL(5,2) UNSIGNED NOT NULL,
    ranura ENUM('Casco','Pecho','Guantes','Botas') NOT NULL,
    defensa_base INT NOT NULL,
    FOREIGN KEY (nombre) REFERENCES ITEM(nombre)
);

CREATE TABLE CONSUMIBLES (
    nombre VARCHAR(100) NOT NULL PRIMARY KEY,
    efecto TEXT NOT NULL,
    cant INT UNSIGNED NOT NULL,
    FOREIGN KEY (nombre) REFERENCES ITEM(nombre)
);

CREATE TABLE MATERIAL (
    nombre VARCHAR(100) NOT NULL PRIMARY KEY,
    descripcion TEXT NOT NULL,
    FOREIGN KEY (nombre) REFERENCES ITEM(nombre)
);

#HOGUERA

CREATE TABLE HOGUERAS (
    codigo INT NOT NULL PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    activa BOOLEAN NOT NULL,
    nivel INT UNSIGNED NOT NULL,
    zona_nombre VARCHAR(100) NOT NULL,
    zona_juego VARCHAR(100) NOT NULL,
    FOREIGN KEY (zona_nombre, zona_juego)
        REFERENCES ZONA(nombre, juego)
);

#RELACIONES

CREATE TABLE ZONA_LLEVA_A ( 				#REFLEXIVA
    zona_origen_nombre VARCHAR(100) NOT NULL,
    zona_origen_juego VARCHAR(100) NOT NULL,
    zona_destino_nombre VARCHAR(100) NOT NULL,
    zona_destino_juego VARCHAR(100) NOT NULL,
    direccion_acceso VARCHAR(100),
    PRIMARY KEY (
        zona_origen_nombre,
        zona_origen_juego,
        zona_destino_nombre,
        zona_destino_juego
    ),
    FOREIGN KEY (zona_origen_nombre, zona_origen_juego)
        REFERENCES ZONA(nombre, juego),
    FOREIGN KEY (zona_destino_nombre, zona_destino_juego)
        REFERENCES ZONA(nombre, juego)
);

CREATE TABLE ZONA_PNJ (
    zona_nombre VARCHAR(100) NOT NULL,
    zona_juego VARCHAR(100) NOT NULL,
    codigo INT NOT NULL,
    PRIMARY KEY (zona_nombre, zona_juego, codigo),
    FOREIGN KEY (zona_nombre, zona_juego)
        REFERENCES ZONA(nombre, juego),
    FOREIGN KEY (codigo)
        REFERENCES PNJS(codigo)
);

CREATE TABLE ZONA_ENEMIGO (
    zona_nombre VARCHAR(100) NOT NULL,
    zona_juego VARCHAR(100) NOT NULL,
    enemigo_codigo INT NOT NULL,
    PRIMARY KEY (zona_nombre,zona_juego, enemigo_codigo),
    FOREIGN KEY (zona_nombre, zona_juego) 
		REFERENCES ZONA(nombre, juego),
    FOREIGN KEY (enemigo_codigo) 
		REFERENCES ENEMIGO(codigo)
);

CREATE TABLE ZONA_ITEM (
    zona_nombre VARCHAR(100) NOT NULL,
    zona_juego VARCHAR(100) NOT NULL,
    item_nombre VARCHAR(100) NOT NULL,
    PRIMARY KEY (zona_nombre,zona_juego, item_nombre),
    FOREIGN KEY (zona_nombre,zona_juego) 
		REFERENCES ZONA(nombre,juego),
    FOREIGN KEY (item_nombre)
		REFERENCES ITEM(nombre)
);

CREATE TABLE MEJORA (
    arma_nombre VARCHAR(100) NOT NULL,
    material_nombre VARCHAR(100) NOT NULL,
    receta TEXT,
    cant INT,
    nivel INT,
    PRIMARY KEY (arma_nombre, material_nombre),
    FOREIGN KEY (arma_nombre) REFERENCES ARMAS(nombre),
    FOREIGN KEY (material_nombre) REFERENCES MATERIAL(nombre)
);

#Algunos ALTER-TABLE

ALTER TABLE PERSONAJE
ADD ultima_conexion DATETIME,
ADD hoguera_codigo INT UNIQUE,
ADD FOREIGN KEY (hoguera_codigo)
    REFERENCES HOGUERAS(codigo);

ALTER TABLE PNJS
ADD zona_nombre VARCHAR(100),
ADD zona_juego VARCHAR(100),
ADD FOREIGN KEY (zona_nombre, zona_juego)
    REFERENCES ZONA(nombre, juego);

#He añadido checks para comprobar la integridad de algunos datos
ALTER TABLE ARMAS
ADD CHECK (durabilidad >= 0);

ALTER TABLE HOGUERAS
ADD CHECK (nivel >= 0);

ALTER TABLE CONSUMIBLES
ADD CHECK (cant >= 0);
