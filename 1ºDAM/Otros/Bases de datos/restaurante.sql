DROP DATABASE IF EXISTS Restaurante;

CREATE DATABASE IF NOT EXISTS Restaurante CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

USE Restaurante;

CREATE TABLE EMPLEADO(
	DNI char(9) PRIMARY KEY,
    NumSS char(15),
    Nombre varchar(50),
    Apellido1 varchar(50),
    Apellido2 varchar(50),
    TelFijo char(9),
    TelMovil char(9)
)CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

CREATE TABLE COCINERO(
	DNI_cocinero char(9) PRIMARY KEY,
    fecha_alta	date,
    FOREIGN KEY (DNI_cocinero) REFERENCES EMPLEADO(DNI)
		ON DELETE RESTRICT
        ON UPDATE CASCADE
)CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

CREATE TABLE PINCHE(
	DNI_pinche char(9) PRIMARY KEY,
    fecha_nac date,
    DNI_cocinero char(9),
    FOREIGN KEY (DNI_pinche) REFERENCES EMPLEADO(DNI)
		ON DELETE RESTRICT
        ON UPDATE CASCADE,
    FOREIGN KEY (DNI_cocinero) REFERENCES COCINERO(DNI_cocinero)
			ON DELETE RESTRICT
        ON UPDATE CASCADE
)CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

CREATE TABLE PLATO(
	Nombre varchar(100) PRIMARY KEY,
    Precio decimal(10,2),
    Tipo varchar(50),
    DNI_cocinero_prepara char(9),
    FOREIGN KEY (DNI_cocinero_prepara) REFERENCES COCINERO(DNI_cocinero)
		ON DELETE RESTRICT
        ON UPDATE CASCADE
)CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

CREATE TABLE ALMACEN(
	Num_almacen tinyint PRIMARY KEY,
    Nombre varchar(100),
    Descripcion text
)CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

CREATE TABLE ESTANTE(
	Letra char(1),
    Num_almacen tinyint,
    dimensiones varchar(50),
    PRIMARY KEY (Letra ,Num_almacen),
    FOREIGN KEY (Num_almacen) REFERENCES ALMACEN(Num_almacen)
		ON DELETE CASCADE
)CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

CREATE TABLE INGREDIENTE(
	Nombre varchar(100) PRIMARY KEY,
    Precio_kg decimal(10,2),
    cant_ingre_almacen decimal(10,2),
    letra_estante char(1),
    num_almacen tinyint,
    FOREIGN KEY (letra_estante,num_almacen) REFERENCES ESTANTE(Letra,Num_almacen)
)CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

CREATE TABLE LLEVA(
	Nom_plato varchar(100),
    Nom_ingred varchar(100),
    cant_ingre_plato decimal(10,2) ,
    PRIMARY KEY (Nom_plato, Nom_ingred),
    FOREIGN KEY (Nom_plato) REFERENCES PLATO(Nombre),
    FOREIGN KEY (Nom_ingred) REFERENCES INGREDIENTE(Nombre)
)CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

ALTER TABLE PLATO ADD CONSTRAINT chk_precio_max CHECK (Precio <= 100);
ALTER TABLE PINCHE ADD CONSTRAINT chk_fecha_nac CHECK(fecha_nac <= "2007-12-17");
ALTER TABLE ESTANTE ADD CONSTRAINT chk_letra_estante CHECK (Letra REGEXP '^[A-E]$');
ALTER TABLE EMPLEADO MODIFY COLUMN TelFijo CHAR(11), ADD CONSTRAINT chk_telfijo_formato CHECK (TelFijo REGEXP '^[0-9]{3}-[0-9]{3}-[0-9]{3}$');
ALTER TABLE EMPLEADO ADD CONSTRAINT chk_formato_dni CHECK(DNI REGEXP '^[0-9]{8}[A-Z]$');
ALTER TABLE EMPLEADO DROP COLUMN Apellido2;
ALTER TABLE EMPLEADO ADD curso_prl boolean;
ALTER TABLE PLATO ADD calorias int DEFAULT 0;
ALTER TABLE EMPLEADO RENAME COLUMN TelMovil TO TfnoMovil;
ALTER TABLE EMPLEADO ADD CONSTRAINT unico_nss UNIQUE (NumSS);
ALTER TABLE ALMACEN ADD CONSTRAINT unico_nombre UNIQUE (Nombre);
ALTER TABLE PLATO MODIFY COLUMN Tipo VARCHAR(50) NOT NULL DEFAULT 'General';
ALTER TABLE PINCHE RENAME TO AYUDANTE_COCINA;
CREATE INDEX idx_empleado_nombre ON EMPLEADO(Nombre);
ALTER TABLE PLATO ADD CONSTRAINT unq_nombre_tipo UNIQUE (Nombre, Tipo);

/* ON DELETE CASCADE -> Si borro el padre se borra el hijo || ON DELETE SET NULL Si borro el padre el hijo se queda y deja de depender del padre
CASCADE	Propaga el cambio o borrado
SET NULL	Pone la FK en NULL
RESTRICT	Bloquea la acción
ON UPDATE	Al modificar la PK
ON DELETE	Al eliminar la PK
----------------------------------
1. Tipos numéricos			SI NO TIENE SENTIDO VALOR NEGATIVO-> UNSIGNED, SI NO SE PUEDE REPETIR-> UNIQUE, PARA PONER VALOR PREDETERMINADO-> DEFAULT

TINYINT
Número entero muy pequeño.

SMALLINT
Número entero pequeño.

MEDIUMINT
Número entero de tamaño medio.

INT / INTEGER
Número entero estándar.

BIGINT
Número entero muy grande.

DECIMAL(p,s) / NUMERIC			p=total digitos, s=despues de la coma
Número decimal exacto, usado para dinero.

FLOAT
Número decimal aproximado.

DOUBLE
Número decimal de mayor precisión.

2. Tipos de texto (cadenas)

CHAR(n)
Texto de longitud fija.

VARCHAR(n)
Texto de longitud variable.

TINYTEXT
Texto corto.

TEXT
Texto de tamaño medio.

MEDIUMTEXT
Texto largo.

LONGTEXT
Texto muy largo.

3. Tipos de fecha y hora

DATE
Almacena una fecha (año, mes y día).

TIME
Almacena una hora.

DATETIME
Almacena fecha y hora.

TIMESTAMP
Fecha y hora con control de zona horaria.

YEAR
Almacena solo el año.

4. Tipo booleano

BOOLEAN / BOOL
Valor verdadero o falso (internamente es TINYINT(1)).

5. Tipos binarios

BINARY(n)
Datos binarios de longitud fija.

VARBINARY(n)
Datos binarios de longitud variable.

TINYBLOB
Datos binarios pequeños.

BLOB
Datos binarios normales (imágenes, archivos).

MEDIUMBLOB
Datos binarios grandes.

LONGBLOB
Datos binarios muy grandes.

6. Tipos de lista

ENUM
Permite un solo valor de una lista definida.

SET
Permite varios valores de una lista definida.

7. Tipo JSON

JSON
Almacena datos en formato JSON estructurado.

8. Tipos espaciales (geográficos)

GEOMETRY
Tipo base para datos espaciales.

POINT
Almacena un punto en el espacio.

LINESTRING
Almacena una línea.

POLYGON
Almacena un polígono.

MULTIPOINT
Conjunto de puntos.

MULTILINESTRING
Conjunto de líneas.

MULTIPOLYGON
Conjunto de polígonos.

GEOMETRYCOLLECTION
Colección de objetos espaciales.

*/