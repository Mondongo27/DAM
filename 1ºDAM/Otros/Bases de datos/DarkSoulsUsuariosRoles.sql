USE DarkSouls;

-- CREACIÓN DE ROLES --
CREATE ROLE 'ds_admin';
CREATE ROLE 'ds_editor';
CREATE ROLE 'ds_jugador';

-- ASIGNACIÓN DE PRIVILEGIOS A ROLES --
-- Admin --
GRANT ALL PRIVILEGES ON DarkSouls.* TO 'ds_admin';

-- Editor --
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.ZONA TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.ENEMIGO TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.JEFE TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.ITEM TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.ARMAS TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.ARMADURA TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.CONSUMIBLES TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.MATERIAL TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.HOGUERAS TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.PNJS TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.ZONA_LLEVA_A TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.ZONA_PNJ TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.ZONA_ENEMIGO TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.ZONA_ITEM TO 'ds_editor';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.MEJORA TO 'ds_editor';

-- Jugador --
GRANT SELECT ON DarkSouls.ZONA TO 'ds_jugador';
GRANT SELECT ON DarkSouls.HOGUERAS TO 'ds_jugador';
GRANT SELECT ON DarkSouls.ENEMIGO TO 'ds_jugador';
GRANT SELECT ON DarkSouls.ARMAS TO 'ds_jugador';
GRANT SELECT, INSERT, UPDATE, DELETE ON DarkSouls.PERSONAJE TO 'ds_jugador';

-- CREACIÓN DE USUARIOS Y ASIGNACIÓN DE ROLES --
-- Usuario Admin
CREATE USER 'lord_gywn'@'localhost' IDENTIFIED BY 'EnlaceDelFuego2026!';
GRANT 'ds_admin' TO 'lord_gywn'@'localhost';

-- Usuario Editor
CREATE USER 'heraldo_datos'@'localhost' IDENTIFIED BY 'SolaireData99*';
GRANT 'ds_editor' TO 'heraldo_datos'@'localhost';

-- Usuario Jugador (Acceso desde cualquier IP para la App)
CREATE USER 'ashen_one'@'%' IDENTIFIED BY 'EstusRest123';
GRANT 'ds_jugador' TO 'ashen_one'@'%';

-- ACTIVACIÓN DE ROLES
-- En MySQL los roles no se activan por defecto al loguear a menos que se configure esta variable global:
SET GLOBAL activate_all_roles_on_login = ON;

FLUSH PRIVILEGES;