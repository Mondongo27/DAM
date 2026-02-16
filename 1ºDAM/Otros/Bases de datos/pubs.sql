DROP DATABASE IF EXISTS PUBS;
CREATE DATABASE PUBS;

USE PUBS;

CREATE TABLE Pub (
	cod_pub smallint auto_increment PRIMARY KEY NOT NULL,
    nombre varchar(50)	NOT NULL,
	licencia varchar(50) NOT NULL,
    domicilio varchar(50), 
    fecha_apertura DATETIME NOT NULL,
    horario ENUM ('HOR1','HOR2','HOR3'),
    cod_localidad smallint NOT NULL
);

CREATE TABLE Titular (
	dni_titular int PRIMARY KEY NOT NULL,
    nombre varchar(50) NOT NULL,
    domicilio varchar(50),
    cod_pub smallint NOT NULL,
    foreign key(cod_pub) references PUB(cod_pub)
);

CREATE TABLE Empleado (
	dni_empleado int PRIMARY KEY NOT NULL,
	nombre varchar(50) NOT NULL,
    domicilio varchar(50)
);

CREATE TABLE Existencias (
	cod_articulo smallint auto_increment PRIMARY KEY NOT NULL,
	nombre varchar(50) NOT NULL,
    cantidad int NOT NULL,
    precio double NOT NULL CHECK (precio > 0),
    cod_pub smallint NOT NULL,
    foreign key(cod_pub) references PUB(cod_pub)
);

CREATE TABLE Localidad (
	cod_localidad smallint auto_increment PRIMARY KEY NOT NULL,
    nombre varchar(50) NOT NULL
);

CREATE TABLE Pub_Empleado (
	cod_pub smallint,
	dni_empleado int,
    funcion ENUM('Camarero', 'Seguridad','Limpieza'),
    PRIMARY KEY (cod_pub, dni_empleado, funcion),
    foreign key(cod_pub) references PUB(cod_pub),
    foreign key(dni_empleado) references Empleado(dni_empleado)
);

