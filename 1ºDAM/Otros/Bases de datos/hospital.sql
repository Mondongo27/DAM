DROP DATABASE IF EXISTS Hospital;

CREATE DATABASE Hospital CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci;	# Permite emoticonos, y no tiene en cuenta tildes ni MAY/min al ordenar o comparar

USE Hospital;

/*
Esta era la estructura de tablas:

PLANTA (num_planta, cant_habitaciones, especialidad)
HABITACION (num_habitacion, cant_camas, observaciones, num_planta)
ENFERMO (DNI, cod_enfermo, nombre, direccion, telefono, fec_nac, edad)
DIAGNOSTICO (cod_diagnostico, fecha, informe, DNI_enfermo, DNI_medico)
MEDICO (DNI_medico, nombre, sueldo, direccion, telefono, especialidad)
AUXILIAR (DNI_auxiliar, nombre, sueldo, direccion, telefono, num_planta)
ALOJADO (num_habitacion, DNI_enfermo, fec_entrada, fec_salida)
*/

-- Tabla PLANTA
CREATE TABLE PLANTA (
    num_planta TINYINT PRIMARY KEY,	# Podría ser un CHAR, si queremos nombrar plantas como sótano o entreplantas (S1, E1...)
    cant_habitaciones TINYINT UNSIGNED NOT NULL,
    especialidad VARCHAR(100)
);

-- Tabla HABITACION
CREATE TABLE HABITACION (
    num_habitacion SMALLINT PRIMARY KEY,
    cant_camas TINYINT NOT NULL,
    observaciones TEXT,		# Permitimos un texto muy largo.
    num_planta TINYINT NOT NULL,
    FOREIGN KEY (num_planta) REFERENCES PLANTA(num_planta)
		ON UPDATE CASCADE 	# Cambios en nº planta se actualizan en habitaciones 
        ON DELETE CASCADE	# Borrando una planta, se eliminan las habitaciones
);

-- Tabla ENFERMO
CREATE TABLE ENFERMO (
    DNI CHAR(9) PRIMARY KEY,
    cod_enfermo CHAR(4) NOT NULL,
    nombre VARCHAR(50) NOT NULL,
    direccion VARCHAR(100),
    telefono CHAR(9),
    fec_nac DATE,
    edad TINYINT UNSIGNED
);

-- Tabla MEDICO
CREATE TABLE MEDICO (
    DNI_medico CHAR(9) PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    sueldo DECIMAL(10, 2),
    direccion VARCHAR(100),
    telefono CHAR(9),
    especialidad VARCHAR(100)
);

-- Tabla DIAGNOSTICO
CREATE TABLE DIAGNOSTICO (
    cod_diagnostico CHAR(4) PRIMARY KEY,
    fecha DATE NOT NULL,
    informe TEXT,		# El texto del informe puede ser muy largo.
    DNI_enfermo CHAR(9) NOT NULL,
    DNI_medico CHAR(9) NULL,
    FOREIGN KEY (DNI_enfermo) REFERENCES ENFERMO(DNI)
		ON DELETE CASCADE	/* Eliminando al paciente se eliminan sus diagnósticos */
        ON UPDATE CASCADE	/* Actualiza cambios en DNI */,
    FOREIGN KEY (DNI_medico) REFERENCES MEDICO(DNI_medico)
		ON DELETE SET NULL, 	# Eliminando un médico, sus diagnósticos van a NULL
    CHECK (cod_diagnostico REGEXP '^[A-Z][0-9]{3}$') -- Formato: Letra mayúscula seguida de tres números
);

-- Tabla AUXILIAR
CREATE TABLE AUXILIAR (
    DNI_auxiliar CHAR(9) PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    sueldo DECIMAL(10, 2),
    direccion VARCHAR(100),
    telefono CHAR(9),
    num_planta TINYINT,
    FOREIGN KEY (num_planta) REFERENCES PLANTA(num_planta)
		ON UPDATE CASCADE
        ON DELETE SET NULL
);

-- Tabla ALOJADO
CREATE TABLE ALOJADO (
    num_habitacion SMALLINT NOT NULL,
    DNI_enfermo CHAR(9) NOT NULL,
    fec_entrada DATE NOT NULL,
    fec_salida DATE NULL,		# fec_salida estará a NULL en pacientes aún alojados
    CHECK (fec_entrada <= fec_salida),
    PRIMARY KEY (num_habitacion, DNI_enfermo, fec_entrada),
    FOREIGN KEY (num_habitacion) REFERENCES HABITACION(num_habitacion)
		ON DELETE RESTRICT		# No se permiten cambios ni eliminaciones de nº habitación con datos de alojamiento	
        ON UPDATE RESTRICT,		# RESTRICT es el valor por defecto, luego estas restricciones no era necesario escribirlas.
    FOREIGN KEY (DNI_enfermo) REFERENCES ENFERMO(DNI)
		ON DELETE cascade
		ON UPDATE cascade
);


# Restricciones adicionales con ALTER :

--  Nueva columna email:
ALTER TABLE MEDICO ADD COLUMN email VARCHAR(100);
# ALTER TABLE MEDICO ADD email VARCHAR(100); 	# Sintaxis alternativa

-- Cambio tipo dato telefono:
ALTER TABLE ENFERMO MODIFY telefono VARCHAR(20);

-- Renombrar columna:
ALTER TABLE PLANTA RENAME COLUMN cant_habitaciones TO total_habitaciones;

-- Eliminar columna
ALTER TABLE HABITACION DROP COLUMN observaciones;

-- Nueva restriccion FK:
ALTER TABLE DIAGNOSTICO 
ADD CONSTRAINT fk_diagnostico_auxiliar FOREIGN KEY (DNI_medico) REFERENCES AUXILIAR(DNI_auxiliar);

-- Eliminación de restricción FK:
ALTER TABLE DIAGNOSTICO DROP CONSTRAINT fk_diagnostico_auxiliar;

-- Tfno único:
ALTER TABLE AUXILIAR
ADD CONSTRAINT unico_tf_auxiliar UNIQUE (telefono);

-- Nueva columna con default:
ALTER TABLE ENFERMO ADD activo TINYINT DEFAULT 1;

-- Eliminación clave primaria:
ALTER TABLE DIAGNOSTICO DROP PRIMARY KEY;

-- Nueva columna TURNO:
 ALTER TABLE AUXILIAR ADD turno ENUM('mañana', 'tarde', 'noche');

-- Cambio tipo dato edad:
ALTER TABLE ENFERMO MODIFY edad SMALLINT;
 
-- Nuevo nombre tabla:
ALTER TABLE ALOJADO RENAME TO ESTANCIAS;
