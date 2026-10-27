-- Bindu Bhargava  09-12-19
-- BEFORE INSERT validation (rejects a bad price via SIGNAL) and AFTER UPDATE audit.
-- self-contained: builds its own small product table.

DROP TABLE IF EXISTS product_audit;
DROP TABLE IF EXISTS product;
DROP PROCEDURE IF EXISTS try_add_product;

CREATE TABLE product (
    pid   INT PRIMARY KEY,
    pname VARCHAR(30),
    price DECIMAL(10,2)
);

CREATE TABLE product_audit (
    audit_id   INT AUTO_INCREMENT PRIMARY KEY,
    pid        INT,
    old_price  DECIMAL(10,2),
    new_price  DECIMAL(10,2),
    changed_at DATETIME
);

DELIMITER //

CREATE TRIGGER trg_product_bi
BEFORE INSERT ON product
FOR EACH ROW
BEGIN
    IF NEW.price <= 0 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'price must be positive';
    END IF;
END //

-- only log rows whose price actually changed
CREATE TRIGGER trg_product_au
AFTER UPDATE ON product
FOR EACH ROW
BEGIN
    IF NEW.price <> OLD.price THEN
        INSERT INTO product_audit (pid, old_price, new_price, changed_at)
        VALUES (OLD.pid, OLD.price, NEW.price, NOW());
    END IF;
END //

DELIMITER ;

INSERT INTO product VALUES (1,'Notebook',45.00),(2,'Pen',10.00),(3,'Marker',25.00);

-- these fire the AFTER UPDATE audit trigger
UPDATE product SET price = 50.00 WHERE pid = 1;
UPDATE product SET price = 30.00 WHERE pid = 3;

SELECT pid, pname, price FROM product ORDER BY pid;
SELECT pid, old_price, new_price FROM product_audit ORDER BY audit_id;

-- a direct INSERT of price 0 raises ERROR 1644 and would abort the script,
-- so wrap it in a proc that traps the SIGNAL to show the rejection cleanly
DELIMITER //
CREATE PROCEDURE try_add_product(IN p_pid INT, IN p_name VARCHAR(30), IN p_price DECIMAL(10,2))
BEGIN
    DECLARE EXIT HANDLER FOR SQLSTATE '45000'
        SELECT CONCAT('rejected ', p_name, ' (price ', p_price, ')') AS result;
    INSERT INTO product VALUES (p_pid, p_name, p_price);
    SELECT CONCAT('inserted ', p_name) AS result;
END //
DELIMITER ;

CALL try_add_product(4, 'Eraser', 8.00);
CALL try_add_product(5, 'Freebie', 0);

SELECT pid, pname, price FROM product ORDER BY pid;
