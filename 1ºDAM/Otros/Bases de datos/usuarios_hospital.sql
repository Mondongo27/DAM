-- Creamos el usuario admin_user 
-- El host '%' permite que se conecte desde cualquier dirección IP
CREATE USER 'admin_user'@'%' IDENTIFIED BY 'contraseña_segura_2026';

-- Refrescamos los privilegios para asegurar que el servidor reconoce al nuevo usuario
FLUSH PRIVILEGES;

-- Asignamos solo el permiso de lectura (SELECT) en la base de datos Hospital
GRANT SELECT ON hospital.* TO 'readonly_user'@'localhost';

-- Refrescamos para aplicar los cambios
FLUSH PRIVILEGES;