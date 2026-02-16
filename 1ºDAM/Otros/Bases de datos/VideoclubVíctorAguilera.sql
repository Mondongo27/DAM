DROP DATABASE IF EXISTS Videoclub;

CREATE DATABASE Videoclub;

USE Videoclub;

-- Creacion de tablas
CREATE TABLE DISTRIBUIDORA(
	id_distribuidora smallint PRIMARY KEY,
    nombre varchar(20) NOT NULL,
    pais varchar(20) NOT NULL,
	año_fundacion YEAR
);

CREATE TABLE PELICULAS(
	codigo_pelicula smallint PRIMARY KEY,
    titulo varchar(20),
    director varchar(20),
    genero ENUM ('Accion','Comedia','Drama','Terror','Documental'),
    id_distribuidora smallint,
    año_estreno YEAR,
    FOREIGN KEY (id_distribuidora) REFERENCES DISTRIBUIDORA(id_distribuidora)
		ON DELETE RESTRICT, -- valor por defecto
    CONSTRAINT REG_EXPR CHECK (codigo_pelicula REGEXP'^[A-Z]{3}-[0-9]{5}$')
);

CREATE TABLE COPIAS(
	id_copia smallint UNIQUE,
    codigo_pelicula smallint,
    fecha_adquisicion datetime, -- Fecha y hora de adquisicion
    precio decimal (4,2),
    estado ENUM ('Disponible','Alquilada','Deteriorada') DEFAULT 'Disponible',
    ubicacion varchar(20),
	PRIMARY KEY (id_copia,codigo_pelicula),
    FOREIGN KEY (codigo_pelicula) REFERENCES PELICULAS(codigo_pelicula)
		ON UPDATE CASCADE,
	CONSTRAINT chk_precio_max CHECK (Precio <= 50)
);

CREATE TABLE CLIENTES(
	id_cliente smallint PRIMARY KEY auto_increment,
    nombre varchar(20),
    apellidos varchar(20),
    DNI char(9),
    telefono char(9), -- Aunque sea numeros pongo char porque no se va a usar para calculos y ocupa menos.
    email varchar(30),
    fecha_nacimiento DATETIME,
    consentimiento_datos boolean DEFAULT false
);

CREATE TABLE ALQUILERES(
	id_alquiler smallint PRIMARY KEY,
    id_copia smallint,
    id_cliente smallint,
    fecha_alquiler DATETIME,
    fecha_devolucion DATETIME,
    FOREIGN KEY (id_copia) REFERENCES COPIAS(id_copia)
		ON DELETE SET NULL,
    FOREIGN KEY (id_cliente) REFERENCES CLIENTES(id_cliente)
		ON DELETE SET NULL
);

ALTER TABLE CLIENTES ADD activo boolean DEFAULT true;
ALTER TABLE CLIENTES RENAME COLUMN activo TO estatus_cliente;
ALTER TABLE ALQUILERES RENAME TO HISTORIAL_ALQUILERES;
ALTER TABLE CLIENTES ADD CONSTRAINT correo_unico UNIQUE (email);
ALTER TABLE COPIAS ADD CONSTRAINT chk_fecha CHECK(fecha_adquisicion <= "2000-1-1"); -- No se si eso es el siglo XXI
ALTER TABLE COPIAS DROP COLUMN ubicacion;